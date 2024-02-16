// 점화식 - 13699번

#include <iostream>

using namespace std;

// DP 테이블
long long arr[25] = { 0 };
// t(n)=t(0)*t(n-1)+t(1)*t(n-2)+...+t(n-1)*t(0) 

// 반복되는 값이 많은데 그냥 일일이 구하는 것은 비효율적 -> DP 로 계산한 값을 저장하여 사용
long long solve(int n) {
	if (n == 0) {
		return 1;
	}
	// DP 테이블에 값이 있는 경우 -> 이미 계산한적 있는 경우는 DP 테이블에 저장된 것을 사용
	if (arr[n] != 0) {
		return arr[n];
	}
	// DP 테이블에 값이 없는 경우
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += solve(i) * solve(n-1- i);
	}
	// DP 테이블에 값을 저장
	arr[n] = sum;
	return sum;
}

int main(void) {
	int n = 0;
	cin >> n;
	cout << solve(n);
}