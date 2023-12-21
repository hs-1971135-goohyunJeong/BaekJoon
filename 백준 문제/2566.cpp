#include <iostream>

using namespace std;

void findMaxValue(int arr[][9], int& row, int& col, int& max) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (max <= arr[i][j]) {
				max = arr[i][j];
				row = i+1;
				col = j+1;
			}
		}
	}
}

int main(void) {
	int arr[9][9] = { 0 };
	int row = 0;
	int col = 0;
	int max = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
	findMaxValue(arr, row, col, max);
	cout << max << endl;
	cout << row <<" " << col;
}