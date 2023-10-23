// 단지번호붙이기 2667번

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

void bfs(int** mat, bool** vis, int n, int& count, vector<int>& vec) {
	queue<pair<int, int>> q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 1 && vis[i][j] == false) {
				q.push({ i, j });
				count++;
				int size = 0;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							continue;
						}
						if (mat[nx][ny] == 0 || vis[nx][ny] == true) {
							continue;
						}
						q.push({ nx, ny });
						vis[nx][ny] = true;
						mat[nx][ny] = ++size;
					}
				}
				if (size == 0) {
					size++;
				}
				vec.push_back(size);
			}
		}
	}
}

void deleteIntMat(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
void deleteBoolMat(bool** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

int main(void) {
	int n = 0;
	cin >> n;
	int** mat = new int* [n];
	bool** vis = new bool* [n];
	string* str = new string[n];
	int count = 0;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
		vis[i] = new bool[n];
	}
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = (int)(str[i][j])-'0';
			vis[i][j] = false;
		}
	}
	bfs(mat, vis, n, count, vec);
	cout << count << "\n";
	sort(vec.begin(), vec.end());
	for (int i = 0; i < count; i++) {
		cout << vec.at(i) << "\n";
	}
	deleteIntMat(mat, n);
	deleteBoolMat(vis, n);
}