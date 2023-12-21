// 1로 만들기 2 - 12852번

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	int arr[1000001] = { 0 };
	int trc[1000002] = { 0 };
	arr[0] = 0;
	trc[0] = 0;
	arr[1] = 0;
	trc[1] = 0;
	arr[2] = 1;
	trc[2] = 1;
	arr[3] = 1;
	trc[3] = 1;
	for (int i = 4; i <= n; i++) {
		int a = INT16_MAX, b = INT16_MAX, c = INT16_MAX;
		if (i % 3 == 0) {
			a = arr[i / 3] + 1;
		}
		if (i % 2 == 0) {
			b = arr[i / 2] + 1;
		}
		c = arr[i - 1] + 1;
		if (min({ a, b, c }) == a) {
			arr[i] = a;
			trc[i] = i / 3;
		}
		else if (min({ a, b, c }) == b) {
			arr[i] = b;
			trc[i] = i / 2;
		}
		else {
			arr[i] = c;
			trc[i] = i - 1;
		}
	}
	cout << arr[n] << "\n";
	for (int i = n; i >= 1; ) {
		cout << i << " ";
		i = trc[i];
	}
}