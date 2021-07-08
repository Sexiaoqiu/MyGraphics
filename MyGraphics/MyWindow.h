#include <Windows.h>

class  MyWindowSet
{
public:
	char *title;
	int xInit;
	int yInit;
	int width;
	int height;
private:

};

LRESULT CALLBACK __WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND MyCreateWindow(MyWindowSet ws);
