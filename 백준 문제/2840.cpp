// 행운의 바퀴 - 2840번

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	int n = 0, k = 0;
	cin >> n >> k;
	stack <int> sStack;
	stack <char> chStack;
	int check[27] = { 0 };
	char str[25];

	for (int i = 0; i < n; i++) {
		str[i] = '?';
	}
	for (int i = 0; i < k; i++) {
		int s = 0;
		char ch;
		cin >> s >> ch;
		sStack.push(s);
		chStack.push(ch);
	}
	int s = 0;
	while (true) {
		if (sStack.empty() || chStack.empty()) {
			break;
		}
		char ch = chStack.top();
		// 문자열 자리에 처음 문자가 들어가거나 이미 들어와 있는 문자와 같은 경우
		if (str[s] == '?' || str[s] == ch) {
			str[s] = ch;
		}
		// 이미 문자가 들어가 있는데, 다른 문자가 들어가려고 하는 경우
		else {
			cout << "!";
			return 0;
		}
		chStack.pop();
		// 다음에 문자가 들어가야하는 자리를 찾는 부분
		s = (s + sStack.top())%n;
		sStack.pop();

	}
	// 같은 문자가 여러개인 경우
	for (int i = 0; i < n; i++) {
		//if (str[i] != '?') { // ? 는 여러개 일 수 있음
		//	check[str[i] - 'A']++;
		//	if (check[str[i] - 'A'] > 1) {
		//		cout << "!";
		//		return 0;
		//	}
		//}
		check[str[i] - 'A']++;
		//cout << str[i] - 'A';
		if (check[str[i] - 'A'] > 1) {
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << str[i];
	}

}