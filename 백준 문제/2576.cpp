#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int oddCount = 0;
	int oddSum = 0;
	int arr[7] = { 0 };
	int odd[7] = { 0 };
	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
		odd[i] = 999;
		if (arr[i] % 2 == 1) {
			odd[oddCount++] = arr[i];
			oddSum += arr[i];
		}
	}
	if (oddCount != 0) {
		sort(odd, odd + 7);
		cout << oddSum << "\n" << odd[0];
	}
	else {
		cout << -1;
	}
}