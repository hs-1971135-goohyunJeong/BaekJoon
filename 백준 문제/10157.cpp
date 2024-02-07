// �ڸ����� - 10157��

#include <iostream>

using namespace std;

enum STATE { UP, RIGHT, DOWN, LEFT };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1,0, 1, 0 };

bool fillSeat(int seat[1000][1000], int x, int y , int wait, int& rx, int& ry) {
	seat[y - 1][0] = 1;
	STATE state = UP;
	int cx = 0;
	int cy = y-1;
	while (true) {
		if (seat[cy][cx] == wait) { // ���� �ڸ��� ����ȣ�� ��ġ�ϴ��� Ȯ��
			ry = (y-1-cy)+1; // �ε����� ����� �°� ��ȯ���ִ� �۾�
			rx = cx+1;
			return true;
		}
		int nx = cx + dx[state];
		int ny = cy + dy[state];
		int finishCount = 0; // ��� �� ���θ��� Ƚ���� üũ
		for (int i = 0; i < 4; i++) {
			if (seat[cy + dy[i]][cx + dx[i]] != 0) {  // �̹� ������ �ڸ��̸� ���θ��� ��
				finishCount++;
			}
		}
		if (finishCount == 4) { // ����̴ϱ� 4�� ���θ������� Ȯ�� -> ������ �ڸ����� ������ ��
			return false;
		}
		if (nx < 0 || nx >= x || ny < 0 || ny >= y || seat[ny][nx] != 0) {
			state = static_cast<STATE>((static_cast<int>(state)+1)%4);
			continue;
		}
		seat[ny][nx] = seat[cy][cx] + 1;
		cy = ny;
		cx = nx;
	}
}

void print(int seat[1000][1000], int x, int y){
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << seat[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(void) {
	int x = 0;
	int y = 0;
	cin >> x >> y;
	int number = 0;
	cin >> number;
	int seat[1000][1000] = { 0 };
	int rx = 0;
	int ry = 0;
	if (fillSeat(seat, x, y, number, rx, ry)) {
		cout << rx << " " << ry <<"\n";
	}
	else {
		cout << 0;
	}
	//print(seat, x, y);
}