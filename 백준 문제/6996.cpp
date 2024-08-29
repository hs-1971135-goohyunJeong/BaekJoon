// 백준 : 애너그램 - 6996번

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		string tmp;

		cin >> str >> tmp;
		int sSize = str.length();
		int tSize = tmp.length();
		char sAlpha[26] = { 0 };
		char tAlpha[26] = { 0 };
		bool isAnagram = true;
		// 두 단어의 길이가 다르면 애너그램이 아님.
		if (sSize != tSize) {
			cout << str << " & " << tmp << " are NOT anagrams.\n";
			continue;
		}
		// 두 단어의 길이가 같으면 알파벳의 개수를 세야함.
		for (int j = 0; j < sSize; j++) {
			sAlpha[str[j] - 'a']++;
			tAlpha[tmp[j] - 'a']++;
		}
		// 알파벳 개수를 센 후 두 단어의 알파벳 개수를 비교 해야함.
		for (int j = 0; j <26; j++) {
			if (sAlpha[j] != tAlpha[j]) {
				cout << str << " & " << tmp << " are NOT anagrams.\n";
				isAnagram = false;
				break;
			}
		}
		if (isAnagram) {
			cout << str << " & " << tmp << " are anagrams.\n";
		}
		
	}


}