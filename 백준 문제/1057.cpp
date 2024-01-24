// 토너먼트 - 1057번
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
		a = oddToEven(a); // 1,2,3,4 가 매칭되는 것은 2,1,4,3 으로 매칭되는 것과 같음 
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