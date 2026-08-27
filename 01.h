#pragma once
#include <windows.h>
#include <winhttp.h>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <queue>
#include <atomic>
#include <condition_variable>
#include <tlhelp32.h>
#include <shlwapi.h>
#include <psapi.h>
#include <wincrypt.h>
#include <shellapi.h>
#include <intrin.h>
#include <iphlpapi.h>
#include <netioapi.h>
#include <setupapi.h>
#include <devguid.h>
#include <cfgmgr32.h>
#include <virtdisk.h>
#include <aclapi.h>
#include <sddl.h>
#include <wbemidl.h>
#include <comdef.h>
#include <wscapi.h>
#include <wtsapi32.h>
#include <userenv.h>
#include <powrprof.h>
#include <winsvc.h>
#include <winevt.h>
#include <evntprov.h>
#include <evntrace.h>
#include <tdh.h>
#pragma comment(lib, "winhttp.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "crypt32.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "setupapi.lib")
#pragma comment(lib, "virtdisk.lib")
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "wscapi.lib")
#pragma comment(lib, "wtsapi32.lib")
#pragma comment(lib, "userenv.lib")
#pragma comment(lib, "powrprof.lib")
#pragma comment(lib, "wevtapi.lib")
#pragma comment(lib, "tdh.lib")
