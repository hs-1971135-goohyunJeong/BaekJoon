#include <iostream>
using namespace std;

#define SWAP(a,b,c) ((c=a),(a=b),(b=c))


int main(void) {
	int n = 0, m = 0, i = 0, j = 0;
	int tmp = 0;
	cin >> n >> m;
	int* arr = new int[n];
	for (int a = 0; a < n; a++) {
		arr[a] = a+1;
	}
	for (int a = 0; a < m; a++) {
		cin >> i >> j;
		SWAP(arr[i-1], arr[j-1], tmp);
	}
	for (int a = 0; a < n; a++) {
		cout << arr[a] << " ";
	}
}