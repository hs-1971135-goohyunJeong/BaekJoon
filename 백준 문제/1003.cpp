// 피보나치 함수 - 1003번

#include <iostream>

using namespace std;

void dp(int n, int& count0, int& count1) {
	int arr0[41] = { 0 };
	int arr1[41] = { 0 };
	arr0[0] = 1;
	arr1[0] = 0;

	arr0[1] = 0;
	arr1[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr0[i] = arr0[i - 1] + arr0[i - 2];
		arr1[i] = arr1[i - 1] + arr1[i - 2];
	}
	count0 = arr0[n];
	count1 = arr1[n];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 0;
	cin >> tc;
	while (tc-- > 0) {
		int n = 0;
		int count0 = 0;
		int count1 = 0;
		cin >> n;
		dp(n, count0, count1);
		cout << count0 << " " << count1 << "\n";
	}

}