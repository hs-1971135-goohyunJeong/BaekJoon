// 케빈 베이컨 - 1389번

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
	int val;
	vector<Node*> friends;
	int count = 0;
	int visit = INT16_MAX;
	bool canPush = true;
};

void makeLink(Node& nodeA, Node& nodeB) {
	for (int i = 0; i < nodeA.friends.size(); i++) {
		if (nodeA.friends.at(i) == &nodeB) {
			return;
		}
	}
	nodeA.friends.push_back(&nodeB);
	nodeB.friends.push_back(&nodeA);
}

void BFS(Node& start, vector<Node>& nodes) {
	queue<Node*> s;
	Node* cur;
	start.visit = 0;
	s.push(&start);
	while (!s.empty()) {
		cur = s.front();
		s.pop();
		bool canIncrease = true;
		for (int i = 0; i < cur->friends.size(); i++) {
			if (cur->friends.at(i)->visit == INT16_MAX) {
				s.push(cur->friends.at(i));
			}
			if (cur->visit+1 < cur->friends.at(i)->visit) {
				cur->friends.at(i)->visit = cur->visit + 1;
			}
			
		}
	}
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes.at(i).visit != INT16_MAX) {
			start.count += nodes.at(i).visit;
		}
	}
}
void DFS(Node& start, vector<Node>& nodes) {
	stack<Node*> s;
	Node* cur;
	start.visit = 0;
	s.push(&start);
	while (!s.empty()) {
		cur = s.top();
		s.pop();
		bool canIncrease = true;
		for (int i = 0; i < cur->friends.size(); i++) {
			if (cur->friends.at(i)->visit == INT16_MAX) {
				s.push(cur->friends.at(i));
			}
			if (cur->visit + 1 < cur->friends.at(i)->visit) {
				cur->friends.at(i)->visit = cur->visit + 1;
			}

		}
	}
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes.at(i).visit != INT16_MAX) {
			start.count += nodes.at(i).visit;
		}
	}
}

void clearVisit(vector<Node>& nodes) {
	for (int i = 0; i < nodes.size(); i++) {
		nodes.at(i).visit = INT16_MAX;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<Node> nodes;
	for (int i = 0; i < n; i++) {
		Node tmp;
		tmp.val = i + 1;
		nodes.push_back(tmp);
	}
	
	int x = 0, y = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		makeLink(nodes.at(x-1), nodes.at(y-1));
	}

	for (int i = 0; i < nodes.size(); i++) {
		DFS(nodes.at(i), nodes);
		clearVisit(nodes);
	}
	Node* min = &nodes.at(0);
	//for (int i = 0; i < nodes.size(); i++) {
	//	cout << nodes.at(i).count << " ";
	//}
	//cout << "\n";
	for (int i = 1; i < nodes.size(); i++) {
		if (min->count > nodes.at(i).count) {
			min = &nodes.at(i);
		}
	}
	cout << min->val;
}
