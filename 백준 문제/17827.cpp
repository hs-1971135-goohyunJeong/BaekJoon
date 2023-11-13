// 달팽이 리스트 - 17827번

#include <iostream>
#include <vector>
using namespace std;


int answer(vector<int>& vec, int tmp, int n, int v) {
	
	// count = 움직여야 하는 횟수 -> 인덱스로 표현
	int count = tmp;
	// count 가 n-1보다 크면 반복되는 부분에서만 숫자가 돌음
	if (count > n - 1) {
		// 한 바퀴는 제대로 돌아야함
		count -= n;
		// 반복되는 부분 처리 
		count = count % (n - v+1);
		
		// 반복되지 않는 부분은 나오지 않음 그 부분 처리
		count += (v-1);
	}

	
	return vec.at(count);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0, v = 0;
	cin >> n >> m >> v;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		vec.push_back(tmp);
	}
	// 질문을 받고 답하는 부분
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		cin >> tmp;
		cout  << answer(vec, tmp, n, v) << "\n";
	}
	
}