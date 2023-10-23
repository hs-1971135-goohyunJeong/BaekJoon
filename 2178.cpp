//¹Ì·Î Å½»ö 2178¹ø
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;


void bfs(int** mat, int** visit, int** dis, int n, int m) {
	queue<pair<int, int>> q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	q.push({ 0,0 });
	dis[0][0] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (mat[nx][ny] != 1 || visit[nx][ny] != 0) {
				continue;
			}
			q.push({ nx, ny });
			visit[nx][ny] = true;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
		}
		
	}
}
void delArray(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	int m = 0;
	cin >> n >> m;
	int** mat = new int* [n];
	int** dis = new int* [n];
	int** visit = new int* [n];
	string tmp;
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m];
		dis[i] = new int[m];
		visit[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			mat[i][j] = tmp[j] - '0';
			dis[i][j] = 0;
			visit[i][j] = 0;
		}
	}
	bfs(mat, visit, dis, n, m);
	cout << dis[n - 1][m - 1];
	delArray(mat, n);
	delArray(dis, n);
	delArray(visit, n);

}