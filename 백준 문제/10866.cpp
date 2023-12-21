#include <iostream>

using namespace std;
#define SIZE 100000
class Deq {
private:
	int head;
	int tail;
	int data[SIZE];
	int length;
public:
	Deq() {
		head = 0;
		tail = 0;
		length = 0;
	}
	void push_front(int x);
	void push_back(int x);
	int pop_front();
	int pop_back();
	int size();
	int empty();
	int front();
	int back();
};

void Deq::push_back(int x) {
	data[tail] = x;
	tail = (tail + 1) % SIZE;
	length++;
}

void Deq::push_front(int x) {
	head = (head - 1+SIZE) % SIZE;
	data[head] = x;
	length++;
}

int Deq::pop_back() {
	if (empty() == 1) {
		return -1;
	}
	tail = (tail - 1+SIZE) % SIZE;
	length--;
	return data[tail];
}

int Deq::pop_front() {
	if (empty() == 1) {
		return -1;
	}
	head = head % SIZE;
	int tmp = data[head];
	head = (head + 1) % SIZE;
	length--;
	return tmp;
}

int Deq::size() {
	return length;
}

int Deq::front() {
	if (empty() == 1) {
		return -1;
	}
	return data[head];
}
int Deq::back() {
	if (empty() == 1) {
		return -1;
	}
	int before = tail;
	tail = (tail - 1 + SIZE) % SIZE;
	int tmp =  data[tail];
	tail = before;
	return tmp;
}
int Deq::empty() {
	if (size() == 0) {
		return 1;
	}
	return 0;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	string str;
	int item = 0;
	Deq deq = Deq();
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str.compare("push_back") == 0) {
			cin >> item;
			deq.push_back(item);
		}
		else if (str.compare("push_front") == 0) {
			cin >> item;
			deq.push_front(item);
		}
		else if (str.compare("front") == 0) {
			cout << deq.front() << "\n";
		}
		else if (str.compare("back") == 0) {
			cout << deq.back() << "\n";
		}
		else if (str.compare("size") == 0) {
			cout << deq.size() <<"\n";
		}
		else if (str.compare("empty") == 0) {
			cout << deq.empty() << "\n";
		}
		else if (str.compare("pop_front") == 0) {
			cout << deq.pop_front() << "\n";
		}
		else if (str.compare("pop_back") == 0) {
			cout << deq.pop_back() << "\n";
		}
	}
}