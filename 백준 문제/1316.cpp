#include <iostream>
#include <string>

using namespace std;

bool check(string str) {
	bool divide = true;
	for (int i = 1; i < str.length(); i++) {
		if (str[i] != str[i - 1]) {
			for (int j = 0; j < i; j++) {
				if (str[i] == str[j]) {
					return false;
				}
			}
		}
	}
	return true;
}

int main(void) {
	int n = 0;
	int count = 0;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		if (check(str)) {
			count++;
		}
	}
	cout << count;
}