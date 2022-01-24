#pragma once
#include <iostream>
#include <windows.h>
#include <thread>
bool loader_active = true;
#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")
#include <thread>
#include <random>

IDirect3DTexture9* NZlogo;
#include <iostream>
#include <windows.h>
#include <thread>
#include <random>

#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")
#include <D3dx9tex.h>
#pragma comment(lib, "D3dx9")
#include "others/ImGui/imgui.h"
#include "others/ImGui/imgui_impl_dx9.h"
#include "others/ImGui/imgui_impl_win32.h"
//

#include "termcolor.hpp"

#include "xorstr.hpp"
#include "cheat/functions.h"
//

static int width = 440;
static int height = 380;

HWND main_hwnd = nullptr;

LPDIRECT3DDEVICE9        g_pd3dDevice;
D3DPRESENT_PARAMETERS    g_d3dpp;
LPDIRECT3D9              g_pD3D;

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

bool CreateDeviceD3D(HWND hWnd)
{
	if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return false;

	// Create the D3DDevice
	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
	//g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
	if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
		return false;
	return true;
}

void CleanupDeviceD3D()
{
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
	if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

void ResetDevice()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
	if (hr == D3DERR_INVALIDCALL)
		IM_ASSERT(0);
	ImGui_ImplDX9_CreateDeviceObjects();
}

static std::string random_string(int length)
{
	std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(str.begin(), str.end(), generator);
	return str.substr(0, length);    // assumes 32 < number of characters in str         
}
static DWORDLONG random_number(DWORDLONG min, DWORDLONG max)
{
	srand(time(0));
	DWORDLONG out = min + rand() % (max - min + 1);
	return out;
}
static std::string randomclassname = random_string(random_number(4, 16));

int APIENTRY WindownsMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	AntiDebugger();
	AntiTİTLE();
	AntiDriver();
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, randomclassname.c_str(), NULL };
	RegisterClassEx(&wc);
	main_hwnd = CreateWindow(wc.lpszClassName, randomclassname.c_str(), WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

	if (!CreateDeviceD3D(main_hwnd)) {
		CleanupDeviceD3D();
		UnregisterClass(wc.lpszClassName, wc.hInstance);
		return 1;
	}
	ShowWindow(main_hwnd, SW_HIDE);
	UpdateWindow(main_hwnd);

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = nullptr;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	constexpr auto ColorFromBytes = [](uint8_t r, uint8_t g, uint8_t b)
	{
		return ImVec4((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, 1.0f);
	};

	D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, NZ, sizeof(NZ), 100, 100, D3DX_DEFAULT, D3DUSAGE_DYNAMIC, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &NZlogo);

#define HI(v)   ImVec4(255, 0, 0 , v) ////// üst kısım rengi
#define MED(v)  ImVec4(255, 0, 0 , v) ////// üst kısım rengi
#define LOW(v)  ImVec4(0.232f, 0.201f, 0.271f, v)
	// backgrounds (@todo: complete with BG_MED, BG_LOW)
#define BG(v)   ImVec4(0.200f, 0.220f, 0.270f, v)
// text
#define TEXT(v) ImVec4(0.860f, 0.930f, 0.890f, v)

	auto& style = ImGui::GetStyle();
	style.Colors[ImGuiCol_Text] = TEXT(0.78f);
	style.Colors[ImGuiCol_TextDisabled] = TEXT(0.28f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
	style.Colors[ImGuiCol_PopupBg] = BG(0.9f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = BG(1.00f);
	style.Colors[ImGuiCol_FrameBgHovered] = MED(0.78f);
	style.Colors[ImGuiCol_FrameBgActive] = MED(1.00f);
	style.Colors[ImGuiCol_TitleBg] = LOW(1.00f);
	style.Colors[ImGuiCol_TitleBgActive] = HI(1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = BG(0.75f);
	style.Colors[ImGuiCol_MenuBarBg] = BG(0.47f);
	style.Colors[ImGuiCol_ScrollbarBg] = BG(1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = MED(0.78f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = MED(1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); ///// checkbox tiki 
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
	style.Colors[ImGuiCol_ButtonHovered] = MED(0.86f);
	style.Colors[ImGuiCol_ButtonActive] = MED(1.00f);
	style.Colors[ImGuiCol_Header] = MED(0.76f);
	style.Colors[ImGuiCol_HeaderHovered] = MED(0.86f);
	style.Colors[ImGuiCol_HeaderActive] = HI(1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
	style.Colors[ImGuiCol_ResizeGripHovered] = MED(0.78f);
	style.Colors[ImGuiCol_ResizeGripActive] = MED(1.00f);
	style.Colors[ImGuiCol_PlotLines] = TEXT(0.63f);
	style.Colors[ImGuiCol_PlotLinesHovered] = MED(1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = TEXT(0.63f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = MED(1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = MED(0.43f);
	// [...]


	

	ImGui_ImplWin32_Init(main_hwnd);
	ImGui_ImplDX9_Init(g_pd3dDevice);

	DWORD window_flags = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar;
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect);
	auto x = float(screen_rect.right - width) / 2.f;
	auto y = float(screen_rect.bottom - height) / 2.f;

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		{
			ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
			ImGui::SetNextWindowSize(ImVec2(width, height));
			ImGui::SetNextWindowBgAlpha(1.0f);

		
			ImGui::Begin("NarkozProject", &loader_active, window_flags);
			{
				width = 315;
				height = 400;

				ImGui::SameLine(120);
				ImGui::Image(NZlogo, ImVec2(75, 65));

				


				ImGui::TextColored(ImColor(252, 246, 246), "_________________________________________________________________________");
				ImGui::Text(" ");
				ImGui::Text(" ");
				ImGui::SameLine(18);
				ImGui::Checkbox(" Admin Flag", &admin_flag_checkboxx);
				ImGui::SameLine(185);
				ImGui::Checkbox(" No Recoil", &no_recoil_checkbox);
				ImGui::Text("  ");
				ImGui::SameLine(18);
				ImGui::Checkbox(" No Spread", &nospread_checkbox);
				ImGui::SameLine(185);
				ImGui::Checkbox(" Gravity", &gravity_checkboxx);
				ImGui::Text("  ");
				ImGui::SameLine(18);
				ImGui::Checkbox(" Spiderman", &spiderman_checkboxx);
				ImGui::SameLine(185);
				ImGui::Checkbox(" Automatic", &full_automatic_checkbox);
				ImGui::Text("  ");
				ImGui::SameLine(18);
				ImGui::Checkbox(" Jump Shot", &jumpshot_checkbox);
				ImGui::SameLine(185);
				ImGui::Checkbox(" Super Eoka", &super_eoka_checkbox);
				ImGui::Text("  ");
				ImGui::SameLine(18);
				ImGui::Checkbox(" Fast Bow", &fast_bow_checkbox);
				ImGui::SameLine(185);
				ImGui::Checkbox(" Fat Bullet", &fat_bullet_checkbox);
				ImGui::Text("  ");
				ImGui::SameLine(18);
				ImGui::Checkbox(" Walk On Water", &walkonwater_checkboxx);
				ImGui::SameLine(185);
				ImGui::Checkbox(" Fast Compound ", &Fast_Compound_Checkbox);

				ImGui::Text("  ");
				ImGui::SameLine(18);
				ImGui::Checkbox(" Fov", &FOV_CHECK);
				ImGui::Text("  ");
				ImGui::SameLine(18);
				ImGui::SliderFloat("Fov Size", &eluzunlugu, 0, 150);
				ImGui::Text("  ");
				ImGui::SameLine(18);
				ImGui::Checkbox(" Always Day", &change_time_checkbox);
				ImGui::Text("  ");
				ImGui::SameLine(18);
				ImGui::SliderFloat("Time", &saatfloat, 0, 25);



				ImGui::TextColored(ImColor(252, 246, 246), "_________________________________________________________________________");

			


				ImGui::Text("  ");
				
				ImGui::EndChild();
				
			}
			ImGui::End();
		}
		ImGui::EndFrame();

		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
		if (g_pd3dDevice->BeginScene() >= 0)
		{
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			g_pd3dDevice->EndScene();
		}
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
		}
		HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
		if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
			ResetDevice();
		}
		if (!loader_active) {
			msg.message = WM_QUIT;
		}
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	CleanupDeviceD3D();
	DestroyWindow(main_hwnd);
	UnregisterClass(wc.lpszClassName, wc.hInstance);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;
	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			g_d3dpp.BackBufferWidth = LOWORD(lParam);
			g_d3dpp.BackBufferHeight = HIWORD(lParam);
			ResetDevice();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
			return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}