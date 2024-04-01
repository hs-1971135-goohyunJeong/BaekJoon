// ºù°í - 2578¹ø

#include <iostream>

using namespace std;

int checkBingo(int board[5][5]) {
	int result = 0;
	bool isBingo = true;
	for (int i = 0; i < 5; i++) {
		if (board[0][i] == -1) {
			for (int j = 0; j < 5; j++) {
				if (board[j][i] != -1) {
					isBingo = false;
					break;
				}
			}
			if (isBingo) {
				result++;
			}
			isBingo = true;
		}
		
	}
	isBingo = true;
	for (int i = 0; i < 5; i++) {
		if (board[i][0] == -1) {
			for (int j = 0; j < 5; j++) {
				if (board[i][j] != -1) {
					isBingo = false;
					break;
				}
			}
			result;
			if (isBingo) {
				result++;
			}
			isBingo = true;
		}
		
	}
	isBingo = true;
	for (int i = 0; i < 5; i++) {
		if (board[i][i] != -1) {
			isBingo = false;
			break;
		}
	}
	if (isBingo) {
		result++;
	}
	isBingo = true;
	for (int i = 0; i < 5; i++) {
		if (board[4-i][i] != -1) {
			isBingo = false;
			break;
		}
	}
	if (isBingo) {
		result++;
	}
	return result;
}
void eraseBoard(int board[5][5], int value) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == value) {
				board[i][j] = -1;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int board[5][5] = { 0 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	int i = 0;
	for (i = 0; i < 25; i++) {
		int tmp = 0;
		cin >> tmp;
		eraseBoard(board, tmp);
		int line = 0;
		line = checkBingo(board);
		if (line >= 3) {
			break;
		}
	}
	cout << i + 1;
}