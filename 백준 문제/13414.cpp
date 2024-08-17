// 백준 : 수강신청 - 13414번

#include <iostream>
#include <algorithm>

using namespace std;

// 아이디어 :
//  학번이 들어오는 순서를 저장한 뒤 학번을 정렬
// -> 정렬된 학번 중 중복된 것은 가장 마지막으로 들어온 학번만 사용 (bool 변수로 마지막으로 들어왔는지 체크, 안정된 정렬을 써야함)
// -> 들어온 순서대로 재 정렬

class Node {
public:
	string id; // 학번
	int idx; // 들어온 순서
	bool isLast = true; // 중복된 것 중 마지막 순서로 들어왔는지 체크 
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