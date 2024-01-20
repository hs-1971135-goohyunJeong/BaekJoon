// IOIOI - 5525번
#include <iostream>
#include <vector>
using namespace std;


// 규칙: 101010101 (4 = O 의 개수 = 길이의 절반) : 1 => 4 / 2 => 3 / 3 => 2 / 4 => 1 (length/2-N)+1
int max(int n) {
	if (n < 0) {
		return 0;
	}
	return n;
}
int solve(string& str, int n, int last) {
	int count = 0;
	int start = 0;
	int end = 0;
	bool canMoveStart = true;
	bool canCalc = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'I' && canMoveStart) {
			canMoveStart = false;
			start = i;
		}
		
		if (i > 0 && str[i-1] == str[i]) {
			canCalc = true;
		}
		if (str[i] == 'I') {
			end = i;
			// 현재의 end 가 마지막 I 를 가리키고 있으면 그 뒤에 있는 것은 신경쓰지말고 마지막으로 테스트
			// 1 4 IOIO 를 제대로 풀기 위함 (이 경우 번갈아가면서 나와서 아래의 문장 없이는 canCalc 조건문을 가지않음)
			if (end == last) {
				canCalc = true;
			}
		}

		if (canCalc) {
			int length = end - start;
			int countingO = length / 2;
			// 카운팅이 음수가 될때도 있음 (ex 0 의 개수가 1개인데 N이 2인 경우) => 음수면 0으로 치환
			count += max((countingO - n) + 1);
			canCalc = false;
			start = i;
			//start 가 가리키는게 O 일 수 있음 이경우 다시 I 를 가리키도록 해줘야함
			if (str[i] != 'I') {
				canMoveStart = true;
			}
		}
	}
		
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	string str = "";
	cin >> str;

	int lastI = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == 'I') {
			lastI = i;
			break;
		}
	}
	cout << solve(str, n, lastI);

}