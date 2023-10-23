#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	int top;
	char data[100];
public:
	Stack() {
		top = -1;
		for (int i = 0; i < 100; i++) {
			data[i] = '\0';
		}
	}
	int getTop();
	void push(char item);
	char pop();
	void reset();
};

int Stack::getTop() {
	return top;
}
void Stack::push(char item) {
	if (top >= 99) {
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
void Stack::reset() {
	top = -1;
}

int main(void) {
	string str;
	Stack s = Stack();
	bool isSuccess = true;
	while (true) {
		getline(cin, str);
		isSuccess = true;
		if (str.compare(".") == 0) {
			break;
		}
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				if (s.pop() != '(') {
					isSuccess = false;
					break;
				}
			}
			else if (str[i] == ']') {
				if (s.pop() != '[') {
					isSuccess = false;
					break;
				}
			}
		}
 		
		if (isSuccess) {
			if (s.getTop() == -1) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
			
		}
		else {
			cout << "no\n";
		}
		s.reset();

	}

}