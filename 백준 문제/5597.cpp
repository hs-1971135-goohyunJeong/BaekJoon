#include <iostream>

using namespace std;

int main() {
	int size = 28;
	int* student = new int[size];
	int check[30] = { 0 };
	int arr[2] = { 0 };
	for (int i = 0; i < size; i++) {
		cin >> student[i];
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < size; j++) {
			if ((i+1) == student[j]) {
				check[i] = 1;
				break;
			}
		}
	}
	int k = 0;
	for (int i = 0; i < 30; i++) {
		if (check[i] != 1) {
			arr[k] = i;
			k++;
		}
		if (k >= 2) {
			break;
		}
	}
	if (arr[0] > arr[1]) {
		cout << arr[1] << endl;
		cout << arr[0];
	}
	else {
		cout << arr[0]+1 << endl;
		cout << arr[1]+1;
	}
	delete[] student;
}