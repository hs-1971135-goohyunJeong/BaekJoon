#include <iostream>
#include <string>
using namespace std;

void push(int stack[], int& point, int item) {
	if (point < 10000-1) {
		point++;
		stack[point] = item;
	}
}

int pop(int stack[], int& point) {
	if (point >= 0) {
		return stack[point--];
	}
	return -1;
}

int top(int stack[], int& point) {
	if (point >= 0) {
		return stack[point];
	}
	return -1;
}

int size(int& point) {
	return point+1;
}

int empty(int& point) {
	if (point < 0) {
		return 1;
	}
	return 0;
}

int main(void) {
	int n = 0;
	int stack[10000] = { 0 };
	int point = -1;
	cin >> n;
	string str;
	int item = 0;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str.compare("push")==0) {
			cin >> item;
			push(stack, point, item);
		}
		else if (str.compare("top") == 0) {
			cout << top(stack, point) << "\n";
		}
		else if (str.compare("size") == 0) {
			cout << size(point) << "\n";
		}
		else if (str.compare("empty") == 0) {
			cout << empty(point) << "\n";
		}
		else if (str.compare("pop") == 0) {
			cout << pop(stack, point) << "\n";
		}
	}
}