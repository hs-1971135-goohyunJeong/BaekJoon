// N°ú M (12) - 15666¹ø

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backTracking(vector<int> arr, int* res, int n, int m, int k , int st) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = st; i < n; i++) {
		res[k] = arr[i];
		backTracking(arr, res, n, m, k + 1, i);
	}
}

int main(void) {
	int n = 0, m = 0;
	cin >> n >> m;
	int* arr = new int[n];
	bool vis[10000];
	int* res = new int[m];
	vector<int> arr2;
	for (int i = 0; i < 10000; i++) {
		vis[i] = false;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (vis[arr[i]] == false) {
			arr2.push_back(arr[i]);
		}
		vis[arr[i]] = true;
	}
	sort(arr2.begin(), arr2.end());
	backTracking(arr2, res, arr2.size(), m, 0, 0);

	delete[] arr;
	delete[] res;
	
}