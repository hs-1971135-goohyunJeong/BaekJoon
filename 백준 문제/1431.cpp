// 백준 : 시리얼 번호 - 1431번

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
// GPT가 짠 코드 
bool compareTo(string& a, string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	if (sum(a) != sum(b)) {
		return sum(a) < sum(b);
	}
	return a < b;
}
// 직접 짠 코드
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

// compare함수를 작성할 때 반사성을 고려해야함. compareTo(a, b)가 true면, compareTo(b,a)는 false여야함.
// 직접 짠 코드는 반사성이 없음. 예를 들어 a가 b보다 짧지만 숫자의 합이 b가 작을 때 
// compareTo(a, b), compareTo(b,a) 둘다 true가 나올 수 있음.

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