// 백준 : 한조서열정리하고옴ㅋㅋ - 14659번

#include <iostream>
#include <vector>

using namespace std;

// 자신보다 더 작은 것을 만나면 end 인덱스를 늘리고
// 자신보다 더 큰 것을 만나면 start 인덱스를 늘림
// 이 때 더 큰 것을 만나면 end-start-1(둘 사이의 길이?)을 배열에 저장
// start 인덱스와 end 인덱스가 같으면 두개가 가리키는 것이 같으므로 end 증가
// 인덱스 둘 중 하나라도 끝에 도달하면 end-start-1을 배열에 저장
// 배열에 저장된 것중 가장 큰 값이 정답
int solve(vector<int>& height, vector<int>& table) {
	int start = 0;
	int end = 1;
	while (true) {
		if (start == end) {
			end++;
		}
		if (start > height.size() - 1 || end > height.size() - 1) {
			table.push_back(end - start-1);
			break;
		}
		if (height.at(start) > height.at(end)) {
			end++;
		}
		else {
			table.push_back(end - start-1);
			start++;
		}
	}
	int result = 0;
	for (int i = 0; i < table.size(); i++) {
		if (result < table.at(i)) {
			result = table.at(i);
		}
	}
	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	vector<int> height;
	vector<int> table;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		height.push_back(tmp);
	}
	cout << solve(height, table);
	
}