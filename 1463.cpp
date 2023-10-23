// 1로 만들기 - 1463번

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n = 0;
	cin >> n;
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(0);

	for (int i = 2; i <= n; i++) {
		int a = n;
		int b = n;
		int c = n;
		if (i % 3 == 0) {
			a = vec.at(i / 3) + 1;
		}
		if (i % 2 == 0) {
			b = vec.at(i / 2) + 1;
		}
		c = vec.at(i - 1) + 1;
		vec.push_back(min({ a,b,c }));
		
	}
	cout << vec.at(n);
}