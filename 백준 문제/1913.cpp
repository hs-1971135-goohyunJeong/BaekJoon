// 백준 : 달팽이 - 1913번

#include <iostream>

using namespace std;

// 2차원 배열이 채워진 부분 혹은 끝을 만나면 방향을 바꾸어서 채워나가는 식으로 진행한다.
// 0,0 에서 최대값으로 시작하며, 방향은 아래, 오른쪽, 위, 왼쪽 순으로 방향을 돌아가면서 바꾼다.
void full(int** mat, int n, int value, int& resultX, int& resultY) {
	// 이동 방향
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1, 0,-1,0 };
	int number = n * n;
	int x = 0;
	int y = 0;
	int direction = 0;
	while (true) {
		mat[y][x] = number;
		if (number == value) {
			resultX = x;
			resultY = y;
		}
		x = x + dx[direction];
		y = y + dy[direction];
		number--;
		// 방향이 바뀌어야하는 순간
		if (x < 0 || y < 0 || x >= n || y >= n || mat[y][x] != 0) {
			// 지금 위치는 if 문에 걸린 잘못된 위치임 -> 이전으로 되돌아간후 올바른 방향으로 이동한다
			x = x - dx[direction];
			y = y - dy[direction];
			direction = (direction + 1) % 4;
			x = x + dx[direction];
			y = y + dy[direction];
		}
		// 1까지 도달하면 다 채운것
		if (number <= 0) {
			break;
		}
	}

}
void deleteMat(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	int x = 0, y = 0;
	int item = 0;
	cin >> item;
	int** mat = new int* [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = 0;
		}
	}
	full(mat, n, item, x, y);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
	cout << y+1 <<" "<< x+1;
	deleteMat(mat, n);
}