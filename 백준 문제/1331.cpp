// 나이트 투어 - 1331번

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
	// 나이트가 이동하면서 한번도 경로 이탈을 한 적 없는지
	bool isValid = true;
	// 나이트가 이동할 수 있는 경로
	int dx[8] = { 1,1,-1,-1,2,-2,2,-2 };
	int dy[8] = { 2,-2,2,-2,1,1,-1,-1 };

	// 첫 시작위치는 마음대로 지정
	cin >> tmp >> y;
	x = tmp - 'A';
	y = y - 1;
	board[x][y] = 0;

	// 첫 시작을 제외한 부분은 경로가 맞는지 확인해야함
	for (int i = 1; i < 36; i++) {
		//현재 스탭에서 경로가 알맞는 지
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
		// 나이트가 움직일 수 없는 곳으로 이동했으면 isValid = false
		if (!isCheck) {
			isValid = false;
		}
		// 예전에도 방문한 적이 있으면 isValid = false
		if (board[x][y] != -1) {
			isValid = false;
		}
		board[x][y] = i;
	}
	// 마지막 지점에서 시작지점으로 갈 수 있는지 확인
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