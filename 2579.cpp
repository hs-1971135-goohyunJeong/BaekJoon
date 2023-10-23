// 계단 오르기 - 2579번

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	vector<int> vec;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[2];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int k = 0;
		cin >> k;
		vec.push_back(k);
	}
	if (n > 1) {
		arr[0][0] = vec.at(0);
		arr[0][1] = vec.at(0);
		arr[1][0] = vec.at(1);
		arr[1][1] = arr[0][0] + vec.at(1);

		for (int i = 2; i < n; i++) {
			arr[i][0] = max(arr[i - 2][0], arr[i - 2][1]) + vec.at(i);
			arr[i][1] = arr[i - 1][0] + vec.at(i);
		}
		cout << max(arr[n - 1][0], arr[n - 1][1]);
	}
	else {
		cout << vec.at(0);
	}
}
