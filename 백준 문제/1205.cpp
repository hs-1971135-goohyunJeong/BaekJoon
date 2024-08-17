// ���� : ��� ���ϱ� - 1205��

#include <iostream>
#include <vector>
using namespace std;

// ������ ������������ �־����� ���ο� ������ ���� ��ŷ�� ������ ������ ��쿡�� 
// ���ο� ������ �� ���� ��ŷ�� �Ű�����. ��, ��ŷ�� ���� �ִ� ���� ���� ��ŷ �������� ���ƾ� ��ŷ�� �Ű�����.
// 
int findRanking(vector<int>& list, int p, int score) {
	int result = 1;
	// ��ŷ�� �ƹ��͵� ���� ���� ������ 1����
	if (list.size() == 0) {
		return 1;
	}
	// ��ŷ�� ��� �ִ� �������� �۰ų� ������ ��ŷ�� ���� ���Ѵ�. 
	// => ���� ���� ��ŷ ������ p��° ���� �̹Ƿ� p ���� Ŀ�� ��ŷ�� ��� ����
	if (list.size() >= p && score <= list.at(p-1)) {
		return -1;
	}
	// ���� ��츦 �����ϸ� ��ŷ�� �� �� �ִ� ������ �ش�Ǹ鼭 ������ ��� �� ���� ��ŷ�� �Ű���
	for (int i = 0; i < list.size(); i++) {
		if (score >= list.at(i)) {
			break;
		}
		result++;
	}

	return result;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	int p = 0;
	int score = 0;
	vector<int> list;
	cin >> n >> score >> p;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		list.push_back(tmp);
	}
	cout << findRanking(list, p, score);
}