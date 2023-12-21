#include <iostream>

using namespace std;

int main() {
	int totalPrice;
	int totalKind;
	int price;
	int count;

	int savePrice = 0;
	cin >> totalPrice;
	cin >> totalKind;
	for (int i = 0; i < totalKind; i++) {
		cin >> price >> count;
		savePrice += price * count;
	}
	if (savePrice == totalPrice) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}