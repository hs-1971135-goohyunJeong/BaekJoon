// ���� : ������ - 1822��

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(vector<int>& a, vector<int>& b, vector<int>& result) {
	int aidx = 0;
	int bidx = 0;
	// a,b �� �˻��ϸ鼭 ��ġ�� ���� ���� result �� ����
	while (true) {
		// a, b �� ���� �˻������� ����������
		if (aidx > a.size() - 1) {
			break;
		}
		if (bidx > b.size() - 1) {
			break;
		}
		// a,b �� ��Ұ� ���� ��� result ���� ����
		if (a.at(aidx) == b.at(bidx)) {
			aidx++;
			bidx++;
		}
		// a �� ��Ұ� b�� ��Һ��� ������ b �� ��Һ��� Ŭ �������� a �� ��Ұ� b �� �ȳ���
		// ==> a �� ��Ҹ� result �� ����
		else if (a.at(aidx) < b.at(bidx)) {
			result.push_back(a.at(aidx));
			aidx++;
		}
		// b �� ��Ҵ� �׳� ����
		else {
			bidx++;
		}
	}
	// b �� ���� �˻��ߴµ� a �� ��Ұ� �������� ���� result �� ����
	while (aidx <= a.size() - 1) {
		result.push_back(a.at(aidx));
		aidx++;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	vector<int> a = vector<int>();
	vector<int> b = vector<int>();

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int j = 0; j < m; j++) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	// ������ �°� ����
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> result = vector<int>();
	solve(a, b, result);
	cout << result.size() <<"\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result.at(i) <<" ";
	}
}