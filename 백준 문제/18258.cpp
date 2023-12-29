#include <iostream>

using namespace std;

typedef struct Queue {
	int data[2000000] = { 0 };
	int rear = 0;
	int front = 0;
}Queue;

void push(Queue& q, int item) {
	q.data[q.rear] = item;
	q.rear = (q.rear + 1) % 2000000;
}
int empty(Queue& q) {
	if (q.rear == q.front) {
		return 1;
	}
	return 0;
}
int pop(Queue& q) {
	if (empty(q) == 1) {
		return -1;
	}
	int result = q.data[q.front];
	q.front = (q.front + 1) % 2000000;
	return result;
}

int size(Queue& q) {
	int result = 0;
	if (q.front > q.rear) {
		result = q.rear + (2000000 - q.front);
	}
	else {
		result = q.rear - q.front;
	}
	return result;
}


int front(Queue& q) {
	if (empty(q) == 1) {
		return -1;
	}
	return q.data[q.front];
}
int back(Queue& q) {
	if (empty(q) == 1) {
		return -1;
	}
	return q.data[q.rear - 1];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	string str;
	int item = 0;
	Queue q = Queue();
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str.compare("push") == 0) {
			cin >> item;
			push(q, item);
		}
		else if (str.compare("pop") == 0) {
			cout << pop(q) << "\n";
		}
		else if (str.compare("size") == 0) {
			cout << size(q) << "\n";
		}
		else if (str.compare("empty") == 0) {
			cout << empty(q) << "\n";
		}
		else if (str.compare("front") == 0) {
			cout << front(q) << "\n";
		}
		else if (str.compare("back") == 0) {
			cout << back(q) << "\n";
		}
	}
}