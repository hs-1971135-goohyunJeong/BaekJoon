// 영역 구하기 2583번
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

void drawRectangle(int** mat) {
	int sx = 0, sy = 0, ex = 0, ey = 0;
	cin >> sx >> sy >> ex >> ey;
	for (int i = sx; i < ex; i++) {
		for (int j = sy; j < ey; j++) {
			mat[i][j] = -1;
		}
	}
}

void bfs(int** mat, bool** vis, int n, int m, int& count, vector<int>& vec) {
	queue<pair<int, int>> q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int size = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 0 && vis[i][j] == false) {
				q.push({ i, j });
				count++;
				size = 1;
				bool isSpread = false;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
							continue;
						}
						if (mat[nx][ny] != 0 || vis[nx][ny] != false) {
							continue;
						}
						q.push({ nx, ny });
						vis[nx][ny] = true;
						mat[nx][ny] = size++;
						isSpread = true;
					}
				}
				if (isSpread == false) {
					vec.push_back(size);
				}
				else {
					vec.push_back(size - 1);
				}
			}
		}
	}
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m = 0, n = 0, k = 0;
	cin >> m >> n >> k;
	int** mat = new int* [n];
	bool** vis = new bool* [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m];
		vis[i] = new bool[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = 0;
			vis[i][j] = false;
		}
	}
	for (int i = 0; i < k; i++) {
		drawRectangle(mat);
	}
	int count = 0;
	vector<int> vec;
	bfs(mat, vis, n, m, count, vec);
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << count << "\n";
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i)<<" ";
	}
}
