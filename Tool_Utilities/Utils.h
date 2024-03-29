﻿/*
	░█████╗░██╗░░██╗███████╗██████╗░░█████╗░░░░██████╗░██╗░██████╗░██╗████████╗░█████╗░██╗░░░░░
	██╔══██╗╚██╗██╔╝██╔════╝██╔══██╗██╔══██╗░░░██╔══██╗██║██╔════╝░██║╚══██╔══╝██╔══██╗██║░░░░░
	███████║░╚███╔╝░█████╗░░██████╔╝███████║░░░██║░░██║██║██║░░██╗░██║░░░██║░░░███████║██║░░░░░
	██╔══██║░██╔██╗░██╔══╝░░██╔══██╗██╔══██║░░░██║░░██║██║██║░░╚██╗██║░░░██║░░░██╔══██║██║░░░░░
	██║░░██║██╔╝╚██╗███████╗██║░░██║██║░░██║██╗██████╔╝██║╚██████╔╝██║░░░██║░░░██║░░██║███████╗
	╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚═════╝░╚═╝░╚═════╝░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝

	-- Axera.Digital BO3 Zombie Tool ( Open Source )

	-- Coded by noodle@axera.digital & sonic@axera.digital

	-- Visit Us @https://axera.digital
*/

#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <vector>

HWND hWnd;
DWORD procID;
HANDLE hProc;

namespace Utils
{
	DWORD GetProcId(const char* procName);
	uintptr_t GetModuleBaseAddress(DWORD procId, const char* modName);
	uintptr_t PointerChain(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);
	void Patch(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProcess);
	void Nop(BYTE* dst, unsigned int size, HANDLE hProcess);
	void Write(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProcess);
	void Read(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProcess);
}