#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		vec.push_back(tmp);
	}
	stack<int> line;
	int number = 1;
	int vecIndex = 0;
	bool isCan = true;
	while(true) {
		if (!line.empty() && line.top() == number) {
			line.pop();
			number++;
		}
		else if(vec.at(vecIndex) == number) {
			vecIndex++;
			number++;
		}
		else if (vec.at(vecIndex) > number) {
			line.push(vec.at(vecIndex));
			vecIndex++;
		}

		if (number > n) {
			break;
		}
		else if (vecIndex >= n) {
			isCan = false;
			break;
		}
	}
	while (!line.empty()) {
		if (number != line.top()) {
			isCan = false;
			break;
		}
		isCan = true;
		line.pop();
		number++;
	}
	if (isCan) {
		cout << "Nice";
	}
	else {
		cout << "Sad";
	}
}