#include <iostream>

using namespace std;
#define SIZE 50
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
		return 'a';
	}
	return data[top--];
}
int Stack::getTop() {
	return top; 
}

int main(void) {
	int n = 0;
	cin >> n;
	string str;
	Stack s = Stack();
	bool isVps = true;
	for (int i = 0; i < n; i++) {
		cin >> str;
		isVps = true;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') {
				s.push(str[j]);
			}
			else {
 				char popCh = s.pop();
				if (popCh != '(') {
					isVps = false;
				}
			}
		}
		if (s.getTop() != -1) {
			isVps = false;
		}

		if (isVps) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		s.reset();
	}
}