// ���� : �������� ���� - 11006��

#include <iostream>

using namespace std;

// �ٸ��� �Ҿ��ٸ� �ϳ����� �Ҿ��� => �ٸ��� ���ڶ� ����ŭ ���� �ٸ��� ����

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