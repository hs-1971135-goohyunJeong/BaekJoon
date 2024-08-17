// 백준 : 등수 구하기 - 1205번

#include <iostream>
#include <vector>
using namespace std;

// 점수는 내림차순으로 주어지며 새로운 점수가 기존 랭킹의 점수와 동점일 경우에는 
// 새로운 점수에 더 높은 랭킹에 매겨진다. 단, 랭킹이 꽉차 있는 경우는 기존 랭킹 점수보다 높아야 랭킹에 매겨진다.
// 
int findRanking(vector<int>& list, int p, int score) {
	int result = 1;
	// 랭킹에 아무것도 없는 경우는 무조건 1등임
	if (list.size() == 0) {
		return 1;
	}
	// 랭킹에 들수 있는 점수보다 작거나 같으면 랭킹에 들지 못한다. 
	// => 가장 작은 랭킹 점수는 p번째 점수 이므로 p 보다 커야 랭킹에 들수 있음
	if (list.size() >= p && score <= list.at(p-1)) {
		return -1;
	}
	// 앞의 경우를 제외하면 랭킹에 들 수 있는 점수에 해당되면서 동점일 경우 더 높은 랭킹에 매겨짐
	for (int i = 0; i < list.size(); i++) {
		if (score >= list.at(i)) {
			break;
		}
		result++;
	}

	return result;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	int p = 0;
	int score = 0;
	vector<int> list;
	cin >> n >> score >> p;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		list.push_back(tmp);
	}
	cout << findRanking(list, p, score);
}