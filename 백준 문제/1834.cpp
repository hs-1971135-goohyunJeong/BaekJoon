// ���� : �������� ���� ���� �� - 1834��

#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	unsigned long long sum = 0;
	for (long long i = 1; i < n; i++) {
		sum += n * i + i;
	}
	cout << sum;
}