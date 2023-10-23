// 등차수열 변환 - 17088번
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// k 는 몇번째 항에 연산을 가하는지를 의미하고 c 는 연산횟수를 의미함
void backTracking(vector<int>& vec, vector<int>& count, int k, int c) {
	// 공차 구하기
	int gap = vec.at(0) - vec.at(1);
	if (k > 1) {
		// k-2 와 k-1 을 비교하여 두 수의 차가 공차와 다르면 더 조사할 필요 없음
		// k-2 와 k-1 을 비교하는 이유는 k 와 k-1/ k 와 k+1 을 비교하면 안되기 때문 
		// (k 는 아직 연산을 가하기 전이기 때문에 k 를 가지고 비교를 하면 return 이 실행됨)  
		if (vec.at(k-2) != vec.at(k -1) + gap) {
			return;
		}
	}
	// 모든 수열의 차가 일정하면 그 때의 연산횟수를 저장
	if (k == vec.size()) {
		count.push_back(c);
		return;
	}
	// 아무것도 안바꿨을 때
	backTracking(vec, count, k + 1, c);

	// 1 을 더했을 때
	vec.at(k) = vec.at(k) + 1;
	backTracking(vec, count, k + 1, c + 1);

	vec.at(k) = vec.at(k) - 1;
	// 1 을 뺐을 때
	vec.at(k) = vec.at(k) - 1;
	backTracking(vec, count, k + 1, c + 1);
	vec.at(k) = vec.at(k) + 1;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	int m = n;
	// 수열을 저장할 벡터
	vector<int> vec = vector<int>();
	// 등차수열로 만들때 얼마나 연산이 필요한지 저장하는 벡터
	vector<int> count = vector<int>();
	while (n--) {
		int tmp = 0;
		cin >> tmp;
		vec.push_back(tmp);
	}
	// 수열의 개수가 2개 이하면 무조건 등차 수열임
	if (m < 3) {
		cout << 0;
		return 0;
	}
	backTracking(vec, count, 0, 0);
	if (count.empty()) {
		cout << -1;
		return 0;
	}
	sort(count.begin(), count.end());
	cout << count.front();
}