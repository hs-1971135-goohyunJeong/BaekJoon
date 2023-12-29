#include <iostream>
#include <vector>

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
	int n = 0;
	int stack[100000] = { 0 };
	vector<char> result = vector<char>();
	int top = -1;
	int item = 0;
	int recent = 0;
	int max = 0;
	bool isPush = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> item;
		for (int j = max+1; j <= item; j++) {
			push(stack, top, j);
			result.push_back('+');
			isPush = true;
		}
		if (isPush) {
			recent = pop(stack, top);
			max = recent;
			result.push_back('-');
			isPush = false;
			continue;
		}
		if (recent > item) {
			recent = pop(stack, top);
			if (recent != item) {
				cout << "NO";
				return 0;
			}
			result.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}