#pragma once
#include"Windows.h"
#include <cstdint>
class WinApp
{
public://定数
	const int32_t kCLientWidth = 1280;
	const int32_t kCLientHeight = 720;
public://静的メンバ変数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	//初期化
public://メンバ変数
	void Initialiize();
	//更新
	void Update();
};