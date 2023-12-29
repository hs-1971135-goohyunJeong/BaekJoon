#include <iostream>

using namespace std;

void printLoof(int num, string str) {
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < num; j++) {
			cout << str[i];
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	int* num = new int[n];
	string* str = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i] >> str[i];
	}
	for (int i = 0; i < n; i++) {
		printLoof(num[i], str[i]);
		cout << endl;
	}
	delete[] num;
	delete[] str;

}