// »ó¹üºôµù - 6593¹ø

#include <iostream>
#include <queue>

using namespace std;

class Pos {
private :
	int l;
	int r;
	int c;
public :
	Pos() {

	}
	Pos(int l, int r, int c) {
		this->l = l;
		this->r = r;
		this->c = c;
	}
	int getL() {
		return l;
	}
	int getR() {
		return r;
	}
	int getC() {
		return c;
	}
};

int bfs(char*** mat, int*** vis, int l, int r, int c) {
	queue<Pos> q;
	int dl[6] = { 1,0,0,-1,0,0 };
	int dr[6] = { 0,1,0,0,-1,0 };
	int dc[6] = { 0,0,1,0,0,-1 };
	int gl = 0;
	int gr = 0;
	int gc = 0;
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (mat[k][i][j] == 'S') {
					q.push(Pos(k, i, j));
					vis[k][i][j] = 0;
				}
				if (mat[k][i][j] == 'E') {
					gl = k;
					gr = i;
					gc = j;
				}
			}
		}
	}

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nl = cur.getL() + dl[i];
			int nr = cur.getR() + dr[i];
			int nc = cur.getC() + dc[i];
			if (nl < 0 || nr < 0 || nc < 0 || nl >= l || nr >= r || nc >= c) {
				continue;
			}
			if (mat[nl][nr][nc] == '#' || vis[nl][nr][nc] != -1) {
				continue;
			}
			vis[nl][nr][nc] = vis[cur.getL()][cur.getR()][cur.getC()] + 1;
			q.push(Pos(nl, nr, nc));
		}

	}
	return vis[gl][gr][gc];
	
}

void deleteMat(int*** mat, int l, int r, int c) {
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < r; i++) {
			delete[] mat[k][i];
		}
		delete[] mat[k];
	}
	delete[] mat;
}
void deleteMat(char*** mat, int l, int r, int c) {
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < r; i++) {
			delete[] mat[k][i];
		}
		delete[] mat[k];
	}
	delete[] mat;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l = 0, r = 0, c = 0;
	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) {
			break;
		}
		char*** mat = new char** [l];
		int*** vis = new int** [l];
		for (int k = 0; k < l; k++) {
			mat[k] = new char* [r];
			vis[k] = new int* [r];
			for (int i = 0; i < r; i++) {
				mat[k][i] = new char[c];
				vis[k][i] = new int[c];
			}
		}
		for (int k = 0; k < l; k++) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cin >> mat[k][i][j];
					vis[k][i][j] = -1;
				}
			}
		}
		int n = 0;
		if ((n = bfs(mat, vis, l, r, c)) == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << n << " minute(s).\n";
		}
		deleteMat(mat, l, r, c);
		deleteMat(vis, l, r, c);
	}
	
}