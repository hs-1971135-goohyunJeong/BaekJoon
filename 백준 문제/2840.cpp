// ����� ���� - 2840��

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
		// ���ڿ� �ڸ��� ó�� ���ڰ� ���ų� �̹� ���� �ִ� ���ڿ� ���� ���
		if (str[s] == '?' || str[s] == ch) {
			str[s] = ch;
		}
		// �̹� ���ڰ� �� �ִµ�, �ٸ� ���ڰ� ������ �ϴ� ���
		else {
			cout << "!";
			return 0;
		}
		chStack.pop();
		// ������ ���ڰ� �����ϴ� �ڸ��� ã�� �κ�
		s = (s + sStack.top())%n;
		sStack.pop();

	}
	// ���� ���ڰ� �������� ���
	for (int i = 0; i < n; i++) {
		//if (str[i] != '?') { // ? �� ������ �� �� ����
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