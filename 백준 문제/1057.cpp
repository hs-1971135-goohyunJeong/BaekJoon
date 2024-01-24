// ��ʸ�Ʈ - 1057��
#include <iostream>

using namespace std;

int oddToEven(int a) {
	if (a % 2 == 1) {
		return a + 1;
	}
	return a;
}

int findRound(int a, int b) {
	int round = 1;
	while (true) {
		a = oddToEven(a); // 1,2,3,4 �� ��Ī�Ǵ� ���� 2,1,4,3 ���� ��Ī�Ǵ� �Ͱ� ���� 
		b = oddToEven(b);
		if (a == b) {
			break;
		}

		a /= 2;
		b /= 2;
		round++;
	}
	return round;
}

int main(void) {
	int n = 0;
	int a = 0;
	int b = 0;
	cin >> n >> a >> b;
	cout << findRound(a, b);
}