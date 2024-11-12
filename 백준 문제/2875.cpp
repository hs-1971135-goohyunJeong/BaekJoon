// 백준 : 대회 or 인턴 - 2875번
#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	int m = 0;
	int k = 0;
	int team = 0; // 조의 수
	int rest = 0; //조가 없는 학생
	cin >> n >> m >> k;
	team = n / 2; // 여학생 2인 1조로 먼저 꾸리기
	rest = n % 2; // 2인 1조에 포함안된 학생 : 0명 혹은 1명
	if (team > m) { // 남학생이 부족한 경우
		rest += 2*(team - m); // 남학생이 없는 조는 해체
		team = m; // 남학생 수만큼 조가 만들어짐
	}
	else {
		rest += m - team;
	}
	if (k > rest) {
		k -= rest;
		while (k > 0) {
			team--;
			k -= 3;
		}
	}
	cout << team;
}