#include <iostream>

using namespace std;

void printLine(int m) {
	for (int i = 0; i < m; i++) {
		cout << "____";
	}
}
void print(int n, int count) {
	if (n == 0) {
		printLine(count);
		cout << "\"����Լ��� ������?\"\n";
		printLine(count);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		printLine(count);
		cout << "��� �亯�Ͽ���.\n";
		return;
	}
	printLine(count);
	cout << "\"����Լ��� ������?\"\n";
	printLine(count);
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	printLine(count);
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	printLine(count);
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	print(n - 1, count+1);
	printLine(count);
	cout << "��� �亯�Ͽ���.\n";
	
}

int main(void) {
	int n = 0;
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	print(n, 0);
}