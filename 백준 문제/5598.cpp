// ���� : ī�̻縣 ��ȣ - 5598��

#include <iostream>

using namespace std;

// ���ĺ� A �� 0���� Z �� 25�� �ٲٰ� ī�̻縣�� ��ȣ�� Ǯ�� ���� -3�� ���ش�.
// �̷��� ������ -3~22�� �ǰ� ���⿡ ���ĺ� ������ ���� �̾������� �Ѵ�.
// (0~9 ������ ������ �� ������ 10���� ���ָ� �ѹ��� ������ ����ȴ�.)
// �̰��� 0�� 25 ���̰� �ǵ��� 26���� �������� ���ϰ� 'A'�� ���� ���ؼ� 0�� A�� �ǵ��� �Ѵ�.
void solve(string& str, string& result) {
	
	for (int i = 0; i < str.size(); i++) {
		result.push_back((str[i] - 'A' - 3 + 26) % 26 + 65);
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	string result = "";
	solve(str, result);
	cout << result;
	

}