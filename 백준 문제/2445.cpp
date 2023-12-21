#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int j = 0;
		for (j = 0; j < i; j++) {
			cout << "*";
		}
		for (j=0; j < 2 * n - 2 * i; j++) {
			cout << " ";
		}
		for (j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = n-1; i > 0; i--) {
		int j = 0;
		for (j = 0; j < i; j++) {
			cout << "*";
		}
		for (j = 0; j < 2 * n - 2 * i; j++) {
			cout << " ";
		}
		for (j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}