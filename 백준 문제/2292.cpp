#include <iostream>

using namespace std;

int main(void) {
	int num = 0;
	int count = 1;
	int start = 1;
	cin >> num;
	int i = 1;
	while (true) {
		if (num <= start) {
			break;
		}
		else {
			count++;
			start = start + i * 6;
			i++;
		}
		
	}
	cout << count;
}