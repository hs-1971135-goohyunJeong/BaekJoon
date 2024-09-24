//백준 : 암기왕-2776번
#include <iostream>
#include <unordered_map>

using namespace std;


void solve() {
	// 해쉬맵
	unordered_map<int, int> hash;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp=0;
		cin >> tmp;
		hash[tmp] = 1;
	}
	int m = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		cin >> tmp;
		//find()
		//해당 키에 해당하는 value가 있는지 찾는 함수
		//end()
		//해쉬맵을 벗어났음을 의미
		if (hash.find(tmp) != hash.end()) {
			cout << hash[tmp] << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solve();
	}
}