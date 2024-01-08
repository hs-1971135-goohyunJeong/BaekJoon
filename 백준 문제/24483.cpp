// 알고리즘 수업 - 깊이 우선 탐색 5 - 24483번

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>


using namespace std;

struct Node {
	int value = 0;
	vector<Node*> link;
	long long dept = LLONG_MAX;
	long long order = LLONG_MAX;
	bool isPop = false;
};

void setLink(vector<Node>& nodes, int a, int b) {
	nodes[a - 1].link.push_back(&nodes[b - 1]);
	nodes[b - 1].link.push_back(&nodes[a - 1]);
}

bool compare(Node* a, Node* b) {
	return a->value > b->value;
}

void dfs(vector<Node>& nodes, int r) {
	stack<Node*> s;
	nodes[r - 1].dept = 0;
	s.push(&nodes[r - 1]);
	int order = 0;

	while (!s.empty()) {
		Node& cur = *(s.top());
		s.pop();
		if (cur.isPop) { // 여러번 스택에 들어간 정점이 있으면 한번만 pop하도록 조정
			continue;
		}
		cur.isPop = true;
		order++;
		cur.order = order;
		sort(cur.link.begin(), cur.link.end(), compare);
		for (int i = 0; i < cur.link.size(); i++) {
			if (cur.link[i]->order <= cur.order) {
				continue;
			}

			s.push(cur.link[i]);
			cur.link[i]->dept = cur.dept + 1;
		}
		
	}
}

long long calc(vector<Node>& nodes, int n) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (nodes[i].dept == LLONG_MAX) {
			nodes[i].dept = 0;
		}
		sum += (nodes[i].dept * nodes[i].order);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0, r = 0;
	cin >> n >> m >> r;
	vector<Node> nodes;
	for (int i = 0; i < n; i++) {
		Node tmp = Node();
		tmp.value = i + 1;
		nodes.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		int a = 0; int b = 0;
		cin >> a >> b;
		setLink(nodes, a, b);
	}
	dfs(nodes, r);

	long long sum = calc(nodes, n);
	cout << sum;
}