// 퍼거슨과 사과 - 2942번

#include <iostream>

using namespace std;

int solve(int big, int small) {
	int mod = big % small;
	if (mod == 0) {
		return small;
	}
	return solve(small, mod);
}

int main(void) {
	int r = 0, g = 0;

	cin >> r >> g;
	int big = 0;
	int small = 0;
	if (r < g) {
		big = g;
		small = r;
	}
	else {
		big = r;
		small = g;
	}
	int result = solve(big, small);
	for (int i = 1; i <= result; i++) {
		if (result % i == 0) {
			cout << i << " " << r / i << " " << g / i << "\n";
		}
	}
}