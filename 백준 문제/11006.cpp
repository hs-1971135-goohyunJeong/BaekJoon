// 백준 : 남욱이의 닭장 - 11006번

#include <iostream>

using namespace std;

// 다리를 잃었다면 하나씩만 잃었음 => 다리가 모자란 수만큼 닭이 다리를 잃음

void solve(int n, int m) {
	int totalLegs = m * 2;
	int u = totalLegs - n;
	int t = m - u;
	cout << u << " " << t << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0, m = 0;
		cin >> n >> m;
		solve(n, m);
	}
}