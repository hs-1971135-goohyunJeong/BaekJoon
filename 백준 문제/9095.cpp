// 1,2,3 더하기 - 9095번

#include <iostream>

using namespace std;

int main(void) {
	int t = 0;
	cin >> t;
	int arr[12] = { 0 };
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 12; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < t; i++) {
		int n = 0;
		cin >> n;
		
		cout << arr[n] << "\n";
	}
}