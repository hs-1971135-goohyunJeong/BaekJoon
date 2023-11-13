// ������ ����Ʈ - 17827��

#include <iostream>
#include <vector>
using namespace std;


int answer(vector<int>& vec, int tmp, int n, int v) {
	
	// count = �������� �ϴ� Ƚ�� -> �ε����� ǥ��
	int count = tmp;
	// count �� n-1���� ũ�� �ݺ��Ǵ� �κп����� ���ڰ� ����
	if (count > n - 1) {
		// �� ������ ����� ���ƾ���
		count -= n;
		// �ݺ��Ǵ� �κ� ó�� 
		count = count % (n - v+1);
		
		// �ݺ����� �ʴ� �κ��� ������ ���� �� �κ� ó��
		count += (v-1);
	}

	
	return vec.at(count);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0, v = 0;
	cin >> n >> m >> v;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		vec.push_back(tmp);
	}
	// ������ �ް� ���ϴ� �κ�
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		cin >> tmp;
		cout  << answer(vec, tmp, n, v) << "\n";
	}
	
}