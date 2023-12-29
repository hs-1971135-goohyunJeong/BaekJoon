#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	int tmp;
	int sumY = 0;
	int sumM = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sumY += (tmp / 30 + 1) * 10;
		sumM += (tmp / 60 + 1) * 15;
	}
	if (sumY < sumM) {
		cout << "Y " << sumY;
	}
	else if (sumY == sumM) {
		cout << "Y M " << sumY;
	}
	else {
		cout << "M " << sumM;
	}
}