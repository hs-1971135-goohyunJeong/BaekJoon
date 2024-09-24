// 백준 : 점수계산-2506번
#include <iostream>

using namespace std;

// 앞에 문제가 맞으면 총점에 더할 변수인 prev에 1을 더하고 prev를 총점에 더한다.
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	int score = 0; //총점
	int prev = 0; //총점에 더할 점수
	for (int i = 0; i < n; i++) {
		int input = 0;
		cin >> input;
		if (input) { // 맞았을 때
			prev += 1;
			score += prev;
		}
		else { // 틀렸을 때
			prev = 0;
		}
	}
	cout << score;
}