// 하노이 탑 이동순서 11729번

#include <iostream>
#include <cmath>

using namespace std;

void moveTo(int a, int b, int n) {
	if (n == 1) {
		cout << a << " " << b << "\n";
		return;
	}
	moveTo(a, 6 - (a + b), n - 1);
	cout << a << " " << b <<"\n";
	moveTo(6 - (a + b), b, n-1);
}

int main(void) {
	int n = 0;
	cin >> n;
	cout << int(pow(2,n))-1 << "\n";
	moveTo(1, 3, n);
}