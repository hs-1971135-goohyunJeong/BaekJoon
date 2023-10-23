// N°úM(1) 15649¹ø

#include <iostream>

using namespace std;

void backTracking(int n, int m, int k, int* arr, bool* vis) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			arr[k] = i;
			backTracking(n, m, k + 1, arr, vis);
			vis[i] = false;
		}
	}
}

int main(void) {
	int n = 0, m = 0;
	cin >> n >> m;
	int* arr = new int[n+1];
	bool* vis = new bool[n+1];
	for (int i = 0; i <= n; i++) {
		vis[i] = false;
	} 
	backTracking(n, m, 0, arr, vis);
	delete[] vis;
	delete[] arr;
}