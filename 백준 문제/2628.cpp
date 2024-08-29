// 백준 : 종이자르기 - 2628번

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 큰 면적을 갖는 사각형 => 직선으로 종이를 자르기 때문에 너비와 높이가 가장 길다.

// 가장 긴 길이를 재는 함수 (높이던 너비던)
int calc(vector<int>& vec) {
	int max = 0;
	for (int i = 1; i < vec.size(); i++) {
		int offset = 0;
		offset = vec.at(i) - vec.at(i - 1);
		if (max < offset) {
			max = offset;
		}
	}
	return max;
}
// 가장 큰 너비와 높이를 곱하는 함수
void solve(vector<int>& cx, vector<int>& cy) {
	int maxX = 0;
	int maxY = 0;
	maxX = calc(cx);
	maxY = calc(cy);
	cout << maxX * maxY;
	

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x= 0;
	int y = 0;
	int count = 0;
	// 자르는 위치를 저장 하는 벡터
	vector<int> cx;
	vector<int> cy;
	cin >> x >> y;
	cin >> count;
	cx.push_back(0);
	cy.push_back(0);
	for (int i = 0; i < count; i++) {
		int direct = 0;
		int tmp = 0;
		cin >> direct >> tmp;
		// 자르는 방향과 자르는 위치는 반대이다. 가로로 자르는 경우 세로의 위치를 저장해야함
		if (direct == 0) {
			cy.push_back(tmp);
		}
		else {
			cx.push_back(tmp);
		}
	}
	cx.push_back(x);
	cy.push_back(y);

	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());

	solve(cx, cy);
}