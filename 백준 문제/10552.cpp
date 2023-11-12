// DOM - 10552번

#include <iostream>
#include <vector>

using namespace std;

#define NOBODY 100000

// 각 채널마다 싫어하는 사람의 인덱스(가장 빠른 순으로)를 저장하고
// 현재 채널을 싫어하는 사람을 위에서 저장한 배열로 바로 접근한다.
// 그리고 나서 그 사람이 좋아하는 채널로 현재 채널을 바꾼다
// 만약 현재 채널이 이전에 나온적 있다면 무한루프에 빠진 것이므로 더이상의 탐색은 의미가 없다.

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0, p = 0;
	cin >> n >> m >> p;
	int* indexHate = new int[m+1];
	vector<int> favoriteChannel;
	vector<int> hateChannel;
	bool* visit = new bool[m+1];
	for (int i = 1; i <= m; i++) {
		indexHate[i] = NOBODY;
		visit[i] = false;
	}

	for (int i = 0; i < n; i++) {
		int love = 0;
		int hate = 0;
		cin >> love >> hate;
		// 해당 채널을 싫어하는 사람의 가장 빠른 번호를 저장 (인덱스는 채널번호, 저장값은 싫어하는 사람의 인덱스)
		if (i < indexHate[hate]) {
			indexHate[hate] = i;
		}
		favoriteChannel.push_back(love);
	}

	int count = 0;
	while (true) {
		// 무한루프에 빠짐
		if (visit[p] == true) {
			count = -1;
			break;
		}
		visit[p] = true;
		// 아무도 안싫어함
		if(indexHate[p] == NOBODY){
			break;
		}
		p = favoriteChannel.at(indexHate[p]);
		count++;
		
		
	}
	cout << count;
	delete[] indexHate;
}