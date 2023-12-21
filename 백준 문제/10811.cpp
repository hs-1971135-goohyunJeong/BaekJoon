#include <iostream>

using namespace std;

void reverse(int arr[], int i, int j) {
	int start = 0, end = 0;
	int b = j;
	for (int a = i; a <= j; a++) {
		if ((b-a)>=0) {
			start = arr[a];
			end = arr[b];
			arr[a] = end;
			arr[b] = start;
			b--;
		}
	}
}

int main(void) {
	int n = 0, m = 0, i = 0, j = 0;
	cin >> n >> m;
	int* arr = new int[n];
	for (int index = 0; index < n; index++) {
		arr[index] = index+1;
	}
	for (int a = 0; a < m; a++) {
		cin >> i >> j;
		reverse(arr, i-1, j-1);
	}
	for (int index = 0; index < n; index++) {
		cout << arr[index] << " ";
	}
}