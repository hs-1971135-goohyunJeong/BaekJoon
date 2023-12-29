// 색종이 만들기 - 2630번
#include <iostream>

using namespace std;

void slice(int** mat,int n, int startR, int startC, int endR, int endC, int& blue, int& white) {
	int standard = mat[startR][startC];
	bool isOneColor = true;
	for (int i = startR; i < endR; i++) {
		for (int j = startC; j < endC; j++) {
			if (standard != mat[i][j]) {
				isOneColor = false;
				break;
			}
		}
	}
	if (isOneColor == false) {
		slice(mat, n / 2, startR, startC, startR + n / 2, startC + n / 2, blue, white); //1번 구역 나누기
		slice(mat, n / 2, startR + n / 2, startC, startR+n, startC + n / 2, blue, white); //2번 구역 나누기
		slice(mat, n / 2, startR, startC + n / 2, startR + n / 2, startC+n, blue, white); //3번 구역 나누기
		slice(mat, n / 2, startR + n / 2, startC + n / 2, startR+n, startC+n, blue, white); //4번 구역 나누기
	}
	else {
		if (standard == 0) {
			white++;
		}
		else {
			blue++;
		}
	}
}

int main(void) {
	int n = 0;
	cin >> n;
	int** mat = new int* [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	int blue = 0;
	int white = 0;
	slice(mat, n, 0, 0, n, n, blue, white);
	cout << white << "\n" << blue;
}