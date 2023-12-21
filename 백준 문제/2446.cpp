#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * n - 2 * (i-1) - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 2; i <= n; i++) {
		for (int j = n - i; j > 0; j--) {
			cout << " ";
		}
		for (int j = 0; j < 2*i-1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}