#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	int minX;
	int minY;
	int maxX;
	int maxY;
	int x, y;
	cin >> x >> y;
	minX = maxX = x;
	minY = maxY = y;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		if (minX > x) {
			minX = x;
		}
		else if (maxX < x) {
			maxX = x;
		}
		if (minY > y) {
			minY = y;
		}
		else if (maxY < y) {
			maxY = y;
		}
	}
	cout << (maxX - minX) * (maxY - minY);
}