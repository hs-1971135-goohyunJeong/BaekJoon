// 가장 긴 증가하는 부분 수열 - 11053번
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp(vector<int>& vec, int n) {
	vector<int> table;
	int result = 0;
	for (int i = 0; i < n; i++) {
		table.push_back(0);
		for (int j = i; j >= 0; j--) {
			if (vec.at(j) < vec.at(i)) {
				if (table.at(i) < table.at(j)) {
					table[i] = table[j];
				}
			}
		}
		table[i] += 1;
	}
	sort(table.begin(), table.end());
	result = table.at(n-1);
	return result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int item = 0;
		cin >> item;
		vec.push_back(item);
	}
	cout << dp(vec, n);
}