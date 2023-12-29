// ÄõµåÆ®¸® - 1992¹ø

#include <iostream>
#include <string>

using namespace std;

void compress(int** mat, int n, int startR, int startC, int endR, int endC, string& str) {
	int standard = mat[startR][startC];
	bool isSame = true;
	for (int i = startR; i < endR; i++) {
		for (int j = startC; j < endC; j++) {
			if (standard != mat[i][j]) {
				isSame = false;
				break;
			}
		}
	}
	if (isSame == false) {
		str.append("(");
		compress(mat, n / 2, startR, startC, startR + n / 2, startC + n / 2, str);
		compress(mat, n / 2, startR, startC + n / 2, startR + n / 2, startC + n, str);
		compress(mat, n / 2, startR + n / 2, startC, startR + n, startC + n / 2, str);
		compress(mat, n / 2, startR + n / 2, startC + n / 2, startR + n, startC + n, str);
		str.append(")");
	}
	else {
		str.append(to_string(standard-'0'));
	}
}
void deleteIntMat(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
int main(void) {
	int n = 0;
	string str;
	cin >> n;
	int** mat = new int* [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			mat[i][j] = str[j];
		}
	}
	string result = "";
	compress(mat, n, 0, 0, n, n, result);
	cout << result;
	deleteIntMat(mat, n);
}