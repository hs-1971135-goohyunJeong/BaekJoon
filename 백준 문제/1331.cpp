// ����Ʈ ���� - 1331��

#include <iostream>

using namespace std;

bool bfs() {
	int board[6][6] = { 0 };
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			board[i][j] = -1;
		}
	}
	int x;
	int y;
	char tmp;
	// ����Ʈ�� �̵��ϸ鼭 �ѹ��� ��� ��Ż�� �� �� ������
	bool isValid = true;
	// ����Ʈ�� �̵��� �� �ִ� ���
	int dx[8] = { 1,1,-1,-1,2,-2,2,-2 };
	int dy[8] = { 2,-2,2,-2,1,1,-1,-1 };

	// ù ������ġ�� ������� ����
	cin >> tmp >> y;
	x = tmp - 'A';
	y = y - 1;
	board[x][y] = 0;

	// ù ������ ������ �κ��� ��ΰ� �´��� Ȯ���ؾ���
	for (int i = 1; i < 36; i++) {
		//���� ���ǿ��� ��ΰ� �˸´� ��
		bool isCheck = false;
		cin >> tmp >> y;
		x = tmp - 'A';
		y = y - 1;
		for (int j = 0; j < 8; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= 6 || ny >= 6) {
				continue;
			}
			if (board[nx][ny] == i - 1) {
				isCheck = true;
				break;
			}
		}
		// ����Ʈ�� ������ �� ���� ������ �̵������� isValid = false
		if (!isCheck) {
			isValid = false;
		}
		// �������� �湮�� ���� ������ isValid = false
		if (board[x][y] != -1) {
			isValid = false;
		}
		board[x][y] = i;
	}
	// ������ �������� ������������ �� �� �ִ��� Ȯ��
	bool isCycle = false;
	if (isValid) {
		for (int j = 0; j < 8; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= 6 || ny >= 6) {
				continue;
			}
			if (board[nx][ny] == 0) {
				isCycle = true;
				break;
			}
		}

	}
	if (!isCycle) {
		isValid = false;
	}
	return isValid;
}

int main(void) {
	if (bfs()) {
		cout << "Valid";
	}
	else {
		cout << "Invalid";
	}
	return 0;
}