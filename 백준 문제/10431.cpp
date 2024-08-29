// 백준 : 줄세우기 - 10431번

#include <iostream>

using namespace std;

int order(int arr[]) {
	int step = 0;
	// i :  현재 바른 순서에 있는지 확인받는 학생을 의미
	for (int i = 1; i < 20; i++) {
		// j : 확인 받는 학생 보다 앞에 있는 학생을 의미
		for (int j = 0; j < i; j++) {
			// 현재 학생보다 앞에 있는 학생이 더 큰 경우
			if (arr[i] < arr[j]) {
				int tmp = arr[i];
				// 뒤로 한칸씩 밀림
				for (int k = i; k > j; k--) {
					arr[k] = arr[k-1];
					step++;
				}
				arr[j] = tmp;
			}
		}
	}
	return step;
}

void solve(int t) {
	int arr[20] = {0};
	int step = 0;
	for (int i = 0; i < 20; i++) {
		cin >> arr[i];
	}
	cout << t <<" " << order(arr)<<"\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int idx = 0;
		cin >> idx;
		solve(idx);
	}
}