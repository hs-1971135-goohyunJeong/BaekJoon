// 백준 : 가장 많은 글자 - 1371번

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int alpha[26] = { 0 };
	char tmp;
	while (cin.get(tmp)) {
		if (tmp < 'a' || tmp > 'z') {
			continue;
		}
		alpha[tmp - 'a'] += 1;
	}
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (max < alpha[i]) {
			max = alpha[i];
		}
	}
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == max) {
			char tmp = 'a' + i;
			cout << tmp;
		}
	}
}