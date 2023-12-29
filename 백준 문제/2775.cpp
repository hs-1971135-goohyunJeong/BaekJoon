#include <iostream>

using namespace std;

void init(int arr[15][15]) {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (j == 0) {
				arr[i][j] = 1;
			}
			if (i == 0) {
				arr[i][j] = j + 1;
			}
			else if(j !=0) {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}
	}
}

int main(void) {
	int t;
	cin >> t;
	int arr[15][15] = { 0 };
	int* result = new int[t];
	init(arr);
	for (int i = 0; i < t; i++) {
		int k, n;
		cin >> k;
		cin >> n;
		result[i] = arr[k][n - 1];
	}
	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
	delete[] result;
}