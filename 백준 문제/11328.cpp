// น้มุ : Strfry - 11328น๘

#include <iostream>

using namespace std;

void countingAlpha(string& str, int count[]) {
	for (int i = 0; i < str.length(); i++) {
		count[str[i] - 'a']++;
	}
}
bool canStrfry(int countAlphaOfStr[], int countAlphaOfFry[]) {
	for (int i = 0; i < 26; i++) {
		if (countAlphaOfStr[i] != countAlphaOfFry[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		string fry;
		cin >> str >> fry;
		int countAlphaOfStr[26] = { 0 };
		int countAlphaOfFry[26] = { 0 };
		countingAlpha(str, countAlphaOfStr);
		countingAlpha(fry, countAlphaOfFry);
		if (canStrfry(countAlphaOfStr, countAlphaOfFry)) {
			cout << "Possible\n";
		}
		else {
			cout << "Impossible\n";
		}
	}
}