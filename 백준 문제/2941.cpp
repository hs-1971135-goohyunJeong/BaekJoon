#include <iostream>
#include <string>

using namespace std;

int calc(string str) {
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'c') {
			if (str[i + 1] == '-' || str[i + 1] == '=') {
				count++;
				i++;
				continue;
			}
		}
		else if (str[i] == 'd') {
			if (str[i + 1] == 'z') {
				if (str[i + 2] == '=') {
					count++;
					i += 2;
					continue;
				}
			}
			else if (str[i + 1] == '-') {
				count++;
				i++;
				continue;
			}
		}
		else if (str[i] == 'l' || str[i] == 'n') {
			if (str[i + 1] == 'j') {
				count++;
				i++;
				continue;
			}
		}
		else if (str[i] == 's' || str[i] == 'z') {
			if (str[i + 1] == '=') {
				count++;
				i++;
				continue;
			}
		}
		count++;
	}
	return count;
}

int main(void) {
	string str;
	getline(cin, str);
	cout << calc(str);
}