// N°ú M (6) - 15655¹ø

#include <iostream>
#include <algorithm>
using namespace std;

void backTracking(int* arr, int* res, bool* vis, int n, int m, int k, int st) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = st; i < n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			res[k] = arr[i];
			backTracking(arr, res, vis, n, m, k+1, i);
			vis[i] = false;
		}
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
	backTracking(arr, res, vis, n, m, 0, 0);
	delete[] arr;
	delete[] res;
	delete[] vis;
}