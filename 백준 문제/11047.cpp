// 동전 0 - 11047번

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// k보다 작지만 그 중에서는 가장 큰 금액부터 k에서 뺀다.
// 여기서 x 의 값으로 k 를 뺐으면 그 다음에는 x 의 값부터 k 보다 작은지 확인해서 뺀다. 
// (x에서 이미 뺐으면 x 보다 큰 애들은 어차피 k보다 큼) 

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