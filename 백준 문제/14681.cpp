#include <iostream>

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

int main() {
	int x, y;
	cin >> x;
	cin >> y;

	Point p =  Point(x, y);
	if (p.getX() > 0) {
		if (p.getY() > 0) {
			cout << 1;
		}
		else {
			cout << 4;
		}
	}
	else {
		if (p.getY() > 0) {
			cout << 2;
		}
		else {
			cout << 3;
		}
	}

	return 0;
}