// ��ȭ�� - 13699��

#include <iostream>

using namespace std;

// DP ���̺�
long long arr[25] = { 0 };
// t(n)=t(0)*t(n-1)+t(1)*t(n-2)+...+t(n-1)*t(0) 

// �ݺ��Ǵ� ���� ������ �׳� ������ ���ϴ� ���� ��ȿ���� -> DP �� ����� ���� �����Ͽ� ���
long long solve(int n) {
	if (n == 0) {
		return 1;
	}
	// DP ���̺� ���� �ִ� ��� -> �̹� ������� �ִ� ���� DP ���̺� ����� ���� ���
	if (arr[n] != 0) {
		return arr[n];
	}
	// DP ���̺� ���� ���� ���
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += solve(i) * solve(n-1- i);
	}
	// DP ���̺� ���� ����
	arr[n] = sum;
	return sum;
}

int main(void) {
	int n = 0;
	cin >> n;
	cout << solve(n);
}