// 백준 : 할로윈의 사탕 - 10178번

#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int c = 0, v = 0;
		cin >> c >> v;
		cout << "You get " << c / v << " piece(s) and your dad gets " << c % v <<" piece(s).\n";
	}
}
