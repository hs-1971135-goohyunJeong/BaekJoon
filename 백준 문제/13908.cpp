// ��й�ȣ - 13908��

#include <iostream>
#include <vector>
using namespace std;


// ������ ���� hint �� �ִ��� Ȯ��
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
	// hint �� �ٲ����� �ٽ� ���󺹱͸� ��Ű�� ���� ���� �����ؾ���
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