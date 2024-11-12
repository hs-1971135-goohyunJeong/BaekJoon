// 백준 : 반지 - 5555번

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int counting(vector<string>& vec, string& str) {
	int result = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec.at(i).find(str) != string::npos) {
			result++;
			continue;
		}
		/*reverse(vec.at(i).begin(), vec.at(i).end());
		if(vec.at(i).find(str)){
			result++;
		}*/
	}
	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	string str = "";
	cin >> str;
	cin >> n;
	vector<string> vec = vector<string>();
	for(int i=0; i < n; i++){
		string tmp = "";
		cin >> tmp;
		string cpy = tmp + tmp;
		vec.push_back(cpy);
	}
	cout << counting(vec, str);
}