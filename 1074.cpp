// Z 1074¹ø
#include <iostream>

using namespace std;

int calculate(int n, int r, int c) {
	if (n == 0) {
		return 0;
	}
	int half = 1 << (n - 1);
	if (r < half && c < half) {
		return calculate(n - 1, r, c);
	}
	else if (r < half && c >= half) {
		return half*half+calculate(n - 1, r, c - half);
	}
	else if (r >= half && c < half) {
		return half * half * 2 + calculate(n - 1, r - half, c);
	}
	return half * half * 3 + calculate(n - 1, r - half, c - half);
	
}


int main(void) {
	int n = 0;
	cin >> n;
	int r = 0, c = 0;
	cin >> r >> c;
	
	cout << calculate(n, r, c);
}