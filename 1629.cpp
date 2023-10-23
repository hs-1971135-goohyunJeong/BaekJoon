// °ö¼À 1629¹ø

#include <iostream>

using namespace std;

long long recursion(long long a, long long b, long long c) {
	if (b == 1) {
		return a % c;
	}
	long long mod = recursion(a, b / 2, c);
	mod = mod * mod % c;
	if (b % 2 == 0) {
		return mod;
	}
	else {
		return mod * a % c;
	}
}

int main(void) {
	long a = 0, b = 0, c = 0;
	cin >> a >> b >> c;	
	cout << recursion(a, b, c);

}