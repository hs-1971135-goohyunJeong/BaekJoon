// 백준 : 유학 금지 - 2789번

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char str[100];
	char ban[] = { 'C','A','M','B','R','I','D','G','E' };
	
	bool isBreak = false;
	cin >> str;
	for (int i = 0; str[i] != '\0'; i++) {
		isBreak = false;
		for (int j = 0; j < sizeof(ban) / sizeof(char); j++) {
			if (str[i] == ban[j]) {
				isBreak = true;
				break;
			}
		}
		if (isBreak) {
			continue;
		}
		cout << str[i];
	}

}