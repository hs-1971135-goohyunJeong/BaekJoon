#include <iostream>

using namespace std;

int main(void) {
	int n, k;
	int count = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			count++;
		}
	}
	int j = 0;
	int* arr = new int[count];
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			arr[j] = i;
			j++;
		}
	}

	if (k > count) {
		cout << 0;
	}
	else {
		cout << arr[k-1];
	}
	
}