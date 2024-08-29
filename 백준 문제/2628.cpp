// ���� : �����ڸ��� - 2628��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ū ������ ���� �簢�� => �������� ���̸� �ڸ��� ������ �ʺ�� ���̰� ���� ���.

// ���� �� ���̸� ��� �Լ� (���̴� �ʺ��)
int calc(vector<int>& vec) {
	int max = 0;
	for (int i = 1; i < vec.size(); i++) {
		int offset = 0;
		offset = vec.at(i) - vec.at(i - 1);
		if (max < offset) {
			max = offset;
		}
	}
	return max;
}
// ���� ū �ʺ�� ���̸� ���ϴ� �Լ�
void solve(vector<int>& cx, vector<int>& cy) {
	int maxX = 0;
	int maxY = 0;
	maxX = calc(cx);
	maxY = calc(cy);
	cout << maxX * maxY;
	

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x= 0;
	int y = 0;
	int count = 0;
	// �ڸ��� ��ġ�� ���� �ϴ� ����
	vector<int> cx;
	vector<int> cy;
	cin >> x >> y;
	cin >> count;
	cx.push_back(0);
	cy.push_back(0);
	for (int i = 0; i < count; i++) {
		int direct = 0;
		int tmp = 0;
		cin >> direct >> tmp;
		// �ڸ��� ����� �ڸ��� ��ġ�� �ݴ��̴�. ���η� �ڸ��� ��� ������ ��ġ�� �����ؾ���
		if (direct == 0) {
			cy.push_back(tmp);
		}
		else {
			cx.push_back(tmp);
		}
	}
	cx.push_back(x);
	cy.push_back(y);

	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());

	solve(cx, cy);
}