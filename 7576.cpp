// 토마토 7576번

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

void bfs(int** mat, int** dis, int n, int m, queue<pair<int, int>>& q) {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m){
				continue;
			}
			if (mat[nx][ny] == 0) {
				mat[nx][ny] = 1;
				q.push({ nx, ny });
				dis[nx][ny] = dis[cur.X][cur.Y]+1;
			}
		}
	}
}
void deleteMatrix(int** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	int m = 0;
	cin >> m >> n;
	int** mat = new int* [n];
	int** dis = new int* [n];
	queue <pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m];
		dis[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			dis[i][j] = 0;
			if (mat[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}
	int count = 0;
	bfs(mat, dis, n, m, q);
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << mat[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	bool isBreak = false;
	for (int i = 0; i < n; i++) {
		if (isBreak) {
			break;
		}
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 0) {
				count = -1;
				isBreak = true;
				break;

			}
			if (count < dis[i][j]) {
				count = dis[i][j];
			}
		}
	}
	cout << count;
	deleteMatrix(mat, n, m);
	deleteMatrix(dis, n, m);
}