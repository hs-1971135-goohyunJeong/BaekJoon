#include<iostream>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n-1; j++) {
			if (j >= n - i-1 && j <= n + i-1) {
				cout << "*";
			}
			else if (j < n-i-1) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}