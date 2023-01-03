#pragma once
#include <Windows.h>
#include <iostream>

struct offset
{
	static uint64_t GlowESP;
};

uint64_t offset::GlowESP = 0x1D3E951;//48 83 EC 38 66

//Overwatch.exe+
// 48 8B F9 81 FA 00 02 00 00
//
//Overwatch.exe + 1D485A1 - 48 8B F9 - mov rdi, rcx
//Overwatch.exe + 1D485A4 - 81 FA 00020000 - cmp edx, 00000200 { 512 }
//Overwatch.exe + 1D485AA - 0F85 8B000000 - jne Overwatch.exe + 1D4863B
//Overwatch.exe + 1D485B0 - 44 3B C2 - cmp r8d, edx
//Overwatch.exe + 1D485B3 - 0F84 11020000 - je Overwatch.exe + 1D487CA
//Overwatch.exe + 1D485B9 - 48 8B 41 08 - mov rax, [rcx + 08]
//Overwatch.exe + 1D485BD - 4C 8D 4C 24 48 - lea r9, [rsp + 48]
//Overwatch.exe + 1D485C2 - 89 91 E0030000 - mov[rcx + 000003E0], edx
//Overwatch.exe + 1D485C8 - 4C 8D 44 24 50 - lea r8, [rsp + 50]
//Overwatch.exe + 1D485CD - 48 89 44 24 58 - mov[rsp + 58], rax
//Overwatch.exe + 1D485D2 - 48 8D 54 24 28 - lea rdx, [rsp + 28]
//Overwatch.exe + 1D485D7 - 48 8B 44 24 58 - mov rax, [rsp + 58]
//Overwatch.exe + 1D485DC - 48 B9 CE913B3E91601C40 - mov rcx, 401C60913E3B91CE{ 0.18 }
//Overwatch.exe + 1D485E6 - 48 8B 44 24 58 - mov rax, [rsp + 58]
//Overwatch.exe + 1D485EB - 48 2B C1 - sub rax, rcx
//Overwatch.exe + 1D485EE - 48 89 44 24 58 - mov[rsp + 58], rax
//Overwatch.exe + 1D485F3 - 48 8B 4C 24 58 - mov rcx, [rsp + 58]
//Overwatch.exe + 1D485F8 - 48 8B 44 24 58 - mov rax, [rsp + 58]
//Overwatch.exe + 1D485FD - 48 C1 E9 20 - shr rcx, 20 { 32 }
//Overwatch.exe + 1D48601 - 48 C1 E0 20 - shl rax, 20 { 32 }
//Overwatch.exe + 1D48605 - 48 0B C1 - or rax, rcx
//Overwatch.exe + 1D48608 - 48 8D 4C 24 20 - lea rcx, [rsp + 20]
//Overwatch.exe + 1D4860D - 48 89 44 24 58 - mov[rsp + 58], rax
//Overwatch.exe + 1D48612 - 48 8B 5C 24 58 - mov rbx, [rsp + 58]
//Overwatch.exe + 1D48617 - E8 04670100 - call Overwatch.exe + 1D5ED20
//Overwatch.exe + 1D4861C - 44 8B 44 24 48 - mov r8d, [rsp + 48]
//Overwatch.exe + 1D48621 - 4A 8B 94 C3 F0000000 - mov rdx, [rbx + r8 * 8 + 000000F0]
//Overwatch.exe + 1D48629 - 4C 8B CA - mov r9, rdx
//Overwatch.exe + 1D4862C - 4C 23 4C 24 20 - and r9, [rsp + 20]
//Overwatch.exe + 1D48631 - 48 23 54 24 28 - and rdx, [rsp + 28]
//Overwatch.exe + 1D48636 - E9 98000000 - jmp Overwatch.exe + 1D486D3
//Overwatch.exe + 1D4863B - 41 8B C0 - mov eax, r8d
//Overwatch.exe + 1D4863E - 25 C1272000 - and eax, 002027C1{ 2107329 }

