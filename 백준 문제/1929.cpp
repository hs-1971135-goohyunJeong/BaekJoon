// 소수구하기 1929번

#include <iostream>
#include <vector>

using namespace std;

//에라토스테네스의 체
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
			//i*k가 100만*100만까지 정수가 커질 수 있으므로 long long형으로 인덱스를 줌
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
	//소수가 아니면 false 소수면 true를 저장하는 배열
	bool* vis = new bool[n+1];
	//소수를 저장하는 벡터
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