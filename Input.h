#define DIRECTINPUT_VERSION  0x0800//DirectInputのバージョン指定
#pragma once
#include<Windows.h>
#include<wrl.h>
#include<dinput.h>
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
//入力
class Input
{
public://メンバ関数(宣言）
	//初期化
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	//更新
	void Update();

	//namespace省略
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

	bool PushKey(BYTE keyNumber);

	//全キーの状態
	BYTE key[256] = {};

	//前回の全キーの状態
	BYTE keyPre[256] = {};

	//トリガー判定処理
	bool TriggerKey(BYTE keyNumber);

private://メンバ変数
	//キーボードのデバイス
	ComPtr<IDirectInputDevice8>keyboard;

	//DirectInputのインスタンス	
	ComPtr<IDirectInput8>directInput;

};