// 이친수 - 2193번

#include <iostream>

using namespace std;

long long dp(int n) {
	long long* arr0 = new long long[n + 1];
	long long* arr1 = new long long[n + 1];
	// arr0 는 i개의 자리수의 이친수가 0으로 끝나는 가짓수를 나타낸다.
	// arr1 은 i개의 자리수의 이친수가 1로 끝나는 가짓수를 나타낸다.
	arr0[0] = 0;
	arr1[0] = 0;
	arr0[1] = 0;
	arr1[1] = 1;
	arr0[2] = 1;
	arr1[2] = 0;
	for (int i = 3; i < n + 1; i++) {
		// 가장 맨뒤에 0이 오려면 그전에는 0과 1 모두 올 수 있으므로 arr0[i]는 arr0[i-1]+arr1[i-1]이다.
		arr0[i] = arr0[i - 1] + arr1[i-1];
		//가장 맨뒤에 1이 오려면 그전에는 0이 와야 하므로 arr1[i]는 arr0[i-1]이 된다.
		arr1[i] = arr0[i - 1];
	}
	long long result = arr0[n] + arr1[n];
	delete[] arr0;
	delete[] arr1;
	return result;
}

int main(void) {
	int n = 0;
	cin >> n;
	if (n == 1) {
		cout << 1;
	}
	else {
		cout << dp(n);
	}
	
}