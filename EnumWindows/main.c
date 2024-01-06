#include <windows.h>
#include <stdio.h>
#include <psapi.h>

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM Lparam);
int getNameByPid(DWORD dwProcessId);
int SucessProcesEnum = 0;
int FailedProcesEnum = 0;

int main(void)
{
    if (!EnumWindows(EnumWindowsProc, 0))
    {
        printf("[-] Failed to enum Windows.\n%d", GetLastError());
        return EXIT_FAILURE;
    }
    printf("[+] Sucess to enum Windows.\n");

    printf("----------\n");
    printf("Sucess processes: %d\n", SucessProcesEnum);
    printf("Failed processes: %d\n", FailedProcesEnum);
    printf("Total: %d\n", (FailedProcesEnum + SucessProcesEnum));
    return EXIT_SUCCESS;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    DWORD dwProcessId = 0;
    GetWindowThreadProcessId(hwnd, &dwProcessId);
    if(!getNameByPid(dwProcessId))
    {
        FailedProcesEnum++;
    } else
    {
        SucessProcesEnum++;
    }
    return TRUE;
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