#include "pch.h"
int main(void)
{
    TCHAR szCommand[] = TEXT("Victim_jungTaeKwon");
    STARTUPINFO si = { sizeof(STARTUPINFO), };
    PROCESS_INFORMATION pi = { 0, };
    BOOL bRet = DetourCreateProcessWithDll(NULL, szCommand, NULL, NULL, TRUE
        , CREATE_DEFAULT_ERROR_MODE | CREATE_SUSPENDED, NULL, NULL
        , &si, &pi, "Hooking_jungTaeKwon.dll", NULL);
    ResumeThread(pi.hThread);
    WaitForSingleObject(pi.hProcess, INFINITE);
    return 0;
}