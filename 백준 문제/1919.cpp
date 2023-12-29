#include <iostream>

using namespace std;

void countAlpha(string str, int alpha[]) {
	for (unsigned int i = 0; i < str.length(); i++) {
		alpha[str[i] - 'a']++;
	}
}

int countEraseAlpha(int strAlpha[], int cpyAlpha[]) {
	int result = 0;
	for (int i = 0; i < 26; i++) {
		if (strAlpha[i] > cpyAlpha[i]) {
			result += strAlpha[i] - cpyAlpha[i];
		}
		else {
			result += cpyAlpha[i]- strAlpha[i];
		}
	}
	return result;
}

int main(void) {
	int strAlpha[26] = { 0 };
	int cpyAlpha[26] = { 0 };

	string str;
	string cpy;
	cin >> str >> cpy;
	countAlpha(str, strAlpha);
	countAlpha(cpy, cpyAlpha);
	cout << countEraseAlpha(strAlpha, cpyAlpha);

}