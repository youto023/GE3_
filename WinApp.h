#pragma once
#include"Windows.h"
#include <cstdint>
class WinApp
{


public://静的メンバ変数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	//定数
	static const int32_t kCLientWidth = 1280;
	static const int32_t kCLientHeight = 720;

	//初期化
public://メンバ変数
	void Initialiize();
	//更新
	void Update();

	//終了
	void Finalize();

	//getter
	HWND GetHwnd()const { return hwnd; }
	HINSTANCE GetHInstance() const { return wc.hInstance; }

	//メッセージの処理
	bool ProcessMessage();

private://関数
	//ウインドウハンドル
	HWND hwnd = nullptr;

	//ウインドウクラスの設定
	WNDCLASS wc{};
};