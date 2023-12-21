#include <iostream>

using namespace std;

void reverse(int arr[], int a, int b) {
	int tmp = 0;
	a = a - 1;
	b = b - 1;
	for (int i = 0; i <= (b-a)/2; i++) {
		tmp = arr[a+i];
		arr[a + i] = arr[b - i];
		arr[b - i] = tmp;
	}
}
int main(void) {
	int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int a = 0;
	int b = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		reverse(arr, a, b);
	}
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << " ";
	}
}