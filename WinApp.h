#pragma once
#include"Windows.h"
class WinApp
{
public://定数
	static const int32_t kCLientWidth = 1280;
	static const int32_t kCLientHeight = 720;
public://静的メンバ変数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	//初期化
public://メンバ変数
	void Initialiize();
	//更新
	void Update();

	//getter
	HWND GetHwnd()const { return hwnd; }
	HINSTANCE GetHInstance() const { return wc.hInstance; }

private:
	//ウインドウハンドル
	HWND hwnd = nullptr;

	//ウインドウクラスの設定
	WNDCLASS wc{};
};