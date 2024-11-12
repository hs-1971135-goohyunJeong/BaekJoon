// ¹éÁØ : µÚÁıÈù µ¡¼À - 1357¹ø

#include <iostream>
#include <stack>

using namespace std;

int Rev(int num) {
	stack<int> s = stack<int>();
	int result = 0;
	while (num > 0) {
		s.push(num % 10);
		num /= 10;
	}
	int i = 1;
	while (!s.empty()) {
		result += s.top() * i;
		i *= 10;
		s.pop();
	}
	return result;
}

int main(void) {
	int num1 = 0;
	int num2 = 0;
	cin >> num1 >> num2;
	num1 = Rev(num1);
	num2 = Rev(num2);

	cout << Rev(num1 + num2);
}