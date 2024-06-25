// 백준 : 성적 통계 - 5800번

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int k, int n) {
	int gap = 0;
	vector<int> vec;
	int max = 0;
	int min = INT16_MAX;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(tmp);
		if (max < tmp) {
			max = tmp;
		}
		if (min > tmp) {
			min = tmp;
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n - 1; i++) {
		tmp = vec.at(i + 1) - vec.at(i);
		if (gap < tmp) {
			gap = tmp;
		}
	}
	cout << "Class " << k << "\n";
	cout << "Max " << max << ", Min " << min << ", Largest gap " << gap <<"\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;
	int n = 0;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		solve(i + 1, n);
	}

}