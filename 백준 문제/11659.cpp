// 구간 합 구하기 4- 11659번

#include <iostream>
#include <vector>
using namespace std;

void prefix(vector<int>& vec, vector<int>& sum) {
	sum.push_back(0);
	for (int i = 0; i < vec.size(); i++) {
		sum.push_back(vec.at(i) + sum.at(i));
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector<int> vec;
	vector<int> sum;
	for (int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;
		vec.push_back(a);
	}
	prefix(vec, sum);
	for (int i = 0; i < m; i++) {
		int st = 0, en = 0;
		cin >> st >> en;
		cout << sum.at(en) - sum.at(st-1) << "\n";
	}
}