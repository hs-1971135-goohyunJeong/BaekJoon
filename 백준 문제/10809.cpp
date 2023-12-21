#include <iostream>

using namespace std;

int main(void) {
	string str;
	cin >> str;
	int arr[26] = { 0 };
	bool toggle[26];
	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
		toggle[i] = false;
	}
	for (int i = 0; i < str.length(); i++) {
		if (toggle[str[i] - 97] == false) {
			arr[str[i] - 97] = i;
			toggle[str[i] - 97] = true;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}