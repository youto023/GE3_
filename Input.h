#define DIRECTINPUT_VERSION  0x0800//DirectInputのバージョン指定
#pragma once
#include<Windows.h>
#include<wrl.h>
#include<dinput.h>
//入力
class Input
{
public://メンバ関数
	//初期化
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	//更新
	void Update();

	//namespace省略
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

private://メンバ変数
	//キーボードのデバイス
	ComPtr<IDirectInputDevice8>keyboard;


};