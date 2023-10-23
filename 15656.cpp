// N°ú M (7) - 15656¹ø

#include <iostream>
#include <algorithm>

using namespace std;

void backTracking(int* arr, int* res, bool* vis, int n, int m, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		res[k] = arr[i];
		backTracking(arr, res, vis, n, m, k + 1);
	}
}

int main(void) {
	int n = 0, m = 0;
	cin >> n >> m;
	int* arr = new int[n];
	int* res = new int[m];
	bool* vis = new bool[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		vis[i] = false;
	}
	sort(arr, arr + n);
	backTracking(arr, res, vis, n, m, 0);
	delete[] arr;
	delete[] res;
	delete[] vis;
}