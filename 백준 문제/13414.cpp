// ���� : ������û - 13414��

#include <iostream>
#include <algorithm>

using namespace std;

// ���̵�� :
//  �й��� ������ ������ ������ �� �й��� ����
// -> ���ĵ� �й� �� �ߺ��� ���� ���� ���������� ���� �й��� ��� (bool ������ ���������� ���Դ��� üũ, ������ ������ �����)
// -> ���� ������� �� ����

class Node {
public:
	string id; // �й�
	int idx; // ���� ����
	bool isLast = true; // �ߺ��� �� �� ������ ������ ���Դ��� üũ 
};

bool compareString(const Node& a, const Node& b) {
	return a.id < b.id;
}
bool compareIdx(const Node& a, const Node& b) {
	return a.idx < b.idx;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;
	int l = 0;
	cin >> k >> l;
	Node node[500000];
	for (int i = 0; i < l; i++) {
		string tmp;
		cin >> tmp;
		node[i].id = tmp;
		node[i].idx = i;
	}
	stable_sort(node, node+l, compareString);
	for (int i = 0; i < l; i++) {
		if (i > 0 && node[i - 1].id.compare(node[i].id) == 0) {
			node[i - 1].isLast = false;
		}
	}
	sort(node, node+l, compareIdx);
	int j = 0;
	for (int i = 0; i < l; i++) {
		if (j >= k) {
			break;
		}
		if (!node[i].isLast) {
			continue;
		}
		cout << node[i].id << "\n";
		j++;
	}
}