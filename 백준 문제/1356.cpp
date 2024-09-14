// 백준 : 유진수 - 1356번

#include <iostream>

using namespace std;
// front 배열에 앞에서부터 곱을 누적한 것을 저장함
// back 배열에 뒤에서부터 곱을 누적한 것을 저장함
// 누적된 값이 같아질 때 유진수임
void reverse(int arr[], int size) {
	int tmp = 0;
	for (int i = 0; i < size/2; i++) {
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
	}
}

int main() {
	int n = 0;
	int arr[17] = { 0 };
	cin >> n;
	int front[17] = { 0 };
	int back[17] = { 0 };
	int tmp = n;
	int size = 0;
	if (n < 10) {
		cout << "NO";
		return 0;
	}
	while(tmp != 0) {
		arr[size] = tmp % 10;
		size++;
		tmp /= 10;
	}
	// arr이 역순으로 곱해지기 때문에 front와 back의 이름에 맞게 하려면 arr을 역순으로 만들어야함
	reverse(arr, size);
	front[0] = arr[0];
	back[size-1] = arr[size - 1];
	// 앞에서부터 곱을 누적
	for (int i = 1; i < size-1; i++) {
		front[i] = front[i - 1] * arr[i];
	}
	// 뒤에서부터 곱을 누적
	for (int i = size - 2; i > 0; i--) {
		back[i] = back[i + 1] * arr[i];
	}
	// 뒤에서 누적시킨 것을 역순으로 배치 해주는게 편하다고 생각하여 역순 배치
	reverse(back, size);

	for (int i = 0; i < size; i++) {
		int j = size - i - 2;
		if (j < 0) {
			break;
		}
		if (front[i] == back[j]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}