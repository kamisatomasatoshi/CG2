#include <Windows.h>
//�E�B���h�E�v���V�[�W��
LRESULT WindowProcr(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
//���b�Z�[�W�ɉ����ăQ�[���̌ŗL�������s��
{
	switch (msg) 
	{
		//�E�B���h�E���j�����ꂽ
		case WM_DESTROY:
			//OS�ɑ΂��ăA�v���̏I����`����
			PostQuitMessage(0);
			return 0;
	}

	//�W���̃��b�Z�[�W�������s��
	return DefWindowProc(hwnd, msg, wparam, lparam);

}

//Windows�A�v���ł̃G���g���[�|�C���g�imain�֐��j
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
//�R���\�[���ւ̕����o��
{
	OutputDebugStringA("Hello,DrectX!!/n");


	return 0;
}