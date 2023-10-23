// 불 - 5427번

#include <iostream>
#include <queue>

#define X first
#define Y second
using namespace std;

void bfsF(char** mat, int** vis, int w, int h) {
	queue<pair<int, int>> q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (mat[i][j] == '*') {
				q.push({ i,j });
				vis[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
				continue;
			}
			// 벽으로 막혔거나 이미 간 곳이면 패스
			if (mat[nx][ny] == '#' || vis[nx][ny] != INT16_MAX) {
				continue;
			}
			q.push({ nx, ny });
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
		}
		
	}
}
int bfsH(char** mat, int** vis, int** visF, int w, int h) {
	queue<pair<int, int>> q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (mat[i][j] == '@') {
				q.push({ i,j });
				vis[i][j] = 1;
				break;
			}
			
		}
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
				return vis[cur.X][cur.Y];
			}
			// 벽으로 막혔거나, 불이 먼저 지나갔거나, 이미 간 곳이면 패스
			if (mat[nx][ny] == '#' || visF[nx][ny] <= vis[cur.X][cur.Y]+1 || vis[nx][ny] != 0) {
				continue;
			}
			q.push({ nx, ny });
			vis[nx][ny] = vis[cur.X][cur.Y]+1;
		}
		
	}
	return -1;
}

void deleteMat(char** mat, int w, int h) {
	for (int i = 0; i < h; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
void deleteMat(int** mat, int w, int h) {
	for (int i = 0; i < h; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
void printMat(char** mat, int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << mat[i][j];
		}
		cout << "\n";
	}
}
void printMat(int** mat, int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << mat[i][j] <<" ";
		}
		cout << "\n";
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 0;
	cin >> tc;
	while (tc-- > 0) {
		int w = 0, h = 0;
		cin >> w >> h;
		char** mat = new char* [h];
		int** visF = new int* [h];
		int** visH = new int* [h];
		for (int i = 0; i < h; i++) {
			mat[i] = new char[w];
			visF[i] = new int[w];
			visH[i] = new int[w];
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> mat[i][j];
				// bfsH에서 while 문 안에 있는 for문의 두번째 if문 때문에 큰 수로 지정함(1,000,000 이상이면 다 될 듯)
				visF[i][j] = INT16_MAX; 
				visH[i][j] = 0;
			}
		}
		int n = 0;
		bfsF(mat, visF, w, h);
		//printMat(mat, w, h);
		//cout << "\n";
		//printMat(visF, w, h);
		if ( (n = bfsH(mat, visH, visF, w, h)) == -1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << n << "\n";
		}
		deleteMat(mat, w, h);
		deleteMat(visF, w, h); 
		deleteMat(visH, w, h);
	}
	
	
}