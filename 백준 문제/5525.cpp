// IOIOI - 5525��
#include <iostream>
#include <vector>
using namespace std;


// ��Ģ: 101010101 (4 = O �� ���� = ������ ����) : 1 => 4 / 2 => 3 / 3 => 2 / 4 => 1 (length/2-N)+1
int max(int n) {
	if (n < 0) {
		return 0;
	}
	return n;
}
int solve(string& str, int n, int last) {
	int count = 0;
	int start = 0;
	int end = 0;
	bool canMoveStart = true;
	bool canCalc = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'I' && canMoveStart) {
			canMoveStart = false;
			start = i;
		}
		
		if (i > 0 && str[i-1] == str[i]) {
			canCalc = true;
		}
		if (str[i] == 'I') {
			end = i;
			// ������ end �� ������ I �� ����Ű�� ������ �� �ڿ� �ִ� ���� �Ű澲������ ���������� �׽�Ʈ
			// 1 4 IOIO �� ����� Ǯ�� ���� (�� ��� �����ư��鼭 ���ͼ� �Ʒ��� ���� ���̴� canCalc ���ǹ��� ��������)
			if (end == last) {
				canCalc = true;
			}
		}

		if (canCalc) {
			int length = end - start;
			int countingO = length / 2;
			// ī������ ������ �ɶ��� ���� (ex 0 �� ������ 1���ε� N�� 2�� ���) => ������ 0���� ġȯ
			count += max((countingO - n) + 1);
			canCalc = false;
			start = i;
			//start �� ����Ű�°� O �� �� ���� �̰�� �ٽ� I �� ����Ű���� �������
			if (str[i] != 'I') {
				canMoveStart = true;
			}
		}
	}
		
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	string str = "";
	cin >> str;

	int lastI = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == 'I') {
			lastI = i;
			break;
		}
	}
	cout << solve(str, n, lastI);

}