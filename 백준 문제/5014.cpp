// 스타트링크 5014번

#include <iostream>
#include <queue>

using namespace std;

int bfs(int* arr, int f, int s, int g) {
	queue<int> q;
	q.push(s-1);
	int u = 0, d = 0;
	arr[s - 1] = 1;
	cin >> u >> d;
	int count = 0;
	int dy[2] = { u, d*-1 };
	if (s == g) {
		return 1;
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int ny = cur + dy[i];
			if (ny < 0 || ny >= f) {
				continue;
			}
			if (arr[ny] > 0) {
				continue;
			}
			arr[ny] = arr[cur] + 1;
			if (ny == g-1) {
				return arr[ny];
			}
			q.push(ny);
		}
		
	}
	return -1;
}

int main(void) {
	int f = 0, g = 0, s = 0;
	cin >> f >> s >> g;
	int* arr = new int[f];
	for (int i = 0; i < f; i++) {
		arr[i] = 0;
	}
	arr[g - 1] = -1;
	int isStair = bfs(arr, f, s, g);
	/*for (int i = 0; i < f; i++) {
		cout << arr[i] <<"\n";
	}*/
	if (isStair == -1) {
		cout << "use the stairs\n";
	}
	else {
		cout << isStair-1 << "\n";
	}

}