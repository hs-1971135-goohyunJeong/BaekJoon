// 백준 : 첼시를 도와줘! - 11098번

#include <iostream>

using namespace std;

void solve(int p) {
	int max = 0;
	string bestPlayer = "";
	for (int i = 0; i < p; i++) {
		int salery = 0;
		string name = "";
		cin >> salery >> name;
		if (salery > max) {
			bestPlayer = name;
			max = salery;
		}
	}
	cout << bestPlayer << "\n";

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p = 0;
		cin >> p;
		solve(p);
	}

}