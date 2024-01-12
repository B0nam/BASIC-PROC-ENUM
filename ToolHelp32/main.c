#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>

int enumSnapProcesses();
int SucessProcesEnum = 0;

int main(void)
{
    if (enumSnapProcesses() == EXIT_FAILURE)
    {
        printf("[-] Failed to enumerate processes.\n");
        return EXIT_FAILURE;
    }

    printf("[+] Successfully enumerated processes.\n");
    printf("----------\n");
    printf("Success processes: %d\n", SucessProcesEnum);
    printf("Total: %d\n", (SucessProcesEnum));
    return EXIT_SUCCESS;
}

int enumSnapProcesses()
{
    HANDLE hProcessSnap;
    PROCESSENTRY32W pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32W);

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        printf("[-] Failed to create snapshot. Error code: %d\n", GetLastError());
        return EXIT_FAILURE;
    }

    if (!Process32FirstW(hProcessSnap, &pe32))
    {
        printf("[-] Failed to retrieve process snapshot. Error code: %d\n", GetLastError());
        CloseHandle(hProcessSnap);
        return EXIT_FAILURE;
    }

    do
    {
        printf("[+] PID: %d\t-\tNAME: %S\n", pe32.th32ProcessID, pe32.szExeFile);
        SucessProcesEnum++;
    } while (Process32NextW(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
    return EXIT_SUCCESS;
}