#include <iostream>

using namespace std;

int main() {
	int num;
	int count=0;
	int v;
	cin >> num;
	int* arr = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	cin >> v;
	for (int i = 0; i < num; i++) {
		if (v == arr[i]) {
			count++;
		}
	}
	cout << count;

}