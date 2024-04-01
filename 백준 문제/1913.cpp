// ���� : ������ - 1913��

#include <iostream>

using namespace std;

// 2���� �迭�� ä���� �κ� Ȥ�� ���� ������ ������ �ٲپ ä�������� ������ �����Ѵ�.
// 0,0 ���� �ִ밪���� �����ϸ�, ������ �Ʒ�, ������, ��, ���� ������ ������ ���ư��鼭 �ٲ۴�.
void full(int** mat, int n, int value, int& resultX, int& resultY) {
	// �̵� ����
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
		// ������ �ٲ����ϴ� ����
		if (x < 0 || y < 0 || x >= n || y >= n || mat[y][x] != 0) {
			// ���� ��ġ�� if ���� �ɸ� �߸��� ��ġ�� -> �������� �ǵ��ư��� �ùٸ� �������� �̵��Ѵ�
			x = x - dx[direction];
			y = y - dy[direction];
			direction = (direction + 1) % 4;
			x = x + dx[direction];
			y = y + dy[direction];
		}
		// 1���� �����ϸ� �� ä���
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