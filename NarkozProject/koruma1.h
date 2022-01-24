#pragma once

#pragma once

#include <iostream>
#include <thread>
#include <iostream>
#include <windows.h>
#include <thread>
#include <assert.h>
#pragma warning(disable : 4005)
#pragma warning(disable : 4244)
#pragma warning(disable : 6001)
#pragma warning(disable : 6031)
#pragma warning(disable : 6387)
#pragma warning(disable : 26495)
#pragma warning(disable : 26812)
#include <tlhelp32.h>
#include <iostream>
#include <excpt.h>
#include <signal.h>
#include <shlwapi.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <ostream>
#include <windows.h>
#include <assert.h>
#include <tlhelp32.h>
#include <iostream>
#include <excpt.h>
#include <signal.h>
#include <shlwapi.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include <Urlmon.h>
#include <iostream>
#include <windows.h>
#include <thread>
#include <windows.h>
#include <iostream>
#include <thread>
#define print(c, b, ...) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); printf(b); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  printf(__VA_ARGS__)
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <WinUser.h>
#include <thread>
#include <chrono>
#include <string>
#include <functional>
#include <vector>
#include <array>
#include <iterator>
#include <TlHelp32.h>
#include <tchar.h>
#include <dinput.h>
#include <CommCtrl.h>
#include <random>
#include <algorithm>
#include <cctype>
#include <atomic>
#include <mutex>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <cmath>
#include <string>




#pragma comment(lib, "user32.lib")


#include <tchar.h>
#include <random>
#pragma comment(lib, "urlmon.lib")
#include <urlmon.h>
#include <sstream>
#include <Lmcons.h>
#include <string>
#include <random>
#include <ctime>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <chrono>
#pragma comment(lib, "user32.lib")
#include <stdlib.h>
#include "koruma2.h"
#include "xorstr.hpp"
void error(std::string msg);
void DebugChecker()
{
	if (IsDebuggerPresent())
	{
		exit(1);
	}
}

bool IsProcessRun(const char* const processName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &pe);

	while (1) {
		if (strcmp(pe.szExeFile, processName) == 0) return true;
		if (!Process32Next(hSnapshot, &pe)) return false;
	}
}

void error(std::string msg)
{
	MessageBox(0, XorStr("Debugger Dedected").c_str(), "NZ", MB_ICONERROR);
	exit(1);

}
void AntiDebugger()
{

	if (IsProcessRun(XorStr("ollydbg.exe").c_str()) || IsProcessRun(XorStr("ida64.exe").c_str()) || IsProcessRun(XorStr("x64dbg.exe").c_str()) || IsProcessRun(XorStr("x32dbg.exe").c_str()) || IsProcessRun(XorStr("Scylla_x64.exe").c_str()) || IsProcessRun(XorStr("Scylla_x86.exe").c_str()) || IsProcessRun(XorStr("HxD.exe").c_str()) || IsProcessRun(XorStr("dnSpy.exe").c_str()) || IsProcessRun(XorStr("patch.exe").c_str()) || IsProcessRun(XorStr("ksdumper.exe").c_str()) || IsProcessRun(XorStr("Wireshark.exe").c_str()) ||
		IsProcessRun(XorStr("Fiddler Everywhere.exe").c_str()) || IsProcessRun(XorStr("HTTPDebuggerSvc.exe").c_str()) || IsProcessRun(XorStr("dumpcap.exe").c_str()) || IsProcessRun(XorStr("ProcessHacker.exe").c_str()) || IsProcessRun(XorStr("Dumper.exe").c_str()) || IsProcessRun(XorStr("ida32.exe").c_str())
		|| IsProcessRun(XorStr("HTTPDebuggerUI.exe").c_str()) || 


	   /// NEW


	     IsProcessRun(XorStr("KsDumperClient.exe").c_str()) ||
		 IsProcessRun(XorStr("Everything.exe").c_str()) ||
	  	 IsProcessRun(XorStr("ProcessHacker 2.exe").c_str()) ||
	     IsProcessRun(XorStr("FolderChangesView.exe").c_str()) ||
		 IsProcessRun(XorStr("procmon.exe").c_str()) ||
		 IsProcessRun(XorStr("idaq.exe").c_str()) ||
	   	 IsProcessRun(XorStr("idaq64.exe").c_str()) ||
	     IsProcessRun(XorStr("Fiddler.exe").c_str()) ||
		 IsProcessRun(XorStr("Xenos64.exe").c_str()) ||
		 IsProcessRun(XorStr("Cheat Engine.exe").c_str()) ||
		 IsProcessRun(XorStr("Cheat HTTP Debugger Windows Service (32 bit.exe").c_str()) ||
		 IsProcessRun(XorStr("KsDumper.exe").c_str()) ||
		 IsProcessRun(XorStr("x64dbg.exe").c_str()) ||

		/// NEW


		IsProcessRun(XorStr("windowrenamer.exe").c_str())) 
     	{
	  	 error(XorStr(" "));
	}

}


void AntiTÝTLE() {
    HWND slm1 = FindWindowW(XorStr(L"Qt5QWindowIcon").c_str(), 0);  // Class ID denetleyici 
    if (slm1)
    {
        MessageBoxA(NULL, XorStr("Debugger Detected").c_str(), XorStr("NarkozProject").c_str(), MB_ICONERROR);
		error(XorStr(" "));
    }
    HWND slm2 = FindWindow(NULL, (XorStr("OllyDbg").c_str())); // Title Denetleyici
    if (slm2)
    {
        MessageBoxA(NULL, XorStr("Debugger Detected").c_str(), XorStr("NarkozProject").c_str(), MB_ICONERROR);
		error(XorStr(" "));
    }
    HWND slm3 = FindWindowW(XorStr(L"XTPMainFrame").c_str(), 0); // Class ID denetleyici 
    if (slm3)
    {
        MessageBoxA(NULL, XorStr("Debugger Detected").c_str(), XorStr("NarkozProject").c_str(), MB_ICONERROR);
		error(XorStr(" "));
    }
    HWND slm4 = FindWindow(NULL, (XorStr("HTTP Debugger").c_str())); // Title Denetleyici
    if (slm4)
    {
        MessageBoxA(NULL, XorStr("Debugger Detected").c_str(), XorStr("NarkozProject").c_str(), MB_ICONERROR);
		error(XorStr(" "));
    }
    HWND slm5 = FindWindowW(XorStr(L"XTPMainFrame").c_str(), 0); // Class ID denetleyici 
    if (slm5)
    {
        MessageBoxA(NULL, XorStr("Debugger Detected").c_str(), XorStr("NarkozProject").c_str(), MB_ICONERROR);
		error(XorStr(" "));
    }
	HWND slm6 = FindWindowW(XorStr(L"x64dbg").c_str(), 0); // Class ID denetleyici 
	if (slm6)
	{
		MessageBoxA(NULL, XorStr("Debugger Detected").c_str(), XorStr("NarkozProject").c_str(), MB_ICONERROR);
		error(XorStr(" "));
	}
	HWND slm7 = FindWindowW(XorStr(L"Everything").c_str(), 0); // Class ID denetleyici 
	if (slm7)
	{
		MessageBoxA(NULL, XorStr("Debugger Detected").c_str(), XorStr("NarkozProject").c_str(), MB_ICONERROR);
		error(XorStr(" "));
	}

    Sleep(1000);
}

void AntiDriver()
{
	const TCHAR* devices[] = {
_T("\\\\.\\NiGgEr"),
_T("\\\\.\\KsDumper")
	};

	WORD iLength = sizeof(devices) / sizeof(devices[0]);
	for (int i = 0; i < iLength; i++)
	{
		HANDLE hFile = CreateFile(devices[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		TCHAR msg[256] = _T("");
		if (hFile != INVALID_HANDLE_VALUE) {
			error(XorStr(" "));
		}
		else
		{

		}
	}
}



BOOL IsAdministrator(VOID)
{
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	PSID AdministratorsGroup;

	if (!AllocateAndInitializeSid(&NtAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID,
		DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &AdministratorsGroup))
	{
		return FALSE;
	}

	BOOL IsInAdminGroup = FALSE;

	if (!CheckTokenMembership(NULL, AdministratorsGroup, &IsInAdminGroup))
	{
		IsInAdminGroup = FALSE;
	}

	FreeSid(AdministratorsGroup);
	return IsInAdminGroup;
}
