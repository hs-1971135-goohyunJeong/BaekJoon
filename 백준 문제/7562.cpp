// 나이트의 이동 7562번
#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int bfs(int** mat, int l) {
	int dx[8] = { 2,2,-2,-2,1,-1,1,-1};
	int dy[8] = { -1,1,-1,1,2,2,-2,-2};
	int kx = 0, ky = 0, gx = 0, gy = 0;
	cin >> kx >> ky >> gx >> gy;
	queue<pair<int, int>> q;
	q.push({ kx,ky });
	mat[kx][ky] = 1;
	bool isFind = false;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (isFind) {
			break;
		}
		for (int i = 0; i < 8; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= l || ny >= l) {
				continue;
			}
			if (mat[nx][ny] != 0) {
				continue;
			}
			mat[nx][ny] = mat[cur.X][cur.Y] + 1;
			if (nx == gx && ny == gy) {
				isFind = true;
				break;
			}
			q.push({ nx, ny });
		}
	}
	return mat[gx][gy];
}

void deleteIntMat(int** mat, int l) {
	for (int i = 0; i < l; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

int main(void) {
	int t = 0;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int l = 0;
		cin >> l;
		int** mat = new int* [l];
		for (int i = 0; i < l; i++) {
			mat[i] = new int[l];
		}
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				mat[i][j] = 0;
			}
		}
		cout << bfs(mat, l)-1 << "\n";
		deleteIntMat(mat, l);
	}
	
	return 0;
}