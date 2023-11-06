// Project Teams - 20044번

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이 접근 : 고만고만하게 팀을 짜려면 가장 점수가 낮은 애와 가장 점수가 높은 애를 같은 팀에 넣어야함
int main(void) {
	int n = 0;
	cin >> n;
	vector<int> scores;
	// 팀원인 두명의 점수를 합한 값을 저장하는 벡터
	vector<int> teamScores;
	int tmp = 0;
	for (int i = 0; i < 2 * n; i++) {
		cin >> tmp;
		scores.push_back(tmp);
	}
	// 점수를 정렬
	sort(scores.begin(), scores.end());
	// 낮은 순으로 절반을 입력
	for (int i = 0; i < n; i++) {
		teamScores.push_back(scores.at(i));
	}
	int j = 0;
	// 가장 낮은 애한테 가장 높은 애를 매칭해가면서 마지막엔 중간점수인 두명을 매칭해야함
	for (int i = 2 * n - 1; i >= n; i--) {
		teamScores[j] = teamScores[j]+scores[i];
		j++;
	}
	// 팀 점수를 정렬
	sort(teamScores.begin(), teamScores.end());
	cout << teamScores.at(0);
	return 0;
}