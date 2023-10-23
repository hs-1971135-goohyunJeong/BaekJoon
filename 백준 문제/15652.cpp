// N°ú M (4) 15652¹ø

#include <iostream>

using namespace std;

void backTracking(int* arr, int n, int m, int k, int st) {
	if (m == k) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = st; i <= n; i++) {
		arr[k] = i;
		backTracking(arr, n, m, k+1, i);
	}
}

int main(void) {
	int n = 0, m = 0;
	cin >> n >> m;
	int* arr = new int[n+1];
	backTracking(arr, n, m, 0, 1);
	delete[] arr;
}