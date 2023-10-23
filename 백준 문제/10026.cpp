// 적록색약 10026번

#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int bfsNR(char** mat, bool** vis, int n) {
	queue<pair<int, int>> q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] != 'B' && vis[i][j] == false) {
				q.push({ i,j });
				vis[i][j] = true;
				count++;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							continue;
						}
						if (mat[nx][ny] == 'B' || vis[nx][ny] == true) {
							continue;
						}
						q.push({ nx, ny });
						vis[nx][ny] = true;
 					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 'B' && vis[i][j] == false) {
				q.push({ i,j });
				vis[i][j] = true;
				count++;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							continue;
						}
						if (mat[nx][ny] != 'B' || vis[nx][ny] == true) {
							continue;
						}
						q.push({ nx, ny });
						vis[nx][ny] = true;
					}
				}
			}
		}
	}
	return count;
}

int bfs(char** mat, bool** vis, int n) {
	queue<pair<int, int>> q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 'R' && vis[i][j] == false) {
				q.push({ i,j });
				vis[i][j] = true;
				count++;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							continue;
						}
						if (mat[nx][ny] != 'R' || vis[nx][ny] == true) {
							continue;
						}
						q.push({ nx, ny });
						vis[nx][ny] = true;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 'G' && vis[i][j] == false) {
				q.push({ i,j });
				vis[i][j] = true;
				count++;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							continue;
						}
						if (mat[nx][ny] != 'G' || vis[nx][ny] == true) {
							continue;
						}
						q.push({ nx, ny });
						vis[nx][ny] = true;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 'B' && vis[i][j] == false) {
				q.push({ i,j });
				vis[i][j] = true;
				count++;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							continue;
						}
						if (mat[nx][ny] != 'B' || vis[nx][ny] == true) {
							continue;
						}
						q.push({ nx, ny });
						vis[nx][ny] = true;
					}
				}
			}
		}
	}
	return count;
}

void deleteBoolMat(bool** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];

	}
	delete[] mat;
}

void deleteCharMat(char** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
void reset(bool** vis, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = false;
		}
	}
}
int main(void) {
	int n = 0;
	cin >> n;
	char** mat = new char* [n];
	string* str = new string[n];
	bool** vis = new bool*[n];
	for (int i = 0; i < n; i++) {
		mat[i] = new char[n];
		cin >> str[i];
		vis[i] = new bool[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = str[i][j];
			vis[i][j] = false;
		}
	}
	
	cout << bfs(mat, vis, n) << " ";
	reset(vis, n);
	cout << bfsNR(mat, vis, n);

	deleteBoolMat(vis, n);
	deleteCharMat(mat, n);
	delete[] str;
}