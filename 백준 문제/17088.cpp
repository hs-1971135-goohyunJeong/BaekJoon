// �������� ��ȯ - 17088��
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// k �� ���° �׿� ������ ���ϴ����� �ǹ��ϰ� c �� ����Ƚ���� �ǹ���
void backTracking(vector<int>& vec, vector<int>& count, int k, int c) {
	// ���� ���ϱ�
	int gap = vec.at(0) - vec.at(1);
	if (k > 1) {
		// k-2 �� k-1 �� ���Ͽ� �� ���� ���� ������ �ٸ��� �� ������ �ʿ� ����
		// k-2 �� k-1 �� ���ϴ� ������ k �� k-1/ k �� k+1 �� ���ϸ� �ȵǱ� ���� 
		// (k �� ���� ������ ���ϱ� ���̱� ������ k �� ������ �񱳸� �ϸ� return �� �����)  
		if (vec.at(k-2) != vec.at(k -1) + gap) {
			return;
		}
	}
	// ��� ������ ���� �����ϸ� �� ���� ����Ƚ���� ����
	if (k == vec.size()) {
		count.push_back(c);
		return;
	}
	// �ƹ��͵� �ȹٲ��� ��
	backTracking(vec, count, k + 1, c);

	// 1 �� ������ ��
	vec.at(k) = vec.at(k) + 1;
	backTracking(vec, count, k + 1, c + 1);

	vec.at(k) = vec.at(k) - 1;
	// 1 �� ���� ��
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
	// ������ ������ ����
	vector<int> vec = vector<int>();
	// ���������� ���鶧 �󸶳� ������ �ʿ����� �����ϴ� ����
	vector<int> count = vector<int>();
	while (n--) {
		int tmp = 0;
		cin >> tmp;
		vec.push_back(tmp);
	}
	// ������ ������ 2�� ���ϸ� ������ ���� ������
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