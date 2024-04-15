// 백준 : 카드1 - 2161번

#include <iostream>
#include <queue>

using namespace std;

// 카드의 맨 처음을 빼내는 행위 -> 큐의 pop
// 카드의 맨 뒤로 보내는 행위 -> 큐의 push
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