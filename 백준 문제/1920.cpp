//수 찾기 1920번

#include <iostream>
#include <algorithm>

using namespace std;



int binSearch(int arr[], int n, int target) {
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] > target) {
			end = mid - 1;
		}
		else if(arr[mid] < target) {
			start = mid + 1;
		}
		else {
			return 1;
		}
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int m = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int target = 0;
		cin >> target;
		cout << binSearch(arr, n, target) << "\n";
	}
}