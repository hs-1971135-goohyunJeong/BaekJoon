#include <iostream>

using namespace std;

char alpha[5] = { 'E', 'A', 'B', 'C', 'D' };

char getAlpha(int arr[]) {
	int count0 = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[i] == 0) {
			count0++;
		}
	}
	return alpha[count0];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int arr[4] = { 0 };
	for (int i = 0; i < 3; i++) {
		cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
		cout << getAlpha(arr) << "\n";
	}
}