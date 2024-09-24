//���� : �ϱ��-2776��
#include <iostream>
#include <unordered_map>

using namespace std;


void solve() {
	// �ؽ���
	unordered_map<int, int> hash;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp=0;
		cin >> tmp;
		hash[tmp] = 1;
	}
	int m = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		cin >> tmp;
		//find()
		//�ش� Ű�� �ش��ϴ� value�� �ִ��� ã�� �Լ�
		//end()
		//�ؽ����� ������� �ǹ�
		if (hash.find(tmp) != hash.end()) {
			cout << hash[tmp] << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solve();
	}
}