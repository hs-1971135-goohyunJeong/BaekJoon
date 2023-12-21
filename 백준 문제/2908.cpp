#include <iostream>
#include <string>

using namespace std;

void reverse(string& str) {
	string cpy = str;
	for (int i = 0; i < str.length(); i++) {
		str[i] = cpy[cpy.length() - i-1];
	}
}


int main() {
	string left, right;
	cin >> left >> right;
	reverse(left);
	reverse(right);
	int leftNum = stoi(left);
	int rightNum = stoi(right);
	int bigger = 0;
	if (leftNum > rightNum) {
		bigger = leftNum;
	}
	else {
		bigger = rightNum;
	}
	cout << bigger;
}