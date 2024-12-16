#pragma once
#include<d3d12.h>
#include<dxgi1_6.h>
#include<wrl.h>
#include<string>
#include<array>
#include<dxcapi.h>
#include<chrono>
#include<thread>
#include"externals/DirectXTex/DirectXTex.h"
class WinApp;

class DirectXCommon
{
public://メンバ変数
	//初期化
	void Initialize(WinApp* winApp);

	Microsoft::WRL::ComPtr<ID3D12Resource>CreateDepthStencilTextureResource(ID3D12Device* device, int32_t width, int32_t height);
	Microsoft::WRL::ComPtr<IDxcBlob> CompileShader(
		//CompilerするShaderファイルへのパス
		const std::wstring& filePath,
		//Compilerに使用するProfile
		const wchar_t* profile);

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> CreateDescriptorHeap(D3D12_DESCRIPTOR_HEAP_TYPE heapType, UINT numDescriptors, bool shaderVisible);

private://関数

	//デバイスの生成

	/// <summary>
	/// 
	/// </summary>
	void CreateDevice();

	//コマンド関連の生成
	void CreateCommand();

	//スワップチェーンの生成
	void CreateSwapChain();

	//深度バッファの生成
	void DepthCreateBufferView();

	//各種デスクリプタヒープの生成
	void CreateAllDescriptorHeap();

	//レンダーターゲットビューの初期化
	void RTVInitialize();

	//深度ステンシルビューの初期化
	void StencilInitialize();

	//フェンスの生成
	void CreateFence();

	//ビューポート矩形の初期化
	void ViewPortInitilize();

	//シザリング矩形の生成
	void CreateSizaling();

	//DCXコンパイラの生成
	void CreateDCX();

	//ImGuiの初期化
	void ImGuiInitilize();

	//SRV専用のデスクリプタハンドル取得関数を作成する。
	D3D12_CPU_DESCRIPTOR_HANDLE GetSRVCPUDescriptorHandle(uint32_t index);//SRV用
	D3D12_GPU_DESCRIPTOR_HANDLE GetSRVGPUDescriptorHandle(uint32_t index);

	D3D12_CPU_DESCRIPTOR_HANDLE GetRTVCPUDescriptorHandle(uint32_t index);//RTV用
	D3D12_GPU_DESCRIPTOR_HANDLE GetRTVGPUDescriptorHandle(uint32_t index);

	D3D12_CPU_DESCRIPTOR_HANDLE GetDSVCPUDescriptorHandle(uint32_t index);//DSV用
	D3D12_GPU_DESCRIPTOR_HANDLE GetDSVGPUDescriptorHandle(uint32_t index);
private://メンバ変数

	HRESULT hr;

	//WindosAPI
	WinApp* winApp_ = nullptr;

	//名前空間
	Microsoft::WRL::ComPtr<ID3D12Device> device = nullptr;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	//コマンド関連の初期化
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue = nullptr;
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator = nullptr;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList = nullptr;

	//スワップチェーンの生成
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain = nullptr;
	//DSV用のヒープでディスクリプタの数１。DSVはshader内で触るものではないので、ShaderVisibleはfalse
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvDescriptorHeap;/* = CreateDescriptorHeap(device.Get(), D3D12_DESCRIPTOR_HEAP_TYPE_DSV, 1, false)*/;

	//dxcCompilerを初期化
	Microsoft::WRL::ComPtr<IDxcUtils> dxcUtils = nullptr;
	Microsoft::WRL::ComPtr<IDxcCompiler3> dxCompiler = nullptr;

	//SwapChainからresourceを引っ張ってくる


	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvDescriptorHeap;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvDescriptorHeap;
	//Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvDescriptorHeap;

	Microsoft::WRL::ComPtr<IDxcIncludeHandler> includeHander = nullptr;

	//デスクリプタハンドル取得関数の移植
	static D3D12_CPU_DESCRIPTOR_HANDLE GetCPUDescriptorHandle(const Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>& descriptorHeap, uint32_t descriptorSize, uint32_t index);
	static D3D12_GPU_DESCRIPTOR_HANDLE GetGPUDescriptorHandle(const Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>& descriptorHeap, uint32_t descriptorSize, uint32_t index);

	uint32_t desriptorSizeSRV;
	uint32_t desriptorSizeRTV;
	uint32_t desriptorSizeDSV;

	//スワップチェーンリソース
	std::array<Microsoft::WRL::ComPtr<ID3D12Resource>, 2>swapChainResources;

	//初期値０でFenceを作る
	Microsoft::WRL::ComPtr<ID3D12Fence> fence = nullptr;

	//ビューポート
	D3D12_VIEWPORT viewport{};

	//シザー四角形
	D3D12_RECT scissorRect{};

	//スワップチェーンを生成する
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	//RTVの設定
	D3D12_RENDER_TARGET_VIEW_DESC rtvDesc{};
};