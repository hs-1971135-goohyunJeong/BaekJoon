// 백준 : 아름다운 수 - 2774번
#include <iostream>

using namespace std;

int countingNumber(int n) {
	int result = 0;
	bool num[10] = { false };
	while (n > 0) {
		num[n % 10]= true;
		n /= 10;
	}
	for (int i = 0; i < 10; i++) {
		if (num[i]) {
			result++;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		cin >> n;
		cout << countingNumber(n) << "\n";
	}
}