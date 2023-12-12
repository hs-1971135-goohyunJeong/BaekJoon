// ���� 0 - 11047��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// k���� ������ �� �߿����� ���� ū �ݾ׺��� k���� ����.
// ���⼭ x �� ������ k �� ������ �� �������� x �� ������ k ���� ������ Ȯ���ؼ� ����. 
// (x���� �̹� ������ x ���� ū �ֵ��� ������ k���� ŭ) 

int getCount(vector<int> coins, int k) {
	int idx = 0;
	int start = coins.size()-1;
	int count = 0;
	while (true) {
		if (k == 0) {
			break;
		}
		for (idx = start; idx >= 0; idx--) {
			if (coins.at(idx) <= k) {
				k -= coins.at(idx);
				start = idx;
				count++;
				break;
			}
		}
	}
	return count;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> coins;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp > k) {
			continue;
		}
		coins.push_back(tmp);
	}
	cout << getCount(coins, k);
}