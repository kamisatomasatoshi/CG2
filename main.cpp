#include <Windows.h>
//ウィンドウプロシージャ
LRESULT WindowProcr(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
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
	OutputDebugStringA("Hello,DrectX!!/n");


	return 0;
}