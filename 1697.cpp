// 숨바꼭질 1697번
#include <iostream>
#include <queue>
using namespace std;

#define SIZE 200000

void bfs(int arr[], int n, int k) {
	queue<int> q;
	q.push(n);
	int dx[2] = { 1,-1 };
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int i = 0; i < 3; i++) {
			int nx = 0;
			if (i != 2) {
				nx = cur + dx[i];
			}
			else {
				nx = cur * 2;
			}
			if (nx > SIZE || nx < 0) {
				continue;
			}
			if (arr[nx] != -1) {
				continue;
			}
			arr[nx] = arr[cur] + 1;
			if (nx == k) {
				return;
			}
			q.push(nx);
		}
		
	}
}

int main(void) {
	int n = 0;
	int k = 0;
	cin >> n >> k;
	int arr[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++) {
		arr[i] = -1;
	}
	arr[n] = 0;
	bfs(arr, n, k);
	cout << arr[k];
}