#include <iostream>

using namespace std;

void drawRect(int mat[100][100], int x, int y) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mat[y + i][x + j] = 1;
		}
	}
}
int getArea(int mat[100][100]) {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (mat[i][j] == 1) {
				count++;
			}
		}
	}
	return count;
}

int main(void) {
	int n;
	cin >> n;
	int x = 0;
	int y = 0;
	int mat[100][100] = { 0 };
	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		drawRect(mat, x, y);
	}
	cout <<getArea(mat);
}