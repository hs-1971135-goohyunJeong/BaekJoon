// น้มุ : solved.ac - 18110น๘

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define LIMIT 0.15

int roundingOff(double a) {
	int tmp = a;
	if (a - tmp < 0.5f) {
		return tmp;
	}
	else {
		return tmp + 1;
	}
}

int calc(vector<int>& vec) {
	int n = vec.size();
	int upLimit = roundingOff((double)n * LIMIT);
	int downLimit = n - upLimit;
	double sum = 0;
	double count = 0.0f;
	for (int i = upLimit; i < downLimit; i++) {
		sum += vec.at(i);
		count++;
	}
	return round(sum / count);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	vector<int> vec = vector<int>();
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		vec.push_back(tmp);
	}
	if (vec.size() == 0) {
		cout << 0;
		return 0;
	}
	sort(vec.begin(), vec.end());
	cout << calc(vec);
}