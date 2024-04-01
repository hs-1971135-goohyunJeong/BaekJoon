// 백준 : 이진수 덧셈 - 1252번

#include <iostream>
#include <vector>

using namespace std;

// 소수의 맨 뒤에서부터 덧셈을 진행해가면서
// 둘다 1 이면 그 자리수는 0이지만 그 다음 자리수는 1을 추가해줘야한다.
// 둘다 0 이면 그 자리수는 0,
// 그 외의 경우는 자리수가 1이다.
// 다만 아래 자리수가 1을 넘겨줬는지에 따라 달라지므로 이를 체크 해야한다. (bool up 의 역할)
void add(string& a, string& b, char c[]) {
	int aIndex = a.length() - 1;
	int bIndex = b.length() - 1;
	c[aIndex + 1] = '\0';
	bool up = false;
	while (true) {
		// 짧은 쪽의 소수를 전부 더했으면 루프 탈출
		if (bIndex < 0) {
			break;
		}
		if (a[aIndex] == '1' && b[bIndex] == '1') {
			if (up) {
				c[aIndex] = '1';
			}
			else {
				c[aIndex] = '0';
			}
			up = true;
		}
		else if (a[aIndex] == '0' && b[bIndex] == '0') {
			if (up) {
				c[aIndex] = '1';
			}
			else {
				c[aIndex] = '0';
			}
			up = false;
		}
		else {
			if (up) {
				c[aIndex] = '0';
				up = true;
			}
			else {
				c[aIndex] = '1';
				up = false;
			}
		}
		aIndex--;
		bIndex--;
	}
	while (aIndex >= 0) {
		if (up) { // 짧은 쪽이 끝나더라도 up 은 true 일 수 있음 (ex : 11+1)
			if (a[aIndex] == '1') {
				c[aIndex] = '0';
			}
			else {
				c[aIndex] = '1';
				up = false;
			}
		}
		else {
			c[aIndex] = a[aIndex];
		}
		aIndex--;
	}
	// 결과가 0이 아니라면 맨처음은 1로 시작해야함 
	bool start = true;
	for (int i = 0; c[i] != '\0'; i++) {
		// a 의 마지막 자리수 넘어서도 1이 생길 수 있음 (ex : 1 1)
		if (up) {
			cout << "1";
			up = false;
			start = false;
		}
		// 1로 시작하지 않으면 무시
		if (c[i] == '0' && start) {
			continue;
		}
		cout << c[i];
		start = false;
	}
	// 1이 한번도 안나오면 0 출력
	if (start) {
		cout << "0";
	}
}
int main(void) {
	string a;
	string b;
	cin >> a >> b;
	string tmp;
	// a가 무조건 긴 소수를 저장하도록 바꿔줌 
	if (a.length() < b.length()) {
		tmp = a;
		a = b;
		b = tmp;
	}
	// 80 자리수 + 80 자리수 할 경우 c 는 81자리를 가져야함
	char c[81] = "";
	add(a, b, c);
}