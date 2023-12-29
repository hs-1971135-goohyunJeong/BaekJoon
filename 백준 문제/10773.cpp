#include <iostream>

using namespace std;

int pop(int stack[], int& top) {
	if (top >= 0) {
		return stack[top--];
	}
}

void push(int stack[], int& top, int item) {
	if (top < 100000 - 1) {
		stack[++top] = item;
	}
}

int main(void) {
	int stack[100000] = { 0 };
	int top = -1;
	int k = 0;
	cin >> k;
	int item = 0;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		cin >> item;
		if (item != 0) {
			push(stack, top, item);
		}
		else {
			pop(stack, top);
		}
	}
	int size = top+1;
	for (int i = 0; i < size; i++) {
		sum += pop(stack, top);
	}
	cout << sum;
}