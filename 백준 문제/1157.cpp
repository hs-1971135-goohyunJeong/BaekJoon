#include <iostream>

using namespace std;

void changeSmall(string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 65 && str[i] <= 91) {
			str[i] = str[i] + 32;
		}
	}
}

void countAlp(string& str, int arr[]) {
	changeSmall(str);
	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - 97] += 1;
	}
}

void foundMostAlp(string& str, int arr[]) {
	int max = arr[0];
	int index = 0;
	countAlp(str, arr);
	for (int i = 0; i < 26; i++) {
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] == max && index != i) {
			cout << "?";
			return;
		}
	}
	cout << char(index+65);
}

int main(void) {
	string str;
	int arr[26] = { 0 };
	cin >> str;
	foundMostAlp(str, arr);
}