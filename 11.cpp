#include "01.h"
#include "11.h"
void 11() {
    std::wstring exe = L"C:\\Windows\\System32\\syscache32.exe";
    IWbemServices* p = NULL;
    IWbemLocator* l = NULL;
    HRESULT h = CoInitialize(NULL);
    if (h == S_OK) {
        h = CoCreateInstance(CLSID_WbemLocator, NULL, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID*)&l);
        if (h == S_OK) {
            h = l->ConnectServer(L"ROOT\\CIMV2", NULL, NULL, NULL, NULL, NULL, NULL, &p);
            if (h == S_OK) {
                std::wstring q = L"SELECT * FROM Win32_ProcessStartup WHERE Name='syscache32.exe'";
                IEnumWbemClassObject* e = NULL;
                p->ExecQuery(L"WQL", (BSTR)q.c_str(), WBEM_FLAG_FORWARD_ONLY, NULL, &e);
                if (e) e->Release();
                p->Release();
            }
            l->Release();
        }
        CoUninitialize();
    }
}
