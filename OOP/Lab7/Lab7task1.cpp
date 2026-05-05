#include <iostream>
#include <thread>
#include <windows.h>

int main() {
    wchar_t cmd[] = L"mspaint.exe";

    STARTUPINFOW si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    bool success = CreateProcessW(
        NULL, 
        cmd, 
        NULL, 
        NULL, 
        FALSE, 
        NORMAL_PRIORITY_CLASS, 
        NULL, 
        NULL, 
        &si,
        &pi
    );

    if (success) {
        std::cout << "Paint launched successfully\n";

        Sleep(12000);
        TerminateProcess(pi.hProcess, 0);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        std::cout << "Paint closed successfully\n";
    } else {
        std::cerr << "Couldn't launch Paint. " << GetLastError() << std::endl;
    }

    return 0;
}