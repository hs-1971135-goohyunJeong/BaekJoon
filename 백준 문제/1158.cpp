#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* insert(Node* front, int item) {
	Node* tmp = new Node();
	tmp->data = item;
	if (front == NULL) {
		tmp->pre = tmp;
		tmp->next = tmp;
		return tmp;
	}
	tmp->pre = front;
	tmp->next = front->next;
	front->next->pre = tmp;
	front->next = tmp;
	return tmp;
}
Node* deleteNode(Node* remove) {
	Node* tmp = remove->pre;
	tmp->next = remove->next;
	remove->next->pre = tmp;
	cout << remove->data;
	delete remove;
	return tmp;
}

Node* move(Node* cur, int count) {
	for (int i = 0; i < count; i++) {
		cur = cur->next;
	}
	return cur;
}

int main(void) {
	int n = 0;
	int k = 0;
	Node* list = NULL;
	Node* start = NULL;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		list = insert(list, i+1);
		if (i == 0) {
			start = list;
		}
	}
	cout << "<";
	start = start->pre;
	while (true) {
		start = move(start, k);
		if (start->next == start) {
			start = deleteNode(start);
			break;
		}
		start = deleteNode(start);
		
		cout << ", ";
	}
	cout << ">";
}