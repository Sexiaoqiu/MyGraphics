#include "MyWindow.h"
#include <iostream>
using namespace std;

LRESULT CALLBACK __WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	PAINTSTRUCT ps;
	HDC hdc;
	switch (msg) {
	case WM_QUIT:
		//MessageBox(NULL, "WM_CLOSE", "", NULL);
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		//MessageBox(NULL, "WM_CLOSE", "", NULL);
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
HWND MyCreateWindow(MyWindowSet ws)
{
	// �������Գ�ʼ��
	HINSTANCE hIns = GetModuleHandle(0);
	WNDCLASSEX wc;
	wc.cbSize = sizeof(wc);								// ����ṹ��С
	wc.style = CS_HREDRAW | CS_VREDRAW;					// ����ı��˿ͻ�����Ŀ�Ȼ�߶ȣ������»����������� 
	wc.cbClsExtra = 0;									// ���ڽṹ�ĸ����ֽ���
	wc.cbWndExtra = 0;									// ����ʵ���ĸ����ֽ���
	wc.hInstance = hIns;								// ��ģ���ʵ�����
	wc.hIcon = NULL;									// ͼ��ľ��
	wc.hIconSm = NULL;									// �ʹ����������Сͼ��ľ��
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;			// ������ˢ�ľ��
	wc.hCursor = NULL;									// ���ľ��
	wc.lpfnWndProc = __WndProc;							// ���ڴ�������ָ��
	wc.lpszMenuName = NULL;								// ָ��˵���ָ��
	wc.lpszClassName = "MyWindow";				    	// ָ�������Ƶ�ָ��

	// Ϊ����ע��һ��������
	if (!RegisterClassEx(&wc)) {
		cout << "RegisterClassEx error : " << GetLastError() << endl;
	}

	// ��������
	HWND hWnd = CreateWindowEx(
		WS_EX_TOPMOST,				// ������չ��ʽ����������
		"MyWindow",				    // ��������
		ws.title,					// ���ڱ���
		WS_OVERLAPPEDWINDOW,		// ������ʽ���ص�����
		ws.xInit,					// ���ڳ�ʼx����
		ws.yInit,					// ���ڳ�ʼy����
		ws.width,					// ���ڿ��
		ws.height,					// ���ڸ߶�
		0,							// �����ھ��
		0,							// �˵���� 
		hIns,						// �봰�ڹ�����ģ��ʵ���ľ��
		0							// �������ݸ�����WM_CREATE��Ϣ
	);
	return hWnd;
}