// µèº¸Àâ - 1764¹ø

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0;
	cin >> n >> m;

	vector<string> vec;
	for (int i = 0; i < n + m; i++) {
		string tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	vector<string> cpy;
	for (int i = 1; i < vec.size(); i++) {
		if (vec.at(i) == vec.at(i - 1)) {
			cpy.push_back(vec.at(i));
		}
	}
	cout << cpy.size()<<"\n";
	for (int i = 0; i < cpy.size(); i++) {
		cout << cpy.at(i) << "\n";
	}
}