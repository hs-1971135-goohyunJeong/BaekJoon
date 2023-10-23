// 안전영역 2468번

#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

void clear(bool** vis, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = false;
		}
	}
}
void deleteBoolMatrix(bool** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
void deleteIntMatrix(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
void print(bool** mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}
int bfs(int** mat, int n, int limit) {
	int height = 1;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int max = 1;
	bool** vis = new bool* [n];
	for (int i = 0; i < n; i++) {
		vis[i] = new bool[n];
	}
	queue<pair<int, int>> q;
	queue<pair<int, int>> c;
	while (true) {
		clear(vis, n);
		
		for (int i = 0; i < n; i++) {
 			for (int j = 0; j < n; j++) {
				if (mat[i][j] <= height && vis[i][j] == false) {
					q.push({ i, j });
					vis[i][j] = true;
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						for (int k = 0; k < 4; k++) {
							int nx = cur.X + dx[i];
							int ny = cur.Y + dy[i];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
								continue;
							}
							if (mat[nx][ny] > height || vis[nx][ny] == true) {
								continue;
							}
							q.push({ nx, ny });
							vis[nx][ny] = true;
						}
					}
				}
			}
		}
		/*cout << "\n";
		cout << height << "\n";
		print(vis, n);*/
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j] == false) {
					c.push({ i, j });
					count++;
					vis[i][j] = true;
					while (!c.empty()) {
						pair<int, int> cur = c.front();
						c.pop();
						for (int k = 0; k < 4; k++) {
 							int nx = cur.X + dx[k];
							int ny = cur.Y + dy[k];
 							if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
								continue;
							}
							if (vis[nx][ny] == true) {
								continue;
							}
							c.push({ nx, ny });
							vis[nx][ny] = true;
							/*cout << "\n";
							print(vis, n);*/
						}
					}
				}
			}
		}
		/*cout << count << "\n";*/
		if (height == limit) {
			break;
		}
		if (max < count) {
			max = count;
		}
		height++;
	}
	deleteBoolMatrix(vis, n);
	return max;
}

int main(void) {
	int n = 0;
	cin >> n;
	int** mat = new int* [n];
	int limit = 0;
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] > limit) {
				limit = mat[i][j];
			}
		}
	}
	cout << bfs(mat, n, limit);
	deleteIntMatrix(mat, n);
}