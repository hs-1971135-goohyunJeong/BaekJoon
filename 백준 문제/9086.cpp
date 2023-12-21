#include <iostream>
#include <string>

using namespace std;

void printStartAlp(string str) {
	cout << str[0];
}

void printEndAlp(string str) {
	cout << str[str.length() - 1];
}

int main(void) {
	int n;
	cin >> n;
	string* str = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for(int i=0; i < n; i++){
		printStartAlp(str[i]);
		printEndAlp(str[i]);
		cout << endl;
	}
}