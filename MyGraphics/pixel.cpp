#include "MyWindow.h"
#include "Line.h"
using namespace std;



int main()
{
	MyPoint p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = 100;
	p2.y = 600;


	MyWindowSet ws;
	ws.title = "hello world";
	ws.xInit = 0;
	ws.yInit = 0;
	ws.width = 800;
	ws.height = 600;
	HWND hWnd1 = MyCreateWindow(ws);
	if (hWnd1 == 0) {
		cout << "CreateWindowEx error : " << GetLastError() << endl;
	}
	UpdateWindow(hWnd1);
	ShowWindow(hWnd1, SW_SHOW);

	HDC hdc = GetWindowDC(hWnd1);

	// 消息循环（没有会导致窗口卡死）
	MSG msg = { 0 };
	while (1) {
		// 从消息队列中删除一条消息
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			DispatchMessage(&msg);
		}
		if (msg.message== WM_QUIT)
		{
			cout << "ssss" << endl;
			break;
		}
		DrawLine(hdc, p2, p1);

	}


	cout << "finished." << endl;
	//getchar();

	return 0;
}


