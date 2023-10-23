// บา! 4179น๘

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

void bfsF(char** mat, int** dis, int r, int c, queue<pair<int, int>>& q) {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				continue;
			}
			if (dis[nx][ny] == 0 && mat[nx][ny] != '#') {
				dis[nx][ny] = dis[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
			}
			
		}
	}
}
bool bfsH(char** mat, int** disF, int** disH, int r, int c, queue<pair<int, int>>& q) {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop(); 
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				cout << disH[cur.X][cur.Y];
				return true;
			}
			if (mat[nx][ny] == '.' && disH[nx][ny] == 0) {
				disH[nx][ny] = disH[cur.X][cur.Y]+1;
				if (disF[nx][ny] - 1 >= disH[nx][ny] || disF[nx][ny] == 0) {
					q.push({ nx,ny });
				}
				else {
					disH[nx][ny] = 0;
				}
			}
		}
	}
	return false;
}

void deleteIntMatrix(int** mat, int r, int c) {
	for (int i = 0; i < r; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
void deleteCharMatrix(char** mat, int r, int c) {
	for (int i = 0; i < r; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

int main(void) {
	int r = 0;
	int c = 0;
	cin >> r >> c;
	char** mat = new char* [r];
	int** disF = new int* [r];
	int** disH = new int* [r];
	queue<pair<int, int>> human;
	queue<pair<int, int>> fire;
	for (int i = 0; i < r; i++) {
		mat[i] = new char[c];
		disF[i] = new int[c];
		disH[i] = new int[c];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
			disF[i][j] = 0;
			disH[i][j] = 0;
			if (mat[i][j] == 'J') {
				human.push({i, j});
				disH[i][j] = 1;
			}
			else if (mat[i][j] == 'F') {
				fire.push({ i,j });
				disF[i][j] = 1;
			}
		}
	}
	bfsF(mat, disF, r, c, fire);
	
	bool isEscape = bfsH(mat, disF, disH, r, c, human);

	if(!isEscape) {
		cout << "IMPOSSIBLE";
	}
	deleteIntMatrix(disH, r, c);
	deleteIntMatrix(disF, r, c);
	deleteCharMatrix(mat, r, c);
}