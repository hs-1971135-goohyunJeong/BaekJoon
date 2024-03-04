// 백준 : 숨바꼭질 6 - 17087번

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// a 가 b 보다 작으면 값을 교환하는 함수
void swap(long long& a, long long& b) {
	if (a < b) {
		long long tmp = a;
		a = b;
		b = tmp;
	}
}
// 최대 공약수 구하기
long long gcd(long long a, long long b) {
	// a 가 항상 크다는 보장이 없으므로 큰것을 a 로 바꾸는 과정을 수행
	swap(a, b);
	while (b != 0) {
		long long tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

// D = 거리들의 최대 공약수
// 앞에서 구한 최대 공약수와 현재의 거리의 최대 공약수를 구하면 거리들의 최대 공약수가 됨
long long solve(long long n, vector<long long>& dist) {
	long long result = dist.at(0);
	for (long long i = 1; i < n; i++) {
		result = gcd(result, dist.at(i));
	}
	return result;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, s;
	cin >> n >> s;
	vector<long long> kids = vector<long long>();
	vector<long long> dist = vector<long long>();
	for (long long i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		kids.push_back(tmp);
	}
	for (long long i = 0; i < n; i++) {
		long long tmp = abs(s - kids.at(i)); // 거리가 음수가 나오지 못하게 절대값 취해줌
		dist.push_back(tmp);
	}
	cout << solve(n, dist);
}