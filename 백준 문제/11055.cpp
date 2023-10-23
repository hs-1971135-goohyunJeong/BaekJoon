// ���� ū �����ϴ� �κ� ���� - 11055��
#include <iostream>
#include <vector>

using namespace std;

int dp(vector<int>& vec, int n) {
	vector<int> table;
	table.push_back(vec.at(0));
	for (int i = 1; i < n; i++) {
		int j = 0;
		int max = 0;
		// ������ ��ġ(i)�� �������� ������ ���� �͵� �� �ڽź��� �� �������� ���� ū ���� ����
		for (j = i; j >= 0; j--) {  
			if (vec.at(i) > vec.at(j)) { 
				if (max < table.at(j)) {
					max = table.at(j);
				}
			}
		}
		table.push_back(max + vec.at(i));
	}
	int result = table.at(0);
	for (int i = 1; i < n; i++) {
		if (result < table.at(i)) {
			result = table.at(i);
		}
	}
	return result;
}

int main(void) {
	int n = 0;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int item = 0;
		cin >> item;
		vec.push_back(item);
	}
	cout << dp(vec, n);
}