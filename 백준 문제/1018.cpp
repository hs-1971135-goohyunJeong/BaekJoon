// 체스판 다시 칠하기 - 1018번

#include <iostream>

using namespace std;

// 하얀색이 먼저 시작하는 8x8 체스판은 아래와 같은 모양 밖에 없다.
char WhiteBoard[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
};
// 검은색이 먼저 시작하는 8x8 체스판은 아래와 같은 모양 밖에 없다.
char BlackBoard[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
};

int changeCount(char** board, int n, int m, int startX, int startY) {
	int countW = 0;
	int countB = 0;
	int idx = 0;
	int idy = 0;
	for (int i = startX;i < startX + 8; i++) {
		for (int j = startY; j < startY + 8; j++) {
			if (board[i][j] != WhiteBoard[idx][idy]) {
				countW++;
			}
			if (board[i][j] != BlackBoard[idx][idy]) {
				countB++;
			}
			idy++;
		}
		idx++;
		idy = 0;
	}
	return countW > countB ? countB : countW;
}
void deleteMat(char** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 0, m = 0;
	cin >> n >> m;
	char** board = new char* [n];

	int min = INT16_MAX;
	for (int i = 0; i < n; i++) {
		board[i] = new char[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			int tmp = changeCount(board, n, m, i, j);
			if (min > tmp) {
				min = tmp;
			}
		}
	}
	deleteMat(board, n, m);
	cout << min;
}