// 가장 큰 증가하는 부분 수열 - 11055번
#include <iostream>
#include <vector>

using namespace std;

int dp(vector<int>& vec, int n) {
	vector<int> table;
	table.push_back(vec.at(0));
	for (int i = 1; i < n; i++) {
		int j = 0;
		int max = 0;
		// 현재의 위치(i)를 기준으로 이전에 나온 것들 중 자신보다 더 작은것의 가장 큰 값을 선택
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