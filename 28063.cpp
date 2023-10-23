// 동전 복사 28063번

#include <iostream>

using namespace std;

// 아이디어
// 1. 어차피 최대로 움직이는 횟수가 4이다.
// 2. 시작 위치가 어디던지 x,y 좌표를 벽면(가장 자리)에 붙이고 나서 움직이면 된다
// 3. 시작 위치가 이미 벽면에 붙어 있다면 움직여야하는 횟수가 줄어든다

int main(void) {
	int n = 0;
	cin >> n;
	int x = 0, y = 0;
	cin >> x >> y;
	int count = 4; //최대로 움직일 수 있는 횟수는 4이다.
	if (n == 1) { // n이 1이면 무조건 0이 출력된다
		cout << 0;
	}
	else { // 시작 위치가 벽면에 붙어있다면 움직여야하는 횟수를 줄이면 된다.
		if (x == 1 || x == n) {
			count--;
		}
		if (y == 1 || y == n) {
			count--;
		}
		cout << count;
	}


}