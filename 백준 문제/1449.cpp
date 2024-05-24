// ���� : ������ �׽� - 1449��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �������� ���� ���� ����ϴ� ����� ��ġ�� �ʴ� ����
// ���ۿ� �������� �ٿ��� �� �� ������ �ƴѵ��� �������� �������� ������ �ǳʶ�
void solve(vector<int>& pos, int n, int l) {
	sort(pos.begin(), pos.end());
	int window = pos.at(0)+l-1;
	int count = 1;
	for (int i = 1; i < n; i++) {
		int cur = pos.at(i);
		if (cur > window) {
			window = cur + l-1;
			count++;
		}
	}
	cout << count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, l = 0;
	cin >> n >> l;
	vector<int> pos = vector<int>();
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		pos.push_back(tmp);
	}
	solve(pos, n, l);

}