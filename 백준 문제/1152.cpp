#include <iostream>
#include <string>

using namespace std;

int countWord(string str) {
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' '&&i != 0) {
			count++;
		}
	}
	if (str.length() == 1 && str[0] == ' ') {
		return 0;
	}
	else if (str[str.length()-1] == ' ') {
		return count;
	}
	else {
		return count+1;
	}
	
}

int main(void){
	string str;
	getline(cin, str);
	cout << countWord(str);
}