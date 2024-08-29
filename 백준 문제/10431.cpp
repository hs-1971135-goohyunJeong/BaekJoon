// ���� : �ټ���� - 10431��

#include <iostream>

using namespace std;

int order(int arr[]) {
	int step = 0;
	// i :  ���� �ٸ� ������ �ִ��� Ȯ�ι޴� �л��� �ǹ�
	for (int i = 1; i < 20; i++) {
		// j : Ȯ�� �޴� �л� ���� �տ� �ִ� �л��� �ǹ�
		for (int j = 0; j < i; j++) {
			// ���� �л����� �տ� �ִ� �л��� �� ū ���
			if (arr[i] < arr[j]) {
				int tmp = arr[i];
				// �ڷ� ��ĭ�� �и�
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