#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int arr[9] = { 0 };
	int res[2] = { 0 };
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int start = 1;
	int end = 0;
	int goal = sum - 100;
	while (true) {
		if (start >= 9) {
			break;
		}
		if (start <= end) {
			start++;
			end = 0;
		}
		if (goal == arr[start] + arr[end]) {
			res[0] = arr[start];
			res[1] = arr[end];
			break;
		}
		end++;
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++) {
		if (arr[i] != res[0] && arr[i] != res[1]) {
			cout << arr[i] << "\n";
		}
	}
}