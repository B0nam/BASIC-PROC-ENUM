#include <windows.h>
#include <stdio.h>
#include <psapi.h>

int getNameByPid(DWORD dwProcessId);

int main(void)
{
    DWORD aProcesses[1024];
    DWORD cbNeeded;
    DWORD cProcesses;
    int i;
    int FailedProcesEnum = 0;
    int SucessProcesEnum = 0;

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
    {
        printf("[-] Failed to enum processes.\n%d", GetLastError());
        return EXIT_FAILURE;
    }
    printf("[+] Sucess to enum processes.\n");

    cProcesses = cbNeeded / sizeof(DWORD);

    for (i = 0; i < cProcesses;i++)
    {
        if (aProcesses[i] != 0)
        {
            if(!getNameByPid(aProcesses[i]))
            {
                SucessProcesEnum++;
            }
            FailedProcesEnum++;
        }
    }

    printf("----------\n");
    printf("Sucess processes: %d\n", SucessProcesEnum);
    printf("Faild processes: %d\n", FailedProcesEnum);
    printf("Total: %d\n", (FailedProcesEnum + SucessProcesEnum));
    return EXIT_SUCCESS;
}

int getNameByPid(DWORD dwProcessId)
{
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, dwProcessId);
    WCHAR szProcessPath[MAX_PATH];

    if (hProcess == NULL)
    {
        printf("[-] PID: %d\t-\tFailed to open process. Error: %d\n", dwProcessId, GetLastError());
        return EXIT_FAILURE;
    }

    if(!GetProcessImageFileNameW(hProcess, szProcessPath, MAX_PATH))
    {
		printf("[-] PID: %d\t-\tERROR: %d\n", dwProcessId, GetLastError());
        return EXIT_FAILURE;
    }
    printf("[+] PID: %d\t-\tPATH: %S\n", dwProcessId, szProcessPath);

    CloseHandle(hProcess);
    return EXIT_SUCCESS;
}
