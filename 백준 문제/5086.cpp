#include <iostream>

using namespace std;

int main(void) {
	int first, second;
	int size = 0;
	string str[10000];
	while (true) {
		cin >> first >> second;
		if (first == 0 && second == 0) {
			break;
		}
		if (first % second == 0) {
			str[size] = "multiple";
		}
		else if (second % first == 0) {
			str[size] = "factor";
		}
		else {
			str[size] = "neither";
		}
		size++;
	}
	for (int i = 0; i < size; i++) {
		cout << str[i] << endl;
	}
}