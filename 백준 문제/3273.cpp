#include <iostream>

using namespace std;

int check[1000001];

int main(void) {
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	int goal = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> goal;

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (goal - arr[i] > 0 && goal - arr[i] < 1000001 && check[goal - arr[i]] == 1) {
			count++;
		}
		else {
			check[arr[i]] = 1;
		}
	}
	cout << count;
}