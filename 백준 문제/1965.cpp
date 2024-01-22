// ���ڳֱ� - 1965��
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	int value = 0;
	int length = 0;
};

int max(Node node[], int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (result < node[i].length) {
			result = node[i].length;
		}
	}
	return result;
}
// ���̵�� �տ� ���� ���ڵ� �� �ڽź��� ���� ���ڸ� �� �� �� ���ڵ� �� length (���⼭�� ���� ������ ����)�� 
// ���� �� ���� �����Ͽ� �װͿ� +1 �� ���� �ڽ��� length �� ��´�. 
int dp(vector<int>& box, Node node[], int n) {
	node[0].value = box.at(0);
	node[0].length = 1;
	for (int i = 1; i < n; i++) {
		node[i].value = box.at(i);
		bool haveSmall = false;
		for (int j = i-1; j >= 0; j--) {
			if (node[i].value > box.at(j)) { // ���ڰ� ������ ���� Ȯ��
				if (node[i].length < node[j].length + 1) { // ���� ���� �� ���� ä��
					node[i].length = node[j].length + 1;
				}
				haveSmall = true;
			}
		}
		if (!haveSmall) { // �տ� ���� �͵� �߿� �ڽ� ���� ������ ������ length �� 1�� ���� 
			node[i].length = 1;
		}
	}
	/*cout << "\n\n";
	for (int i = 0; i < n; i++) {
		cout << node[i].length << " ";
	}
	cout << "\n\n";*/
	return max(node, n);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> box;
	
	int n = 0;
	cin >> n;
	Node* node = new Node[n];
	for (int i = 0; i < n; i++) {
		int item = 0;
		cin >> item;
		box.push_back(item);
	}

	cout << dp(box, node, n);
}