// 자리배정 - 10157번

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
		if (seat[cy][cx] == wait) { // 현재 자리가 대기번호와 일치하는지 확인
			ry = (y-1-cy)+1; // 인덱스를 결과에 맞게 변환해주는 작업
			rx = cx+1;
			return true;
		}
		int nx = cx + dx[state];
		int ny = cy + dy[state];
		int finishCount = 0; // 사방 중 가로막힌 횟수를 체크
		for (int i = 0; i < 4; i++) {
			if (seat[cy + dy[i]][cx + dx[i]] != 0) {  // 이미 배정한 자리이면 가로막힌 것
				finishCount++;
			}
		}
		if (finishCount == 4) { // 사방이니까 4번 가로막혔는지 확인 -> 마지막 자리까지 도달한 것
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