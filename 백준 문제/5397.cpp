#include <iostream>

using namespace std;

typedef struct Node {
	char data;
	struct Node* pre;
	struct Node* next;
}Node;

typedef struct Head {
	struct Node* start;
}Head;

Node* insert(Node* front, char item) {
	Node* tmp = new Node();
	tmp->data = item;
	tmp->pre = front;
	tmp->next = front->next;
	if (front->next != NULL && front->next->pre != NULL) {
		front->next->pre = tmp;
	}
	front->next = tmp;
	return tmp;
}

Node* deleteNode(Node* remove) {
	Node* tmp = remove->pre;
	tmp->next = remove->next;
	if (remove->next != NULL && remove->next->pre != NULL) {
		remove->next->pre = tmp;
	}
	return tmp;
}

Node* moveLeft(Node* cur) {
	if (cur->pre != NULL) {
		cur = cur->pre;
	}
	return cur;
}
Node* moveRight(Node* cur) {
	if (cur->next != NULL && cur->next->pre != NULL) {
		cur = cur->next;
	}
	return cur;
}

void iter(Node* cur) {
	
	while (cur->pre != NULL && cur->data != NULL) {
		cout << cur->data;
		cur = cur->next;
	}
	cout << "\n";
}

int main(void) {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Node* cur = new Node();
		Head* head = new Head();
		head->start = cur;
		cur->pre = NULL;
		cur->next = cur;
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			switch (str[j]) {
			case '<':
				if (cur != NULL) {
					cur = moveLeft(cur);
				}
				break;
			case '>':
				if (cur != NULL) {
					cur = moveRight(cur);
				}
				break;
			case '-':
				if (cur != NULL && cur->pre != NULL) {
					cur = deleteNode(cur);
				}
				break;
			default:
				if (cur != NULL) {
					cur = insert(cur, str[j]);
				}
				break;
			}
		}
		if (cur != NULL) {
			iter(head->start->next);
		}
		delete cur;
		delete head;

	}
}