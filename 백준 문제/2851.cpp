// ���� : ���� ������ - 2851��

#include <iostream>

using namespace std;
#define SIZE 10

// 100�� �ѱ�� 100�� �ѱ����� ���� ���Ͽ� 100�� ����� ���� ����� ��´�.
int solve(int arr[]) {
	int sum = 0;
	int i;
	for (i = 0; i < SIZE; i++) {
		sum += arr[i];
		if (sum >= 100) {
			break;
		}
	}
	
	if (sum != 100) {
		int compare = sum - arr[i];
		if (sum - 100 > 100 - compare) {
			sum = compare;
		}
	}
	return sum;
	
}
int main() {
	int arr[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}
	cout << solve(arr);
	
}