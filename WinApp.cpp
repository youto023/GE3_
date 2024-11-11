#include "WinApp.h"
#include<cmath>
#include "externals/imgui/imgui_impl_win32.cpp"

//ウィンドウプロシージャ
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

	if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam))
	{
		return true;
	}



	//メッセージに応じてゲーム固有の処理を行う
	switch (msg) {
		//ウィンドウが破棄された
	case WM_DESTROY:
		//osに対して、アプリの終了を伝える
		PostQuitMessage(0);
		return 0;

	}

	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);

}










void WinApp::Initialiize()
{
	CoInitializeEx(0, COINIT_MULTITHREADED);


	const int32_t kCLientWidth = 1280;
	const int32_t kCLientHeight = 720;

	RECT wrc = { 0,0,kCLientWidth,kCLientHeight };

	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);



	//出力ウィンドウへの文字出力
	OutputDebugStringA("Hello,DirectX!\n");

	WNDCLASS wc{};
	//ウィンドウプロシージャ
	wc.lpfnWndProc = WindowProc;

	//ウィンドウクラス名
	wc.lpszClassName = L"CG2WindowClass";

	//インスタンスハンドル
	wc.hInstance = GetModuleHandle(nullptr);

	//カーソル
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	//ウィンドウクラスを登録する
	RegisterClass(&wc);

	//ウィンドウの生成
	HWND hwnd = CreateWindow(
		wc.lpszClassName,
		L"CG2",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wrc.right - wrc.left,
		wrc.bottom - wrc.top,
		nullptr,
		nullptr,
		wc.hInstance,
		nullptr
	);

	//#ifdef DEBUG
	//	ID3D12Debug1* debugController = nullptr;
	//	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))) {
	//		//デバックレイヤーを有効化する
	//		debugController->EnableDebugLayer();
	//		//さらにGPU側でもチェックを行うようにする
	//		debugController->SetEnableGPUBasedValidation(TRUE);
	//	}
	//#endif // DEBUG

//#ifdef _DEBUG
//	ID3D12Debug1* debugController = nullptr;
//	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))) {
//		//デバックレイヤーを有効化する
//		debugController->EnableDebugLayer();
//		//さらにGPU側でもチェックを行うようにする
//		debugController->SetEnableGPUBasedValidation(TRUE);
//	}
//
//#endif

	ShowWindow(hwnd, SW_SHOW);



}

void WinApp::Update()
{
}