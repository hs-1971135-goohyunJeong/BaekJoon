// 이건 꼭 풀어야 해! - 17390번

#include <iostream>
#include <algorithm>

using namespace std;

void prefix(int* arr, int* sum, int n) {
	sum[0] = 0;
	for (int i = 0; i < n; i++) {
		sum[i + 1] = arr[i] + sum[i];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, q = 0;
	cin >> n >> q;
	int* arr = new int[n];
	int* sum = new int[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	prefix(arr, sum, n);
	int start = 0;
	int end = 0;
	for (int i = 0; i < q; i++) {
		cin >> start >> end;
		cout << sum[end] - sum[start-1] << "\n";
	}
	delete[] arr;
	delete[] sum;
}