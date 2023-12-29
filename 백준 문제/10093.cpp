#include <iostream>

using namespace std;

int main(void) {
	long long a = 0;
	long long b = 0;
	long long tmp = 0;
	cin >> a >> b;
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	else if (a == b) {
		cout << 0;
		return 0;
	}
	cout << (long long)(b - a - 1) << "\n";
	for (long long i = 1; i < b - a; i++) {
		cout << (long long)(a + i) << " ";
	}
}