#include <iostream>

using namespace std;

bool isTriangle(int a, int b, int c) {
	if (a + b + c == 180) {
		return true;
	}
	return false;
}

void whatKindOfTriangle(int a, int b, int c, string& str) {
	if (isTriangle(a, b, c) == false) {
		str = "Error";
	}
	else {
		if (a == b && b == c) {
			str = "Equilateral";
		}
		else if (a == b || b == c || a == c) {
			str = "Isosceles";
		}
		else {
			str = "Scalene";
		}
	}
}

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	string str = "";
	whatKindOfTriangle(a, b, c, str);
	cout << str;
}