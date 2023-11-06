// Project Teams - 20044��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ�� ���� : �����ϰ� ���� ¥���� ���� ������ ���� �ֿ� ���� ������ ���� �ָ� ���� ���� �־����
int main(void) {
	int n = 0;
	cin >> n;
	vector<int> scores;
	// ������ �θ��� ������ ���� ���� �����ϴ� ����
	vector<int> teamScores;
	int tmp = 0;
	for (int i = 0; i < 2 * n; i++) {
		cin >> tmp;
		scores.push_back(tmp);
	}
	// ������ ����
	sort(scores.begin(), scores.end());
	// ���� ������ ������ �Է�
	for (int i = 0; i < n; i++) {
		teamScores.push_back(scores.at(i));
	}
	int j = 0;
	// ���� ���� ������ ���� ���� �ָ� ��Ī�ذ��鼭 �������� �߰������� �θ��� ��Ī�ؾ���
	for (int i = 2 * n - 1; i >= n; i--) {
		teamScores[j] = teamScores[j]+scores[i];
		j++;
	}
	// �� ������ ����
	sort(teamScores.begin(), teamScores.end());
	cout << teamScores.at(0);
	return 0;
}