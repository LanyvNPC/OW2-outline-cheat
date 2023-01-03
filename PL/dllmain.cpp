#pragma once
#pragma comment(lib, "dwmapi.lib")
#include <fstream>
#include <Windows.h>
#include <iostream>
#include <thread>
#include <TlHelp32.h>
#include <vector>
#include <ShObjIdl.h>
#include "GetModule.h"
#include "OffsetAddress.h"
#include "USEVEH.h"



LONG WINAPI ExceptionHandler(EXCEPTION_POINTERS* e)
{
		if (e->ExceptionRecord->ExceptionAddress == (void*)(MODULE->BaseAddress + offset::GlowESP))
		{
			e->ContextRecord->Rdx = 0xC1;
			e->ContextRecord->Rdi = e->ContextRecord->Rcx;   // 이부분 수정  Overwatch.exe+1D485A1 - 48 8B F9              - mov rdi,rcx
			e->ContextRecord->Rip = (uint64_t)(MODULE->BaseAddress + offset::GlowESP + 0x3);
			return EXCEPTION_CONTINUE_EXECUTION;
		}
	return EXCEPTION_CONTINUE_SEARCH;

}
void USEVEHIT()
{
	HANDLE hMainThread = USEVEH->GetMainThread();
	srand(GetTickCount());
	PVOID pHandler = AddVectoredExceptionHandler(1, ExceptionHandler);
	CONTEXT c{};
	c.ContextFlags = CONTEXT_DEBUG_REGISTERS;
	SuspendThread(hMainThread);
	c.Dr0 = MODULE->BaseAddress + offset::GlowESP;
	c.Dr7 = (1 << 0) | (1 << 2) | (1 << 4) | (1 << 6);
	SetThreadContext(hMainThread, &c);
	ResumeThread(hMainThread);
}





DWORD WINAPI MainProject(LPVOID lpParam)
{

	MODULE->GetBaseAddress();
	USEVEHIT();
	while (true)
	{

	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, 0, MainProject, lpReserved, 0, NULL);
	}
	return TRUE;
}