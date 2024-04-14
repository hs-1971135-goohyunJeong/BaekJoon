// ���� : ��ȣ - 1247��

#include <iostream>
#include <queue>
#include <string>
using namespace std;

// ������ �׳� ���� ��� �����÷ο� �߻��� �� ����
// => ����� ������ ������ ������� ������ �� �ϳ��� ���� ����� �Ŀ� ��� ����� �ٽ� �����ϱ⸦ �ݺ� 
// �������� ���� ���� ������ �����

// ���� ���� �����ϴ� �Լ�
void saveNumber(long long& tmp, queue<long long>& plus, queue<long long>& minus) {
	if (tmp >= 0) {
		plus.push(tmp);
		
	}
	else {
		minus.push(tmp);
	}

}
// ������ ���ϴ� �Լ�
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
		long long tmp = p + m; // minus �� ����ִ� ���� �̹� �����̱� ������ ���ϱ⸦ �������
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