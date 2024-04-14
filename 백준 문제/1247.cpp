// 백준 : 부호 - 1247번

#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 총합을 그냥 구할 경우 오버플로우 발생할 수 있음
// => 양수는 양수대로 음수는 음수대로 저장한 후 하나씩 빼서 계산한 후에 계산 결과를 다시 저장하기를 반복 
// 마지막에 남은 것이 총합의 결과임

// 따로 따로 저장하는 함수
void saveNumber(long long& tmp, queue<long long>& plus, queue<long long>& minus) {
	if (tmp >= 0) {
		plus.push(tmp);
		
	}
	else {
		minus.push(tmp);
	}

}
// 총합을 구하는 함수
char calcNumber(queue<long long>& plus, queue<long long>& minus) {
	bool isPlusEnd = false;
	
	while (true) {
		if (plus.size() <= 0) {
			isPlusEnd = true;
			break;
		}
		if (minus.size() <= 0) {
			break;
		}
		long long p = plus.front();
		long long m = minus.front();
		long long tmp = p + m; // minus 에 들어있는 것은 이미 음수이기 때문에 더하기를 해줘야함
		plus.pop();
		minus.pop();
		saveNumber(tmp, plus, minus);

	}
	if (isPlusEnd) {
		return '-';
	}
	else {
		bool isZero = true;
		while (!plus.empty()) {
			if (plus.front() != 0) {
				isZero = false;
				break;
			}
			plus.pop();
		}
		if (isZero) {
			return '0';
		}
		else {
			return '+';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 3;
	
	for (int i = 0; i < t; i++) {
		int n = 0;
		cin >> n;
		queue<long long> plus;
		queue<long long> minus;
		for (int j = 0; j < n; j++) {
			long long tmp;
			cin >> tmp;
			saveNumber(tmp, plus, minus);
		}
		if (n == 0) {
			cout << "0\n";
		}
		else {
			cout << calcNumber(plus, minus) << "\n";
		}
		
	}
}