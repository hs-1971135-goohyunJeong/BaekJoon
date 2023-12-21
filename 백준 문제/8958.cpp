#include <iostream>
#include <string>

using namespace std;

void input(string* str, int size) {
	for (int i = 0; i <size; i++) {
		getline(cin, str[i]);
	}
}

int calc(string str) {
	int score = 0;
	int keep = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'O') {
			keep++;
			score += keep;
		}
		else {
			keep = 0;
		}
	}
	return score;
}

int main() {
	int num;
	cin >> num;
	cin.get();
	string* str = new string[num];
	input(str, num);
	for (int i = 0; i < num; i++) {
		cout << calc(str[i])<<endl;
	}
	delete[] str;
}