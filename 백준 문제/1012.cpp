// 유기농 배추 1012번

#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int bfs(int** mat, bool** visit, int n, int m) {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int count = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1 && visit[i][j] == false) {
				q.push({ i,j });
				count++;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.X + dx[i];
						int ny = cur.Y + dy[i];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
							continue;
						}
						if (mat[nx][ny] == 0 || visit[nx][ny] == true) {
							continue;
						}
						q.push({ nx, ny });
						visit[nx][ny] = true;
					}
				}
			}
		}
	}
	return count;
	
}
void deleteIntMat(int** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
void deleteBoolMat(bool** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	int n = 0, m = 0, k = 0;
	cin >> t;
	for (int a = 0; a < t; a++) {
		cin >> m >> n >> k;
		int** mat = new int*[n];
		bool** visit = new bool* [n];
		for (int i = 0; i < n; i++) {
			mat[i] = new int[m];
			visit[i] = new bool[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mat[i][j] = 0;
				visit[i][j] = false;
			}
		}
		for (int i = 0; i < k; i++) {
			int x = 0, y = 0;
			cin >> y >> x;
			mat[x][y] = 1;
		}
		cout << bfs(mat, visit, n, m)<<"\n";
		deleteIntMat(mat, n, m);
		deleteBoolMat(visit, n, m);
	}

	
}