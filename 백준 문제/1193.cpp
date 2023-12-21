#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	int start = 0;
	int gap = 1;
	while (true) {
		start = start + gap;
		if (n <= start) {
			break;
		}
		gap += 1;
	}
	int index = start - n;
	if (gap % 2 == 0) {
		cout << gap - index << "/" << index + 1;
	}
	else {
		cout << index + 1 << "/" << gap - index;
	}
}