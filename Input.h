#pragma once
#define DIRECTINPUT_VERTION 0x0800

#include<Windows.h>
#include<wrl.h>
#include<dinput.h>
#include"WinApp.h"

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")


//入力
class Input
{
public:
	//初期化
	void Initialize(WinApp* winApp);


	//更新
	void Update();

	//namespace省略
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;


	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);


private:

	//キーボードのデバイス
	ComPtr<IDirectInputDevice8>keyboard;

	//全キーの状態
	BYTE key[256] = {};

	BYTE keyPre[256] = {};

	//DirectInputのインスタンス
	ComPtr<IDirectInput8>directInput;

	//WindowsAPI
	WinApp* winApp = nullptr;

};

