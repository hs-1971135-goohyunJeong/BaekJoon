// °¨½Ã - 15683¹ø

#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

void printMat(char** mat, int n, int m) {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

class CCTV {
protected:
	int x;
	int y;
	int kind;
public:
	CCTV(int x, int y, char k) {
		this->x = x;
		this->y = y;
		kind = atoi(&k);
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getKind() {
		return kind;
	}
	virtual void draw1(char** mat, int n, int m) {};
	virtual void draw2(char** mat, int n, int m) {};
	virtual void draw3(char** mat, int n, int m) {};
	virtual void draw4(char** mat, int n, int m) {};
};

class CCTV1 : public CCTV {
public:
	CCTV1(int x, int y, char k) : CCTV(x, y, k) {

	}
	virtual void draw1(char** mat, int n, int m);
	virtual void draw2(char** mat, int n, int m);
	virtual void draw3(char** mat, int n, int m);
	virtual void draw4(char** mat, int n, int m);
};
class CCTV2 : public CCTV {
public:
	CCTV2(int x, int y, char k) : CCTV(x, y, k) {

	}
	virtual void draw1(char** mat, int n, int m);
	virtual void draw2(char** mat, int n, int m);
	virtual void draw3(char** mat, int n, int m);
	virtual void draw4(char** mat, int n, int m);
};
class CCTV3 : public CCTV {
public:
	CCTV3(int x, int y, char k) : CCTV(x, y, k) {

	}
	virtual void draw1(char** mat, int n, int m);
	virtual void draw2(char** mat, int n, int m);
	virtual void draw3(char** mat, int n, int m);
	virtual void draw4(char** mat, int n, int m);
};
class CCTV4 : public CCTV {
public:
	CCTV4(int x, int y, char k) : CCTV(x, y, k) {

	}
	virtual void draw1(char** mat, int n, int m);
	virtual void draw2(char** mat, int n, int m);
	virtual void draw3(char** mat, int n, int m);
	virtual void draw4(char** mat, int n, int m);
};
class CCTV5 : public CCTV {
public:
	CCTV5(int x, int y, char k) : CCTV(x, y, k) {

	}
	virtual void draw1(char** mat, int n, int m);
	virtual void draw2(char** mat, int n, int m);
	virtual void draw3(char** mat, int n, int m);
	virtual void draw4(char** mat, int n, int m);
};
void CCTV1::draw1(char** mat, int n, int m) {
	for (int i = y; i < m; i++) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV1::draw2(char** mat, int n, int m) {
	for (int i = y; i >= 0; i--) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV1::draw3(char** mat, int n, int m) {
	for (int i = x; i >= 0; i--) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}
	}

}
void CCTV1::draw4(char** mat, int n, int m) {
	for (int i = x; i < n; i++) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}
	}

}

void CCTV2::draw1(char** mat, int n, int m) {
	for (int i = y; i < m; i++) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}
	for (int i = y; i >= 0; i--) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV2::draw2(char** mat, int n, int m) {
	for (int i = x; i < n; i++) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}
	}
	for (int i = x; i >= 0; i--) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}
	}

}
void CCTV2::draw3(char** mat, int n, int m) {
	for (int i = y; i < m; i++) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}
	for (int i = y; i >= 0; i--) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV2::draw4(char** mat, int n, int m) {
	for (int i = x; i < n; i++) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}
	}
	for (int i = x; i >= 0; i--) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}
	}

}


void CCTV3::draw1(char** mat, int n, int m) {
	for (int i = x; i >= 0; i--) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = y; i < m; i++) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV3::draw2(char** mat, int n, int m) {
	for (int i = x; i < n; i++) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = y; i < m; i++) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV3::draw3(char** mat, int n, int m) {
	for (int i = x; i < n; i++) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = y; i >= 0; i--) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV3::draw4(char** mat, int n, int m) {
	for (int i = x; i >= 0; i--) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = y; i >= 0; i--) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}

void CCTV4::draw1(char** mat, int n, int m) {
	for (int i = x; i >= 0; i--) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = x; i < n; i++) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = y; i < m; i++) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV4::draw2(char** mat, int n, int m) {
	for (int i = x; i < n; i++) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = y; i < m; i++) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}
	for (int i = y; i >= 0; i--) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV4::draw3(char** mat, int n, int m) {
	for (int i = x; i < n; i++) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = x; i >= 0; i--) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = y; i >= 0; i--) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV4::draw4(char** mat, int n, int m) {
	for (int i = x; i >= 0; i--) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = y; i >= 0; i--) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}
	for (int i = y; i < m; i++) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}


void CCTV5::draw1(char** mat, int n, int m) {
	for (int i = x; i >= 0; i--) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = x; i < n; i++) {
		if (mat[i][y] == '6') {
			break;
		}
		if (mat[i][y] == '0') {
			mat[i][y] = '#';
		}

	}
	for (int i = y; i >= 0; i--) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}
	for (int i = y; i < m; i++) {
		if (mat[x][i] == '6') {
			break;
		}
		if (mat[x][i] == '0') {
			mat[x][i] = '#';
		}
	}

}
void CCTV5::draw2(char** mat, int n, int m) {
	draw1(mat, n, m);
}
void CCTV5::draw3(char** mat, int n, int m) {
	draw1(mat, n, m);
}
void CCTV5::draw4(char** mat, int n, int m) {
	draw1(mat, n, m);
}
void deleteCharMat(char** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

void copy(char** mat, char cpy[8][8], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cpy[i][j] = mat[i][j];
		}
	}
}
void copy2(char** mat, char cpy[8][8], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = cpy[i][j];
		}
	}
}

int getCount(char** mat, int n, int m) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '0') {
				count++;
			}
		}
	}
	return count;
}

void backTracking(char** mat, vector<CCTV*> cctv, int n, int m, int k, vector<int>& store) {

	if (cctv.size() == k) {
		//printMat(mat, n, m);
		store.push_back(getCount(mat, n, m));
		return;
	}
	char cpy[8][8];
	copy(mat, cpy, n, m);
	//printMat(mat, n, m);
	if ((*cctv[k]).getKind() != '5' || (*cctv[k]).getKind() != '2') {
		(*cctv[k]).draw1(mat, n, m);
		backTracking(mat, cctv, n, m, k + 1, store);
		copy2(mat, cpy, n, m);

		(*cctv[k]).draw2(mat, n, m);
		backTracking(mat, cctv, n, m, k + 1, store);
		copy2(mat, cpy, n, m);

		(*cctv[k]).draw3(mat, n, m);
		backTracking(mat, cctv, n, m, k + 1, store);
		copy2(mat, cpy, n, m);

		(*cctv[k]).draw4(mat, n, m);
		backTracking(mat, cctv, n, m, k + 1, store);
		copy2(mat, cpy, n, m);
	}
	else if ((*cctv[k]).getKind() == '5') {
		(*cctv[k]).draw1(mat, n, m);
		backTracking(mat, cctv, n, m, k + 1, store);
		copy2(mat, cpy, n, m);
	}
	else if ((*cctv[k]).getKind() == '2') {
		(*cctv[k]).draw1(mat, n, m);
		backTracking(mat, cctv, n, m, k + 1, store);
		copy2(mat, cpy, n, m);

		(*cctv[k]).draw2(mat, n, m);
		backTracking(mat, cctv, n, m, k + 1, store);
		copy2(mat, cpy, n, m);
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	char** mat = new char* [n];

	vector<CCTV*> cctv;
	vector<int> store;

	for (int i = 0; i < n; i++) {
		mat[i] = new char[m];

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] != '0' && mat[i][j] != '6') {
				if (mat[i][j] == '1') {
					CCTV1* ct = new CCTV1(i, j, mat[i][j]);
					cctv.push_back(ct);
				}
				else if (mat[i][j] == '2') {
					CCTV2* ct = new CCTV2(i, j, mat[i][j]);
					cctv.push_back(ct);
				}
				else if (mat[i][j] == '3') {
					CCTV3* ct = new CCTV3(i, j, mat[i][j]);
					cctv.push_back(ct);
				}
				else if (mat[i][j] == '4') {
					CCTV4* ct = new CCTV4(i, j, mat[i][j]);
					cctv.push_back(ct);
				}
				else if (mat[i][j] == '5') {
					CCTV5* ct = new CCTV5(i, j, mat[i][j]);
					cctv.push_back(ct);
				}
			}

		}
	}
	backTracking(mat, cctv, n, m, 0, store);
	sort(store.begin(), store.end());
	cout << store[0];
	deleteCharMat(mat, n);

}