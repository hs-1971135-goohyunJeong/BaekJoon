// ���� : ������ ���� - 1252��

#include <iostream>
#include <vector>

using namespace std;

// �Ҽ��� �� �ڿ������� ������ �����ذ��鼭
// �Ѵ� 1 �̸� �� �ڸ����� 0������ �� ���� �ڸ����� 1�� �߰�������Ѵ�.
// �Ѵ� 0 �̸� �� �ڸ����� 0,
// �� ���� ���� �ڸ����� 1�̴�.
// �ٸ� �Ʒ� �ڸ����� 1�� �Ѱ�������� ���� �޶����Ƿ� �̸� üũ �ؾ��Ѵ�. (bool up �� ����)
void add(string& a, string& b, char c[]) {
	int aIndex = a.length() - 1;
	int bIndex = b.length() - 1;
	c[aIndex + 1] = '\0';
	bool up = false;
	while (true) {
		// ª�� ���� �Ҽ��� ���� �������� ���� Ż��
		if (bIndex < 0) {
			break;
		}
		if (a[aIndex] == '1' && b[bIndex] == '1') {
			if (up) {
				c[aIndex] = '1';
			}
			else {
				c[aIndex] = '0';
			}
			up = true;
		}
		else if (a[aIndex] == '0' && b[bIndex] == '0') {
			if (up) {
				c[aIndex] = '1';
			}
			else {
				c[aIndex] = '0';
			}
			up = false;
		}
		else {
			if (up) {
				c[aIndex] = '0';
				up = true;
			}
			else {
				c[aIndex] = '1';
				up = false;
			}
		}
		aIndex--;
		bIndex--;
	}
	while (aIndex >= 0) {
		if (up) { // ª�� ���� �������� up �� true �� �� ���� (ex : 11+1)
			if (a[aIndex] == '1') {
				c[aIndex] = '0';
			}
			else {
				c[aIndex] = '1';
				up = false;
			}
		}
		else {
			c[aIndex] = a[aIndex];
		}
		aIndex--;
	}
	// ����� 0�� �ƴ϶�� ��ó���� 1�� �����ؾ��� 
	bool start = true;
	for (int i = 0; c[i] != '\0'; i++) {
		// a �� ������ �ڸ��� �Ѿ�� 1�� ���� �� ���� (ex : 1 1)
		if (up) {
			cout << "1";
			up = false;
			start = false;
		}
		// 1�� �������� ������ ����
		if (c[i] == '0' && start) {
			continue;
		}
		cout << c[i];
		start = false;
	}
	// 1�� �ѹ��� �ȳ����� 0 ���
	if (start) {
		cout << "0";
	}
}
int main(void) {
	string a;
	string b;
	cin >> a >> b;
	string tmp;
	// a�� ������ �� �Ҽ��� �����ϵ��� �ٲ��� 
	if (a.length() < b.length()) {
		tmp = a;
		a = b;
		b = tmp;
	}
	// 80 �ڸ��� + 80 �ڸ��� �� ��� c �� 81�ڸ��� ��������
	char c[81] = "";
	add(a, b, c);
}