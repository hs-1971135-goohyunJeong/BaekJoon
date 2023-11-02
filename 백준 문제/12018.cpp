// Yonsei TOTO - 12018번

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>* apply = new vector<int>[n];
	// 지원자들이 넣은 마일리지 중 커트라인 혹은 내가 넣어야할 마일리지
	vector<int> minMilege = vector<int>();
	int p = 0, l = 0;
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		for (int j = 0; j < p; j++) {
			int tmp = 0;
			cin >> tmp;
			apply[i].push_back(tmp);
		}
		// 지원자들 마일리지를 정렬
		sort(apply[i].begin(), apply[i].end());
		// 지원자 수 - 정원 수 = 커트라인 지원자
		int index = p - l;
		// index 가 음수면 정원 미달이므로 마일리지 1만 넣어도 됨
		if (index < 0) {
			minMilege.push_back(1);
		}
		// 다른 지원자가 마일리지를 음수로 넣어도 마일리지 1 이상 넣어야함
		else if (apply[i].at(index) <= 0) {
			minMilege.push_back(1);
		}
		// 커트라인 지원자의 마일리지
		else {
			minMilege.push_back(apply[i].at(index));
		}
	}
	// 최대한 많은 수업을 듣고 싶으니 정렬
	sort(minMilege.begin(), minMilege.end());
	int count = 0;
	for (int i = 0; i < minMilege.size(); i++) {
		// 마일리지가 다 고갈될 때까지 강좌수 증가
		if ((m = m - minMilege.at(i)) >= 0) {
			count++;
		}
		else {
			break;
		}
	}
	cout << count;
}