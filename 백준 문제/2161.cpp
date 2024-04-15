// ���� : ī��1 - 2161��

#include <iostream>
#include <queue>

using namespace std;

// ī���� �� ó���� ������ ���� -> ť�� pop
// ī���� �� �ڷ� ������ ���� -> ť�� push
void solve(queue<int>& q) {
	while (q.size()> 1) {
		cout << q.front() << " ";
		q.pop();
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << q.front();
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> q;
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	solve(q);

}