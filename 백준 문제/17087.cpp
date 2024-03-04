// ���� : ���ٲ��� 6 - 17087��

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// a �� b ���� ������ ���� ��ȯ�ϴ� �Լ�
void swap(long long& a, long long& b) {
	if (a < b) {
		long long tmp = a;
		a = b;
		b = tmp;
	}
}
// �ִ� ����� ���ϱ�
long long gcd(long long a, long long b) {
	// a �� �׻� ũ�ٴ� ������ �����Ƿ� ū���� a �� �ٲٴ� ������ ����
	swap(a, b);
	while (b != 0) {
		long long tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

// D = �Ÿ����� �ִ� �����
// �տ��� ���� �ִ� ������� ������ �Ÿ��� �ִ� ������� ���ϸ� �Ÿ����� �ִ� ������� ��
long long solve(long long n, vector<long long>& dist) {
	long long result = dist.at(0);
	for (long long i = 1; i < n; i++) {
		result = gcd(result, dist.at(i));
	}
	return result;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, s;
	cin >> n >> s;
	vector<long long> kids = vector<long long>();
	vector<long long> dist = vector<long long>();
	for (long long i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		kids.push_back(tmp);
	}
	for (long long i = 0; i < n; i++) {
		long long tmp = abs(s - kids.at(i)); // �Ÿ��� ������ ������ ���ϰ� ���밪 ������
		dist.push_back(tmp);
	}
	cout << solve(n, dist);
}