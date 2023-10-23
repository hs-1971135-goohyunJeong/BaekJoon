// 정수 삼각형 - 1932번

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void deleteMat(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

int dp(int** mat, int n, int count) {
	int** table = new int* [n];
	int floor = 1;
	int k = 0;
	for (int i = 0; i < n; i++) {
		table[i] = new int[n];
	}
	table[0][0] = mat[0][0];
	for (int i = 1; i < count; i++) {
		if (k == 0) {
			table[floor][k] = table[floor - 1][0]+mat[floor][k];
		}
		else if (k == floor) {
			table[floor][k] = table[floor-1][floor-1]+mat[floor][k];
		}
		else {
			table[floor][k] = max(table[floor - 1][k - 1], table[floor - 1][k])+mat[floor][k];
		}
		
		k++;
		if (k > floor) {
			floor++;
			k = 0;
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (result < table[n - 1][i]) {
			result = table[n - 1][i];
		}
	}
	deleteMat(table, n);
	return result;
}

int getCount(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += i;
	}
	return result;
}

int main(void) {
	int n = 0;
	cin >> n;
	int** mat = new int* [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
	}
	int count = getCount(n);
	int floor = 0;
	int k = 0;
	for (int i = 0; i < count; i++) {
		cin >> mat[floor][k];
		k++;
		if(k > floor){
			floor++;
			k = 0;
		}
	}
	cout << dp(mat, n, count);
	deleteMat(mat, n);

}