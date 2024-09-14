// ���� : �ø��� ��ȣ - 1431��

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int sum(string& str) {
	int result = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] > '0' && str[i] <= '9') {
			result += str[i]-'0';
		}
	}
	return result;
}
// GPT�� § �ڵ� 
bool compareTo(string& a, string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	if (sum(a) != sum(b)) {
		return sum(a) < sum(b);
	}
	return a < b;
}
// ���� § �ڵ�
//bool compareTo(string& a, string& b) {
//	if (a.length() < b.length()) {
//		return true;
//	}
//	if (sum(a) < sum(b)) {
//		return true;
//	}
//	if (a < b) {
//		return true;
//	}
//	return false;
//}

// compare�Լ��� �ۼ��� �� �ݻ缺�� ����ؾ���. compareTo(a, b)�� true��, compareTo(b,a)�� false������.
// ���� § �ڵ�� �ݻ缺�� ����. ���� ��� a�� b���� ª���� ������ ���� b�� ���� �� 
// compareTo(a, b), compareTo(b,a) �Ѵ� true�� ���� �� ����.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	vector<string> vec;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), compareTo);
	for (int i = 0; i < n; i++) {
		cout << vec.at(i) << "\n";
	}
}