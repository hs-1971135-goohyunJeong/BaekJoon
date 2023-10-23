// ��ģ�� - 2193��

#include <iostream>

using namespace std;

long long dp(int n) {
	long long* arr0 = new long long[n + 1];
	long long* arr1 = new long long[n + 1];
	// arr0 �� i���� �ڸ����� ��ģ���� 0���� ������ �������� ��Ÿ����.
	// arr1 �� i���� �ڸ����� ��ģ���� 1�� ������ �������� ��Ÿ����.
	arr0[0] = 0;
	arr1[0] = 0;
	arr0[1] = 0;
	arr1[1] = 1;
	arr0[2] = 1;
	arr1[2] = 0;
	for (int i = 3; i < n + 1; i++) {
		// ���� �ǵڿ� 0�� ������ �������� 0�� 1 ��� �� �� �����Ƿ� arr0[i]�� arr0[i-1]+arr1[i-1]�̴�.
		arr0[i] = arr0[i - 1] + arr1[i-1];
		//���� �ǵڿ� 1�� ������ �������� 0�� �;� �ϹǷ� arr1[i]�� arr0[i-1]�� �ȴ�.
		arr1[i] = arr0[i - 1];
	}
	long long result = arr0[n] + arr1[n];
	delete[] arr0;
	delete[] arr1;
	return result;
}

int main(void) {
	int n = 0;
	cin >> n;
	if (n == 1) {
		cout << 1;
	}
	else {
		cout << dp(n);
	}
	
}