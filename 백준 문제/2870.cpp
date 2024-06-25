// ���� : ���м��� - 2870��
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// ���� �κ��� �������͸� Ȱ���Ͽ� ������ ���۰� �� �κ��� �������� ���ڿ����� �߶󳽴�.
// 0�� �տ� �ٴ� ���� 0 �� �ƴ� ���ڰ� ���� ������ ���� �����ϰ� ���� 000 ���� 0���θ� �̷���� ��� �� ������ 0�� �����Ѵ�.

bool compareTo(const string& a, const string& b) {
	// ���� § �� => ����
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
	//GPT�� § ��
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		return a < b;
	}
}
void findNumber(string& str, vector<string>& vec) {
	int start = 0; // ������ ������
	int end = 0; // ������ ����
	string tmp = ""; // ���ڿ� �� ���ںκ�
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
			string trim = ""; // �տ� ������ 0�� ������ ���ڿ�
			for (int i = 0; i < tmp.length(); i++) {
				if (isFirst && tmp[i] == '0') {
					if (i == tmp.length() - 1) { // 0���θ� ������ ��� �� ���ڴ� 0�� 
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