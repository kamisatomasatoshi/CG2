#include <Windows.h>


//ウィンドウ設定

//ウィンドウサイズ

//const int WINDOW_WINDTH = 1280;//横幅
//const int WINDOW_HEIGHT = 720;//縦幅
//
////ウィンドウクラスの設定
//
//WNDCLASSEX w{};
//w.hInstance = GetModuleHandle(nullptr);		
//w.cbSize = sizeof(WNDCLASSEX)				//ウィンドウプロシージャを設定
//w.lpfnWndProc = (WNDPROC)WindowProc;		//ウィンドウクラス名
//w.lpszClassName = L"DirectXGame";			//ウィンドウハンドル
//w.hCursor = LoadCursor(NULL, IDC = ARROW);	//カーソル指定
//
////ウィンドウクラスをOPに登録する
//RegisterClassEx(&w);
////ウィンドウサイズ｛X座標、Y座標、横幅、縦幅｝
//RECT wrc = { 0,0,WINDOW_WINDTH,WINDOW_HEIGHT };
////自動でサイズを補正する
//AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);






//ウィンドウプロシージャ
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
//メッセージに応じてゲームの固有処理を行う
{
	switch (msg)
	{
		//ウィンドウが破棄された
	case WM_DESTROY:
		//OSに対してアプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}

	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);

}

//Windowsアプリでのエントリーポイント（main関数）
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
//コンソールへの文字出力
{
	//OutputDebugStringA("Hello,DrectX!!/n");
	//ウィンドウサイズ

	const int WINDOW_WINDTH = 1280;//横幅
	const int WINDOW_HEIGHT = 720;//縦幅

	//ウィンドウクラスの設定

	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;		//ウィンドウプロシージャを設定
	w.lpszClassName = L"DirectXGame";			//ウィンドウクラス名
	w.hInstance = GetModuleHandle(nullptr);		//ウィンドウハンドル
	w.hCursor = LoadCursor(NULL, IDC_ARROW);	//カーソル指定

	//ウィンドウクラスをOPに登録する
	RegisterClassEx(&w);
	//ウィンドウサイズ｛X座標、Y座標、横幅、縦幅｝
	RECT wrc = { 0,0,WINDOW_WINDTH,WINDOW_HEIGHT };
	//自動でサイズを補正する
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);


	//ウィンドウオブジェクトの生成
	HWND hwnd = CreateWindow(w.lpszClassName,	//クラス名
		L"DirectXGame",							//タイトルバー
		WS_OVERLAPPEDWINDOW,					//標準的なウィンドウスタイル
		CW_USEDEFAULT,							//表示X座標（OSに任せる）
		CW_USEDEFAULT,							//表示Y座標（OSに任せる）
		wrc.right - wrc.left,					//ウィンドウ横幅
		wrc.bottom - wrc.top,					//ウィンドウ縦幅
		nullptr,								//親ウィンドウハンドル
		nullptr,								//メニューハンドル
		w.hInstance,							//呼び出しアプリケーションハンドル
		nullptr);								//オプション

	ShowWindow(hwnd, SW_SHOW);


	MSG msg{};//メッセージ

	//


	//


	//ゲームループ
	while (true)
	{
		//メッセージがある？
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);//キー入力メッセージの処理
			DispatchMessage(&msg);//プロシージャにメッセージを送る
		}

		//×ボタンで終了のメッセージが来たらゲームループを抜ける
		if (msg.message == WM_QUIT)
		{
			break;
		}

		//DrectX毎フレーム処理開始


		//DrectX毎フレーム処理終了


	}

	//ウィンドウクラスを登録解除
	UnregisterClass(w.lpszClassName, w.hInstance);
	return 0;
}