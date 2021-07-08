#include "Line.h"
using namespace std;
void DrawLine(HDC hdc, const MyPoint p_start, const MyPoint p_end)
{
	//Bresenham算法
	unsigned int x0, x1, y0, y1;
	x0 = p_start.x;
	y0 = p_start.y;
	x1 = p_end.x;
	y1 = p_end.y;
	//这里可以加入越界判断
	bool flip = false;
	if (abs((int)(y1 - y0)) > abs((int)(x1 - x0))) {
		swap(x0, y0);
		swap(x1, y1);
		flip = true;
	}
	if (x0 > x1) {
		swap(x0, x1);
		swap(y0, y1);
	}
	int dy = y1 - y0;
	int dx = x1 - x0;
	int y = y0;
	int error = 0;
	int derror = 2 * abs((int)dy);
	for (int x = x0; x <= x1; x++) {
		flip ? SetPixel(hdc, y, x, RGB(255, 0, 0)) : SetPixel(hdc, x, y, RGB(255, 0, 0));
		error += derror;
		if (error > dx) {
			error -= 2 * dx;
			y += (y1 > y0 ? 1 : -1);
		}
	}
}