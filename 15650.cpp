// N°ú M (2) 15650¹ø

#include <iostream>

using namespace std;

void backTracking(int* arr, bool* vis, int n, int m, int k, int st) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = st; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			arr[k] = i;
			backTracking(arr, vis, n, m, k + 1, i);
			vis[i] = false;
		}
	}
}

int main(void) {
	int n = 0, m = 0;
	cin >> n >> m;
	int* arr = new int[n + 1];
	bool* vis = new bool[n + 1];
	for (int i = 0; i <= n; i++) {
		vis[i] = false;
	}
	backTracking(arr, vis, n, m, 0, 1);
	delete[] arr;
	delete[] vis;
}