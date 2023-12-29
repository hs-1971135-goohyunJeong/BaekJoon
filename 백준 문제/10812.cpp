#include <iostream>

using namespace std;

void init(int arr[], int n) {
	for (int index = 0; index < n; index++) {
		arr[index] = index + 1;
	}
}
void copy(int arr[], int tmp[], int n) {
	for (int index = 0; index < n; index++) {
		tmp[index] = arr[index];
	}
}
void print(int arr[], int n) {
	for (int index = 0; index < n; index++) {
		cout << arr[index] << " ";
	}
}
void rotate(int arr[], int i, int j, int k, int n) {
	int* tmp = new int[n];
	copy(arr, tmp, n);
	int a = k;
	int index = i;
	for (index = i; index <= j; index++) {
		if (a <= j) {
			arr[index] = tmp[a++];
		}
		else{
			a = i;
			break;
		}
	}
	while (index <= j) {
		arr[index++] = tmp[a++];
	}
	delete[] tmp;
}

int main(void) {
	int n = 0, m = 0, i=0, j=0, k=0;
	cin >> n >> m;
	int* arr = new int[n];
	init(arr, n);
	
	for (int a = 0; a < m; a++) {
		cin >> i >> j >> k;
		rotate(arr, i-1, j-1, k-1, n);
	}
	print(arr, n);
	delete[] arr;
}