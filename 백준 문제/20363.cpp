// 당근 키우기 - 20363번

#include <iostream>

using namespace std;

// 둘중 더 큰 수를 더한 다음 작은수를 더하고, 작은 수의 10분의 1 만큼 더 더하면됨 
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