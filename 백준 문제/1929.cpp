// �Ҽ����ϱ� 1929��

#include <iostream>
#include <vector>

using namespace std;

//�����佺�׳׽��� ü
void isPrime(int* arr, bool* vis, int m, int n, vector<int>& vec) {
	if (m <= 2) {
		vec.push_back(2);
	}
	for (long long i = 3; i <= n; i+=2) {
		if (vis[i] == false) {
			if (arr[i] >= m) {
				vec.push_back(arr[i]);
			}
			vis[i] = true;
			long long k = i;
			//i*k�� 100��*100������ ������ Ŀ�� �� �����Ƿ� long long������ �ε����� ��
			for (long long j = i * k; j <= n; j = i*k) {
				k++;
				vis[j] = true;
			}
		}
	}
}

int main(void) {
	int n = 0, m = 0;
	cin >> m >> n;
	int* arr = new int[n+1];
	//�Ҽ��� �ƴϸ� false �Ҽ��� true�� �����ϴ� �迭
	bool* vis = new bool[n+1];
	//�Ҽ��� �����ϴ� ����
	vector<int> vec;
	for (int i = 0; i <= n; i++) {
		arr[i] = i;
		vis[i] = false;
	}
	isPrime(arr, vis, m, n, vec);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << "\n";
	}

}