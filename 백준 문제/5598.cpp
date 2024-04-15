// 백준 : 카이사르 암호 - 5598번

#include <iostream>

using namespace std;

// 알파벳 A 를 0으로 Z 를 25로 바꾸고 카이사르의 암호를 풀기 위해 -3을 해준다.
// 이러면 범위가 -3~22가 되고 여기에 알파벳 개수를 더해 이어지도록 한다.
// (0~9 범위로 한정할 때 음수는 10에서 빼주면 한바퀴 돌듯이 연결된다.)
// 이것을 0과 25 사이가 되도록 26으로 나머지를 구하고 'A'의 값을 더해서 0이 A가 되도록 한다.
void solve(string& str, string& result) {
	
	for (int i = 0; i < str.size(); i++) {
		result.push_back((str[i] - 'A' - 3 + 26) % 26 + 65);
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	string result = "";
	solve(str, result);
	cout << result;
	

}