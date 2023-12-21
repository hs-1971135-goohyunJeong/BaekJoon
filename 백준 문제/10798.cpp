#include <iostream>

using namespace std;

int main(void) {
	string str[5];
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (max <= str[i].length()) {
			max = str[i].length();
		}
	}
	for (int col = 0; col < max; col++) {
		for (int row = 0; row < 5; row++) {
			if (str[row].length() > col) {
				cout << str[row][col];
			}
		}
	}
	
}