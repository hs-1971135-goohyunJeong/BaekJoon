// ��� Ű��� - 20363��

#include <iostream>

using namespace std;

// ���� �� ū ���� ���� ���� �������� ���ϰ�, ���� ���� 10���� 1 ��ŭ �� ���ϸ�� 
int main(void) {
	long long x = 0, y = 0;
	cin >> x >> y;
	long long sum = 0;
	if (x > y) {
		sum = x;
		sum += y;
		sum = sum + y / 10;
	}
	else {
		sum = y;
		sum += x;
		sum = sum + x / 10;
	}
	
	cout << sum;
}