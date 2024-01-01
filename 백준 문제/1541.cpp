// 잃어버린 괄호 - 1541번

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 첫번째 - 를 기준으로 그 이전에서 그 이후의 값을 뺌 
int calcPlus(string& num) {
	int sum = 0;
	vector<string> str;
	int length = num.length();
	int end = length;
	int idx = 0;
	int start = 0;
	int point = 0;
	while (true) {
		idx = num.find('+', start);
		point = idx;
		if (idx == string::npos) {
			end = length - start;
			str.push_back(num.substr(start, end));
			break;
		}
		point -= start;
		str.push_back(num.substr(start, point));
		start = idx + 1;
	}
	for (int i = 0; i < str.size(); i++) {
		sum += stoi(str.at(i));
	}
	return sum;
}
void changeMinus(string& str) {
	int idx = 0;
	int start = 0;
	while (true) {
		idx = str.find('-', start);
		if (idx == string::npos) {
			break;
		}
		str.at(idx) = '+';
		start = idx + 1;
	}
}
int main(void) {
	string str;
	cin >> str;
	string num1 ="", num2="";
	int idx = str.find('-'); 
	if (idx == string::npos) {
		cout << calcPlus(str);
		return 0;
	}
	num1.append(str.substr(0, idx));
	string change = str.substr(idx + 1, str.length() - idx - 1);
	changeMinus(change);
	num2.append(change);
	cout << calcPlus(num1) - calcPlus(num2);
}