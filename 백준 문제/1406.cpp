#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
	char data;
	struct Node* pre;
	struct Node* next;
}Node;

typedef struct Head {
	struct Node* start;
};

void init(Head* head) {
	head->start = NULL;
}
Node* insert(Node* front, char item) {
	Node* tmp = new Node();
	tmp->data = item;
	tmp->pre = front;
	tmp->next = front->next;
	front->next->pre = tmp;
	front->next = tmp;
	
	return tmp;
}

Node* deleteNode(Node* remove, Head* head) {
	Node* tmp = remove;
	remove->pre->next = tmp->next;
	if (remove->next != head->start) {
		remove->next->pre = tmp->pre;
	}
	tmp = remove->pre;
	delete remove;
	return tmp;
}

void iter(Node* head) {
	Node* move = head;
	do{
		cout << move->data;
		move = move->next;
	} while (head->pre != move && move != NULL);
}

int main(void) {
	Head* head = new Head();
	init(head);
	string str;
	Node* cur = new Node();
	cur->pre = NULL;
	cur->next = cur;
	int n = 0;
	char command;
	char item;
	cin >> str;
	cin >> n;
	head->start = cur;
	for (int i = 0; i < str.length(); i++) {
		cur = insert(cur, str[i]);
	}
	for (int i = 0; i < n; i++) {
		cin >> command;
		switch (command) {
		case 'L':
			if (cur != head->start) {
				cur = cur->pre;
			}
			break;
		case 'B':
			if (cur != head->start) {
				cur = deleteNode(cur, head);
			}
			break;
		case 'D':
			if (cur->next != head->start) {
				cur = cur->next;
			}
			break;
		case 'P':
			cin >> item;
			cur = insert(cur, item);
			break;
		}
	}
	iter(head->start->next);

}