// �⼮üũ - 20438��

#include <iostream>
#include <vector>

using namespace std;

void checking(int* student, vector<int>& start, int n) {
	for (int j = 0; j < start.size(); j++) {
		for (int i = start[j]; i < n; i += start[j]) {
			student[i] = 0; // �����ϸ� 0
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
	int* student = new int[n + 3]; // �⼮�ߴ��� ���ߴ��� �����ϴ� �迭
	for (int i = 3; i < n + 3; i++) {
		student[i] = 1; // �������ϸ� 1, ó������ ���� 1�� �ʱ�ȭ
	}
	int sleep[5003] = { 0 }; // � ��ȣ�� �ڰ� �ִ��� -> start���� ���� ���� ���
	int* whoSleep = new int[k]; // � ��ȣ�� �ڰ� �ִ��� -> �ڰ� ������ 1�� �����ֱ� ���� ���
	for (int i = 0; i < k; i++) {
		whoSleep[i] = 0;
	}
	int* attendent = new int[n + 4]; // �����տ� �� �迭
	vector<int> start; // � ��ȣ�� ����� �⼮�ϴ� �� �����ϴ� �迭
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
		if (sleep[who] == 1) { // �����ϴ� ��ȣ�� �ڰ� ������ �� ���� start���� ����
			continue;
		}
		start.push_back(who);
	}
	checking(student, start, n+3); // start�� ������� �⼮�ϵ��� �ϴ� �Լ�
	sleeping(student, whoSleep, k); // start�� �ƴ����� �ڰ� ������ �� ���� �⼮���ϵ��� �ϴ� �Լ�
	
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