#include <iostream>

using namespace std;

bool isOneNum(int x) {
	int d = 0;
	int size = 0;
	int tmp = x;
	while (tmp) {
		tmp = tmp / 10;
		size++;
	}
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = x % 10;
		x = x / 10;
	}
	d = arr[1] - arr[0];
	for (int i = 0; i < size-1; i++) {
		if (d != arr[i + 1] - arr[i]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int n = 0;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (isOneNum(i)) {
			count++;
		}
	}
	cout << count;
}