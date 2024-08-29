// ���� : �ֳʱ׷� - 6996��

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
		// �� �ܾ��� ���̰� �ٸ��� �ֳʱ׷��� �ƴ�.
		if (sSize != tSize) {
			cout << str << " & " << tmp << " are NOT anagrams.\n";
			continue;
		}
		// �� �ܾ��� ���̰� ������ ���ĺ��� ������ ������.
		for (int j = 0; j < sSize; j++) {
			sAlpha[str[j] - 'a']++;
			tAlpha[tmp[j] - 'a']++;
		}
		// ���ĺ� ������ �� �� �� �ܾ��� ���ĺ� ������ �� �ؾ���.
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