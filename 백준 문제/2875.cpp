// ���� : ��ȸ or ���� - 2875��
#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	int m = 0;
	int k = 0;
	int team = 0; // ���� ��
	int rest = 0; //���� ���� �л�
	cin >> n >> m >> k;
	team = n / 2; // ���л� 2�� 1���� ���� �ٸ���
	rest = n % 2; // 2�� 1���� ���Ծȵ� �л� : 0�� Ȥ�� 1��
	if (team > m) { // ���л��� ������ ���
		rest += 2*(team - m); // ���л��� ���� ���� ��ü
		team = m; // ���л� ����ŭ ���� �������
	}
	else {
		rest += m - team;
	}
	if (k > rest) {
		k -= rest;
		while (k > 0) {
			team--;
			k -= 3;
		}
	}
	cout << team;
}