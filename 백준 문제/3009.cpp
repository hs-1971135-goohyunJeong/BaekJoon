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

class Rect {
private:
	Point* a;
	Point* b;
	Point* c;
	Point* d;
public:
	Rect(int point[]) {
	
		this->a = new Point(point[0], point[1]);
		this->b = new Point(point[2], point[3]);
		this->c = new Point(point[4], point[5]);
		setD();
	}
	~Rect() {
		delete a;
		delete b;
		delete c;
		delete d;
	}
	
	void setD() {
		int dx = 0;
		int dy = 0;
		if (a->getX() == b->getX()) {
			dx = c->getX();
		}
		else if (a->getX() == c->getX()) {
			dx = b->getX();
		}
		else if (b->getX() == c->getX()) {
			dx = a->getX();
		}
		if (a->getY() == b->getY()) {
			dy = c->getY();
		}
		else if (a->getY() == c->getY()) {
			dy = b->getY();
		}
		else if (b->getY() == c->getY()) {
			dy = a->getY();
		}
		d = new Point(dx, dy);
	}
	Point* getD() {
		return d;
	}
};

int main(void) {
	int point[6] = { 0 };
	for (int i = 0; i < 6; i++) {
		cin >> point[i];
	}
	Rect r = Rect(point);
	cout << r.getD()->getX() << " " << r.getD()->getY();
}