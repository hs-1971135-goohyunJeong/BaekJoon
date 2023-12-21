#include <iostream>

using namespace std;

void factorization(int n) {
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			n /= i;
			cout << i << endl;
			i--;
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	factorization(n);
}