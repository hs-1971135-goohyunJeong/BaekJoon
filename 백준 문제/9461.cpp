// 파도반 수열 - 9461번

#include <iostream>

using namespace std;

int main(void) {
	int tc = 0;
	cin >> tc;
	long long table[101] = { 0 };
	table[0] = 0;
	table[1] = 1;
	table[2] = 1;
	table[3] = 1;
	table[4] = 2;
	table[5] = 2;
	for (int i = 6; i < 101; i++) {
		table[i] = table[i - 1] + table[i - 5];
	}
	while (tc-- > 0) {
		int n = 0;
		cin >> n;
		cout << table[n] <<"\n";
	}
}