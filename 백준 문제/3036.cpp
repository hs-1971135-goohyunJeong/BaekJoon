// 백준 : 링 - 3036번

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	int standard = 0;
	cin >> standard;
	vector<int> vec = vector<int>();
	for (int i = 1; i < n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	for (int i = 0; i < n-1; i++) {
		int tmp = gcd(standard, vec.at(i));
		cout << standard/tmp <<"/" << vec.at(i) / tmp << "\n";
	}
}