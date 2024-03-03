// 백준 : 차집합 - 1822번

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(vector<int>& a, vector<int>& b, vector<int>& result) {
	int aidx = 0;
	int bidx = 0;
	// a,b 를 검사하면서 겹치지 않은 것은 result 에 복사
	while (true) {
		// a, b 를 전부 검사했으면 빠져나오기
		if (aidx > a.size() - 1) {
			break;
		}
		if (bidx > b.size() - 1) {
			break;
		}
		// a,b 의 요소가 같은 경우 result 에서 제외
		if (a.at(aidx) == b.at(bidx)) {
			aidx++;
			bidx++;
		}
		// a 의 요소가 b의 요소보다 작으면 b 의 요소보다 클 때까지는 a 의 요소가 b 에 안나옴
		// ==> a 의 요소를 result 에 복사
		else if (a.at(aidx) < b.at(bidx)) {
			result.push_back(a.at(aidx));
			aidx++;
		}
		// b 의 요소는 그냥 무시
		else {
			bidx++;
		}
	}
	// b 를 전부 검사했는데 a 의 요소가 남았으면 전부 result 에 복사
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
	// 순서에 맞게 정렬
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> result = vector<int>();
	solve(a, b, result);
	cout << result.size() <<"\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result.at(i) <<" ";
	}
}