// 백준 : 수학숙제 - 2870번
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 숫자 부분은 투포인터를 활용하여 숫자의 시작과 끝 부분을 기준으로 문자열에서 잘라낸다.
// 0이 앞에 붙는 경우는 0 이 아닌 숫자가 나올 때까지 전부 무시하고 만약 000 같이 0으로만 이루어진 경우 맨 마지막 0을 저장한다.

bool compareTo(const string& a, const string& b) {
	// 내가 짠 것 => 에러
	/*if (a.length() > b.length()) {
		return true;
	}
	else if (a.length() < b.length()) {
		return false;
	}
	else {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] > b[i]) {
				return true;
			}
			else if (a[i] < b[i]) {
				return false;
			}
		}
	}*/
	//GPT가 짠 것
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		return a < b;
	}
}
void findNumber(string& str, vector<string>& vec) {
	int start = 0; // 숫자의 시작점
	int end = 0; // 숫자의 끝점
	string tmp = ""; // 문자열 중 숫자부분
	while (true) {
		
		if (str[start] < 'a' || str[start] >'z') {
			while (true) {
				end++;
				if (end >= str.length()) {
					break;
				}
				if (str[end] >= 'a' && str[end] <= 'z') {
					break;
				}
				
			}
			tmp = str.substr(start, end-start);
			bool isFirst = true;
			string trim = ""; // 앞에 나오는 0을 제거한 문자열
			for (int i = 0; i < tmp.length(); i++) {
				if (isFirst && tmp[i] == '0') {
					if (i == tmp.length() - 1) { // 0으로만 구성된 경우 그 숫자는 0임 
						trim.append("0");
						break;
					}
					continue;
				}
				isFirst = false;
				trim = tmp.substr(i, tmp.length() - i);
				break;
			}
			
			vec.push_back(trim);
		}
		start = end + 1;
		end = start;
		if (end >= str.length()) {
			break;
		}
	}
}
void solve() {
	int n = 0;
	cin >> n;
	vector<string> vec;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		findNumber(str, vec);
	}
	sort(vec.begin(), vec.end(), compareTo);
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.at(i).length(); j++) {	
			cout << vec.at(i)[j];
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	
}