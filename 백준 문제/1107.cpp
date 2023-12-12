// 리모컨 - 1107번

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int calcSize(int n) {
	int size = 0;
	while (true) {
		if (n / 10 == 0) {
			size++;
			break;
		}
		n /= 10;
		size++;
	}
	return size;
}
void moveChannel(string& n, vector<int> except, int& count, string& arr, int k, bool first) {
	if (n.length() <= k) {
		int des = stoi(n);
		int cur = stoi(arr);
		int tmp = calcSize(cur);
		tmp += abs(des - cur);
		//cout << arr << " " << tmp << "\n";
		if (tmp < count) {
			count = tmp;
		}
		if (count > abs(des - 100)) {
			count = abs(des - 100);
		}
		return;
	}
	
	for (int i = 0; i < 10; i++) {
		bool isExcept = false;
		for (int j = 0; j < except.size(); j++) {
			if (i == except.at(j)) {
				isExcept = true;
				break;
			}
		}
		if (isExcept) {
			continue;
		}
		// 자리수에 맞게 탐색 (1000 일때 1000~9999 탐색)
		arr.append(to_string(i));
		moveChannel(n, except, count, arr, k + 1, false);
		arr.pop_back();
		if (k == 0&& first) {
			// 자리수보다 1개 더 적게 탐색 (1000 일때 999 도 찾아봐야함)
			arr.append(to_string(i));
			moveChannel(n, except, count, arr, k + 2, false);
			arr.pop_back();

			// 자리수보다 1개 더 많게 탐색 (999 일때 1000 도 찾아봐야함)
			arr.append(to_string(i));
			moveChannel(n, except, count, arr, k, false);
			arr.pop_back();
		}

	}
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string n;
	int m = 0;
	cin >> n >> m;
	vector<int> except;
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		cin >> tmp;
		except.push_back(tmp);
	}
	string arr;
	// 예외 상황
	if (m == 10) {
		cout << abs(stoi(n) - 100);
		return 0;
	}
	int count = INT32_MAX;
	moveChannel(n, except, count, arr, 0, true);
	cout << count;
}