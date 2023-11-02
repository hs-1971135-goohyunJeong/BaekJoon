// Yonsei TOTO - 12018��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>* apply = new vector<int>[n];
	// �����ڵ��� ���� ���ϸ��� �� ĿƮ���� Ȥ�� ���� �־���� ���ϸ���
	vector<int> minMilege = vector<int>();
	int p = 0, l = 0;
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		for (int j = 0; j < p; j++) {
			int tmp = 0;
			cin >> tmp;
			apply[i].push_back(tmp);
		}
		// �����ڵ� ���ϸ����� ����
		sort(apply[i].begin(), apply[i].end());
		// ������ �� - ���� �� = ĿƮ���� ������
		int index = p - l;
		// index �� ������ ���� �̴��̹Ƿ� ���ϸ��� 1�� �־ ��
		if (index < 0) {
			minMilege.push_back(1);
		}
		// �ٸ� �����ڰ� ���ϸ����� ������ �־ ���ϸ��� 1 �̻� �־����
		else if (apply[i].at(index) <= 0) {
			minMilege.push_back(1);
		}
		// ĿƮ���� �������� ���ϸ���
		else {
			minMilege.push_back(apply[i].at(index));
		}
	}
	// �ִ��� ���� ������ ��� ������ ����
	sort(minMilege.begin(), minMilege.end());
	int count = 0;
	for (int i = 0; i < minMilege.size(); i++) {
		// ���ϸ����� �� ���� ������ ���¼� ����
		if ((m = m - minMilege.at(i)) >= 0) {
			count++;
		}
		else {
			break;
		}
	}
	cout << count;
}