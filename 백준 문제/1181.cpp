// 단어 정렬 - 1181번

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareTo(string a, string b) {
	if (a.length() < b.length()) {
		return false;
	}
	else if(a.length() == b.length()){
		if (a.compare(b) < 0) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return true;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	vector<string> str;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		str.push_back(tmp);
	}
	sort(str.begin(), str.end(), compareTo);
	for (int i = 0; i < n; i++) {
		if (i < n-1 && str.at(i).compare(str.at(i + 1)) == 0) {
			continue;
		}
		cout << str.at(i) << "\n";
	}
}