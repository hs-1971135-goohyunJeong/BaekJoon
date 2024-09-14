// ���� : ������ - 1356��

#include <iostream>

using namespace std;
// front �迭�� �տ������� ���� ������ ���� ������
// back �迭�� �ڿ������� ���� ������ ���� ������
// ������ ���� ������ �� ��������
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
	// arr�� �������� �������� ������ front�� back�� �̸��� �°� �Ϸ��� arr�� �������� ��������
	reverse(arr, size);
	front[0] = arr[0];
	back[size-1] = arr[size - 1];
	// �տ������� ���� ����
	for (int i = 1; i < size-1; i++) {
		front[i] = front[i - 1] * arr[i];
	}
	// �ڿ������� ���� ����
	for (int i = size - 2; i > 0; i--) {
		back[i] = back[i + 1] * arr[i];
	}
	// �ڿ��� ������Ų ���� �������� ��ġ ���ִ°� ���ϴٰ� �����Ͽ� ���� ��ġ
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