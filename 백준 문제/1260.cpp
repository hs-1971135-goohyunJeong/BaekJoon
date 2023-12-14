 // DFS¿Í BFS - 1260¹ø 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Node {
	int val;
	bool visit;
	vector<Node*> link;
};
void makeLink(Node& nodeA, Node& nodeB) {
	nodeA.link.push_back(&nodeB);
	nodeB.link.push_back(&nodeA);
}
void DFS(Node& node) {
	stack<Node*> s;
	s.push(&node);
	Node* cur;
	while (!s.empty()) {
		cur = s.top();
		s.pop();
		if (cur->visit == false) {
			cout << cur->val << " ";
			cur->visit = true;
			for (int i = 0; i < cur->link.size(); i++) {
				s.push(cur->link.at(i));
			}
		}
	}

}

void BFS(Node& node) {
	queue<Node*> q;
	q.push(&node);
	node.visit = true;
	Node* cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		cout << cur->val << " ";
		for (int i = 0; i < cur->link.size(); i++) {
			if (cur->link.at(i)->visit == true) {
				continue;
			}
			q.push(cur->link.at(i));
			cur->link.at(i)->visit = true;
		}
	}

}
bool compare(Node* a, Node* b) {
	return a->val > b->val;
}

int main(void) {
	int n = 0, m = 0, v = 0;
	cin >> n >> m >> v;
	int x = 0, y = 0;
	vector<Node> nodes;
	for (int i = 0; i < n; i++) {
		Node tmp;
		tmp.val = i + 1;
		tmp.visit = false;
		nodes.push_back(tmp);
	}
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		makeLink(nodes.at(x - 1), nodes.at(y - 1));
	}

	for (int i = 0; i < n; i++) {
		sort(nodes.at(i).link.begin(), nodes.at(i).link.end(), compare);
	}

	DFS(nodes.at(v - 1));
	cout << "\n";
	for (int i = 0; i < n; i++) {
		nodes.at(i).visit = false;
		sort(nodes.at(i).link.begin(), nodes.at(i).link.end());
	}
	
	BFS(nodes.at(v - 1));
}
