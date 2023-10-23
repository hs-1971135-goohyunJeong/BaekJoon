// 2xn 타일링 - 11726번

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	
	for (int i = 2; i < n; i++) {
		vec.push_back((vec.at(i - 2) + vec.at(i - 1)) % 10007);
	}
	cout << vec.at(n - 1);

}