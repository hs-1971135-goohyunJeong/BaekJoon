// ���� : ������ ��ȯ - 10829��

#include <iostream>
#include <vector>

using namespace std;

// �������� ��ȯ�� �� �������� �������� ��ġ�ؾ� �ùٸ� �������� ��
void solve(long long n) {
	vector<int> vec;
	while (true) {
		if (n == 0) {
			break;
		}
		vec.push_back(n % 2);
		n /= 2;
	}
	int size = vec.size();
	for (int i = size - 1; i >= 0; i--) {
		cout << vec.at(i);
	}
}

int main() {
	long long n = 0;
	cin >> n;
	solve(n);
}