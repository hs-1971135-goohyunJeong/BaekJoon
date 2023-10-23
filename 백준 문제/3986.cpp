#include <iostream>

using namespace std;
#define SIZE 100000
class Stack {
private:
	int top;
	char data[SIZE];
public:
	Stack() {
		top = -1;
	}
	void reset();
	void push(char item);
	char pop();
	char peak();
	int getTop();
};
void Stack::reset() {
	top = -1;
}
void Stack::push(char item) {
	if (top >= SIZE - 1) {
		return;
	}
	data[++top] = item;
}
char Stack::pop() {
	if (top < 0) {
		return 'c';
	}
	return data[top--];
}
char Stack::peak() {
	return data[top];
}
int Stack::getTop() {
	return top;
}

int main(void) {
	string str;
	int count = 0;
	int n = 0;
	cin >> n;
	Stack s = Stack();
	for (int i = 0; i < n; i++) {
		cin >> str;
		s.push(str[0]);
		for (int j = 1; j < str.length(); j++) {
			if (s.peak() == str[j]) {
				s.pop();
			}
			else {
				s.push(str[j]);
			}
		}
		if (s.getTop() == -1) {
			count++;
		}
		s.reset();
	}
	cout << count;
}