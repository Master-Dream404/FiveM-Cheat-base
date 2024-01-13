#include "pch.h"
#include "CPed.h"
#include <Windows.h>
void cheat()
{
    void* addr = (void*)((uintptr_t)GetModuleHandle(NULL) + 0x247F840);
    CWorld* World = (CWorld*)*(uint64_t*)(addr);
    while (!World->LocalPlayer())
    {
        Sleep(1);
    }
    MessageBoxA(0, "LocalPlayer was hooked", 0, 0);
    MessageBoxA(0, std::to_string(World->LocalPlayer()->GetHP()).c_str(), 0, 0);
    World->LocalPlayer()->SetHP(0);
    MessageBoxA(0, std::to_string(World->LocalPlayer()->GetHP()).c_str(), 0, 0);
}

DWORD WINAPI Chrat_org(LPVOID lr)
{
    cheat();
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, Chrat_org, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

