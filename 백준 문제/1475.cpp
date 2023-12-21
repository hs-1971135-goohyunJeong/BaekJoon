#include <iostream>

using namespace std;

int main(void) {
	int arr[10] = { 0 };
	int tmp = 0;
	cin >> tmp;
	while (tmp > 0) {
		int n = tmp%10;
		tmp = tmp / 10;
		arr[n]++;
	}
	int idx = 0;
	int max = arr[0];
	
	arr[9] += arr[6];
	arr[6] = 0;
	if (arr[9] % 2 == 0) {
		arr[9] /= 2;
	}
	else {
		arr[9] = arr[9] / 2 + 1;
	}
	for (int i = 0; i < 10; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	cout << max;
}