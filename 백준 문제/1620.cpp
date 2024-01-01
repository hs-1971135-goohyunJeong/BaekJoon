// 나는야 포켓몬 마스터 이다솜 - 1620번

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void find(unordered_map<string, int>& hash, string& tmp) {
	auto value = hash.find(tmp);
	if (value != hash.end()) {
		cout << value->second+1 << "\n";
	}
	
}
void find(vector<string>& str, int idx) {
	cout << str.at(idx-1) << "\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<string> str;
	unordered_map<string, int> hash;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		str.push_back(tmp);
		hash.insert(unordered_map<string, int>::value_type(tmp, i));
	}
	
	for (int i = 0; i < m; i++) {
		string tmp;
		int idx = 0;
		cin >> tmp;
		if (isdigit(tmp[0])) {
			idx = stoi(tmp);
			find(str, idx);
		}
		else {
			find(hash, tmp);
		}
	}
}