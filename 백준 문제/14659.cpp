// ���� : �������������ϰ�Ȥ��� - 14659��

#include <iostream>
#include <vector>

using namespace std;

// �ڽź��� �� ���� ���� ������ end �ε����� �ø���
// �ڽź��� �� ū ���� ������ start �ε����� �ø�
// �� �� �� ū ���� ������ end-start-1(�� ������ ����?)�� �迭�� ����
// start �ε����� end �ε����� ������ �ΰ��� ����Ű�� ���� �����Ƿ� end ����
// �ε��� �� �� �ϳ��� ���� �����ϸ� end-start-1�� �迭�� ����
// �迭�� ����� ���� ���� ū ���� ����
int solve(vector<int>& height, vector<int>& table) {
	int start = 0;
	int end = 1;
	while (true) {
		if (start == end) {
			end++;
		}
		if (start > height.size() - 1 || end > height.size() - 1) {
			table.push_back(end - start-1);
			break;
		}
		if (height.at(start) > height.at(end)) {
			end++;
		}
		else {
			table.push_back(end - start-1);
			start++;
		}
	}
	int result = 0;
	for (int i = 0; i < table.size(); i++) {
		if (result < table.at(i)) {
			result = table.at(i);
		}
	}
	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	vector<int> height;
	vector<int> table;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		height.push_back(tmp);
	}
	cout << solve(height, table);
	
}