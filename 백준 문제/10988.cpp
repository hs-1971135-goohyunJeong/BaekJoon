#include <iostream>
#include <string>
using namespace std;

int divide(string str) {
	int i = 0;
	int j = str.length()-1;
	for (i = 0; i < str.length(); i++) {
		if (str[i] != str[j]) {
			return 0;
		}
		j--;
	}
	return 1;
}

int main(void) {
	string str;
	getline(cin, str);
	cout << divide(str);
}