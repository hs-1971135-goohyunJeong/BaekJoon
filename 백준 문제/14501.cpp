// Επ»η - 14501Ήψ

#include <iostream>

using namespace std;

int dp(int mat[15][2], int n) {
	int table[15] = { 0 };
	for (int i = 0; i < n; i++) {
		int time = mat[i][0];
		if (time + i <= n) {
			table[i] += mat[i][1];
			for (int j = i; j+time < n; j++) {
				if (table[time + j] < table[i]) {
					table[time + j] = table[i];
				}
			}
			
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (result < table[i]) {
			result = table[i];
		}
	}
	return result;
	
}

int main(void) {
	int n = 0;
	cin >> n;
	int mat[15][2] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> mat[i][0] >> mat[i][1];
	}
	cout << dp(mat, n);
}