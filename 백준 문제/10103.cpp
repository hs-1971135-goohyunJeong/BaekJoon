// 백준 : 주사위 게임 - 10103번

#include <iostream>

using namespace std;

void solve(int& chang, int& sang, int c, int s) {
	if (c < s) {
		chang -= s;
	}
	else if (c > s) {
		sang -= c;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int chang = 100;
	int sang = 100;

	int n = 0;
	int c = 0;
	int s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> s;
		solve(chang, sang, c, s);
	}
	cout << chang << "\n" << sang;
}