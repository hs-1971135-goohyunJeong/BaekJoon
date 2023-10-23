// ������ - 1912��

#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int>& vec, int n) {
	int result = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur += vec.at(i);
		if (cur < 0) {
			cur = 0;
		}
		if (result < cur) {
			result = cur;
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
	int max = findMax(vec, n); 
	if (max <= 0) { // ��� ������ ������ ��쿡 max�� 0�� ��
		max = vec.at(0);
		for (int i = 0; i < n; i++) {
			if (max < vec.at(i)) {
				max = vec.at(i);
			}
		}
	}
	cout << max;
}