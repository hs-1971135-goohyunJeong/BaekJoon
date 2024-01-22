// 상자넣기 - 1965번
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
// 아이디어 앞에 나온 상자들 중 자신보다 작은 상자를 고른 후 그 상자들 중 length (여기서는 넣은 상자의 개수)가 
// 가장 긴 것을 선택하여 그것에 +1 한 값을 자신의 length 로 삼는다. 
int dp(vector<int>& box, Node node[], int n) {
	node[0].value = box.at(0);
	node[0].length = 1;
	for (int i = 1; i < n; i++) {
		node[i].value = box.at(i);
		bool haveSmall = false;
		for (int j = i-1; j >= 0; j--) {
			if (node[i].value > box.at(j)) { // 상자가 작은지 부터 확인
				if (node[i].length < node[j].length + 1) { // 그중 가장 긴 것을 채택
					node[i].length = node[j].length + 1;
				}
				haveSmall = true;
			}
		}
		if (!haveSmall) { // 앞에 나온 것들 중에 자신 보다 작은게 없으면 length 는 1로 설정 
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