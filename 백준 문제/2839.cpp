// ¼³ÅÁ ¹è´Ş - 2839¹ø

#include <iostream>

using namespace std;

int dp(int n) {
	int arr[5001];
	arr[0] = 0;
	arr[1] = -1;
	arr[2] = -1;
	arr[3] = 1;
	arr[4] = -1;
	arr[5] = 1;
	for (int i = 6; i <= n; i++) {
		int a = 0, b = 0;
		if(arr[i-3] != -1) {
			a = arr[i - 3] + 1;
		}
		else{
			a = -1;
		}
		if (arr[i-5] != -1) {
			b = arr[i - 5] + 1;
		}
		else{
			b = -1;
		}
		if (a > b) {
			if (b != -1) {
				arr[i] = b;
			}
			else {
				arr[i] = a;
			}
		}
		else {
			if (a != -1) {
				arr[i] = a;
			}
			else {
				arr[i] = b;
			}
		}
	}
	return arr[n];
}

int main(void) {
	int n = 0;
	cin >> n;
	cout << dp(n);
}