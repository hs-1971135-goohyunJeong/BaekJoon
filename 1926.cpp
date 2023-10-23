// ±×¸² 1926¹ø
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second 

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int** mat, bool** visit, int n, int m, int& max, int& count) {
	int size = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1 && visit[i][j] == false) {
				q.push({ i,j });
				visit[i][j] = true;
				count++;
				size++;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
							continue;
						}
						if (mat[nx][ny] == 0 || visit[nx][ny] == true) {
							continue;
						}
						q.push({ nx, ny });
						visit[nx][ny] = true;
						size++;
					}
				}
				if (max < size) {
					max = size;
				}
				size = 0;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	int m = 0;
	cin >> n >> m;
	int** mat = new int* [n];
	bool** visit = new bool* [n];
	int max = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m];
		visit[i] = new bool[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			visit[i][j] = false;
		}
	}
	bfs(mat, visit, n, m, max, count);
	cout << count << "\n" << max;
}