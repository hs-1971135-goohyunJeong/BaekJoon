#include <iostream>

using namespace std;

int check(int arr[], int size) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		bool isPrimary = true;
		if (arr[i] == 1) {
			continue;
		}
		for (int j = 2; j <= arr[i]/2; j++) {
			if (arr[i] % j == 0) {
				isPrimary = false;
				break;
			}
		}
		if (isPrimary) {
			count++;
		}
	}
	return count;
}

int main(void) {
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << check(arr, n);
}