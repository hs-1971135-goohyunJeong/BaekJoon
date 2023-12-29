#include <iostream>

using namespace std;

int getDistance(int x, int y, int w, int h) {
	int dx = x;
	int dy = y;
	if (dx > w - x) {
		dx = w - x;
	}
	if (dy > h - y) {
		dy = h - y;
	}
	if (dy > dx) {
		return dx;
	}
	return dy;
}

int main(void) {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << getDistance(x, y, w, h);
}