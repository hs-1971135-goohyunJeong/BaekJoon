// 배열 합치기 - 11728번

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, vector<int>& brr, vector<int>& crr, int n, int m) {
	int aIndex = 0;
	int bIndex = 0;
	bool aReach = false;
	bool bReach = false;
	while (true) {
		if (arr.at(aIndex) < brr.at(bIndex)) {
			crr.push_back(arr.at(aIndex));
			aIndex++;
		}
		else {
			crr.push_back(brr.at(bIndex));
			bIndex++;
		}
		if (aIndex >= n) {
			aReach = true;
			break;
		}
		if (bIndex >= m) {
			bReach = true;
			break;
		}
	}
	if (aReach) {
		for (bIndex; bIndex < m; bIndex++) {
			crr.push_back(brr.at(bIndex));
		}
	}
	if (bReach) {
		for (aIndex; aIndex < n; aIndex++) {
			crr.push_back(arr.at(aIndex));
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> arr = vector<int>();
	vector<int> brr = vector<int>();
	vector<int> crr = vector<int>();
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		brr.push_back(tmp);
	}
	merge(arr, brr, crr, n, m);
	for (int i = 0; i < n + m; i++) {
		cout << crr.at(i) << " ";
	}

}