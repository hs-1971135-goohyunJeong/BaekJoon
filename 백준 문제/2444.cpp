#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	int max = 2 * n - 1;
	int blank = (max - 1) / 2;
	int star = 1;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < blank; j++) {
			cout << " ";
		}
		for (int j = 0; j < star;j++) {
			cout << "*";
		}
		if (i < n-1) {
			blank--;
			star = star + 2;
		}
		else {
			blank++;
			star = star - 2;
		}
		cout << endl;
	}

}