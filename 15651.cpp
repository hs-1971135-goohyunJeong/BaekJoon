// N°ú M (3) 15651¹ø

#include <iostream>

using namespace std;

void backTracking(int* arr, int n, int m, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[k] = i;
		backTracking(arr, n, m, k + 1);
	}
}

int main(void) {
	int n = 0, m = 0;
	cin >> n >> m;
	int* arr = new int[n+1];
	
	backTracking(arr, n, m, 0);
	delete[] arr;


}