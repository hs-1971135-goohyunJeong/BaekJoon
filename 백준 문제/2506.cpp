// ���� : �������-2506��
#include <iostream>

using namespace std;

// �տ� ������ ������ ������ ���� ������ prev�� 1�� ���ϰ� prev�� ������ ���Ѵ�.
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	int score = 0; //����
	int prev = 0; //������ ���� ����
	for (int i = 0; i < n; i++) {
		int input = 0;
		cin >> input;
		if (input) { // �¾��� ��
			prev += 1;
			score += prev;
		}
		else { // Ʋ���� ��
			prev = 0;
		}
	}
	cout << score;
}