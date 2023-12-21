#include <iostream>
#define SIZE 500001
using namespace std;


class Queue {
private:
	int rear;
	int front;
	int data[SIZE];
public:
	Queue() {
		rear = 1;
		front = 0;
	}
	void push(int item) {
		data[rear] = item;
		rear = (rear + 1) % SIZE;
	}
	bool empty() {
		if (rear-1 == front) {
			return true;
		}
		return false;
	}
	int pop() {
		front = (front + 1) % SIZE;
		int tmp = data[front];
		return tmp;
	}
};

int main(void) {
	int n = 0;
	int result = 0;
	cin >> n;
	Queue q = Queue();
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (true) {
		if (q.empty()) break;
		result = q.pop();
		if (q.empty()) break;
		result = q.pop();
		q.push(result);
	}
	cout << result;
}