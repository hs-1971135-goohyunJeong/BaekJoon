//백준 : 영수증-5565번
#include <iostream>

using namespace std;

int main(void) {
	int totalPrice = 0;
	cin >> totalPrice;
	for (int i = 0; i < 9; i++) {
		int price = 0;
		cin >> price;
		totalPrice -= price;
	}
	cout << totalPrice;
}