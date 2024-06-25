// 백준 : 이진수 변환 - 10829번

#include <iostream>
#include <vector>

using namespace std;

// 이진수로 변환할 때 나머지를 역순으로 배치해야 올바른 이진수가 됨
void solve(long long n) {
	vector<int> vec;
	while (true) {
		if (n == 0) {
			break;
		}
		vec.push_back(n % 2);
		n /= 2;
	}
	int size = vec.size();
	for (int i = size - 1; i >= 0; i--) {
		cout << vec.at(i);
	}
}

int main() {
	long long n = 0;
	cin >> n;
	solve(n);
}