// N°ú M (11) - 15665¹ø

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void backTracking(vector<int>& arr, int* res, int n, int m, int k) {
	if (m == k) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < arr.size(); i++) {
		res[k] = arr.at(i);
		backTracking(arr, res, n, m, k + 1);
	}
}

int main(void) {
	int n = 0, m = 0;
	cin >> n >> m;
	int* arr = new int[n];
	int* res = new int[m];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	vector<int> arr2;
	for (int i = 0; i < n; i++) {
		if (i < n - 1) {
			if (arr[i] == arr[i + 1]) {
				continue;
			}
		}
		arr2.push_back(arr[i]);
	}
	backTracking(arr2, res, n, m, 0);
	
	delete[] arr;
	delete[] res;

}