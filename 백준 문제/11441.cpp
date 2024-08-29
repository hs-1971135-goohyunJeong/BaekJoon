// 백준 : 합 구하기 - 11441번

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	int m = 0;
	vector<int> vec;
	vector<int> sum;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		vec.push_back(tmp);
	}
	sum.push_back(vec.at(0));
	for (int i = 1; i < n; i++) {
		sum.push_back(sum.at(i - 1) + vec.at(i));
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int start = 0;
		int end = 0;
		cin >> start >> end;
		int tmp=0;
		if (start - 1 > 0) {
			tmp = sum.at(end - 1) - sum.at(start - 2);
		}
		else {
			tmp = sum.at(end - 1);
		}
		cout << tmp << "\n";
	}
}