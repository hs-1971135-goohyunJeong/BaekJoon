#include <iostream>

using namespace std;

int selfNum(int num) {
	int sum = num;
	while (num > 0) {
		sum += num % 10;
		num = num / 10;
	}
	return sum;
}

int main(void) {
	int arr[10000] = { 0 };
	for (int i = 0; i < 10000; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < 10000; i++) {
		int j = selfNum(i + 1);
		if (j <= 10000) {
			arr[j - 1] = 0;
		}
	}
	for (int i = 0; i < 10000; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << "\n";
		}
	}
}