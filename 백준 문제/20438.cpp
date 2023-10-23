// 출석체크 - 20438번

#include <iostream>
#include <vector>

using namespace std;

void checking(int* student, vector<int>& start, int n) {
	for (int j = 0; j < start.size(); j++) {
		for (int i = start[j]; i < n; i += start[j]) {
			student[i] = 0; // 참석하면 0
		}
	}
	
}

void sleeping(int* student, int* sleep, int k) {
	for (int j = 0; j < k; j++) {
		student[sleep[j]] = 1;
	}
}

void prefix(int* student, int* attendent, int n) {
	attendent[3] = 0;
	for (int i = 3; i < n; i++) {
		attendent[i + 1] = student[i] + attendent[i];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, k = 0, q = 0, m = 0;
	cin >> n >> k >> q >> m;
	int* student = new int[n + 3]; // 출석했는지 안했는지 저장하는 배열
	for (int i = 3; i < n + 3; i++) {
		student[i] = 1; // 참석안하면 1, 처음에는 전부 1로 초기화
	}
	int sleep[5003] = { 0 }; // 어떤 번호가 자고 있는지 -> start에서 빼기 위해 사용
	int* whoSleep = new int[k]; // 어떤 번호가 자고 있는지 -> 자고 있으면 1로 고쳐주기 위해 사용
	for (int i = 0; i < k; i++) {
		whoSleep[i] = 0;
	}
	int* attendent = new int[n + 4]; // 누적합에 쓸 배열
	vector<int> start; // 어떤 번호의 배수를 출석하는 지 저장하는 배열
	int count = 0;
	for (int i = 0; i < k; i++) {
		int who = 0;
		cin >> who;
		sleep[who] = 1;
		whoSleep[i] = who;
	}
	for (int i = 0; i < q; i++) {
		int who = 0;
		cin >> who;
		if (sleep[who] == 1) { // 시작하는 번호가 자고 있으면 그 수는 start에서 제외
			continue;
		}
		start.push_back(who);
	}
	checking(student, start, n+3); // start의 배수들을 출석하도록 하는 함수
	sleeping(student, whoSleep, k); // start가 아니지만 자고 있으면 그 수만 출석못하도록 하는 함수
	
	prefix(student, attendent, n + 3);
	for (int i = 0; i < m; i++) {
		int s = 0, e = 0;
		cin >> s >> e;
		cout << attendent[e+1] - attendent[s] << "\n";
	}
	delete[] whoSleep;
	delete[] student;
	delete[] attendent;
}