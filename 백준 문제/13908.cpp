// 비밀번호 - 13908번

#include <iostream>
#include <vector>
using namespace std;


// 쓰이지 않은 hint 가 있는지 확인
bool checkHint(bool hint[]) {
	for (int i = 0; i < 10; i++) {
		if (hint[i] == true) {
			return false;
		}
	}
	return true;
}

void backTracking(int n, bool hint[], int idx, int& sum) {
	if (idx == n) {
		if (checkHint(hint)) {
			sum += 1;
		}
		return ;
	}
	// hint 를 바꿨으면 다시 원상복귀를 시키고 다음 것을 조사해야함
	bool isChange = false;
	for (int i = 0; i < 10; i++) {
		if (hint[i] == true) {
			hint[i] = false;
			isChange = true;
		}
		backTracking(n, hint, idx + 1, sum);
		if (isChange) {
			hint[i] = true;
			isChange = false;
		}
	}
}

int main(void) {
	int n = 0, m = 0;
	bool hint[10];
	for (int i = 0; i < 10; i++) {
		hint[i] = false;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int idx = 0;
		cin >> idx;
		hint[idx] = true;
	}
	int sum = 0;
	backTracking(n, hint, 0, sum);
	cout << sum;
}