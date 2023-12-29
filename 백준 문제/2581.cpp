#include <iostream>

using namespace std;

int searchMinPrimary(int min, int max) {
	for (int i = min; i <= max; i++) {
		bool isPrimary = true;
		if (i == 1) {
			continue;
		}
		for (int j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				isPrimary = false;
				break;
			}
		}
		if (isPrimary) {
			return i;
		}
	}
}

int sumPrimary(int min, int max) {
	int sum = 0;
	for (int i = min; i <= max; i++) {
		bool isPrimary = true;
		if (i == 1) {
			continue;
		}
		for (int j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				isPrimary = false;
				break;
			}
		}
		if (isPrimary) {
			sum += i;
		}
	}
	if (sum == 0) {
		return -1;
	}
	else {
		return sum;
	}
}

int main(void) {
	int max, min;
	cin >> min >> max;
	cout << sumPrimary(min, max) << endl;
	if (sumPrimary(min, max) == -1) {
		return 0;
	}
	cout << searchMinPrimary(min, max)<<endl;
}