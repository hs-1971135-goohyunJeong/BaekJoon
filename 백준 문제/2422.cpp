#include <iostream>
#include <vector>

using namespace std;

bool isBan(vector<int> ban[], int icecream[], int m, int k, int target) {
	for (int i = 0; i < k; i++) {
		//cout << ban[icecream[i]].size() << "\n";
		for (int j = 0; j < ban[icecream[i]].size(); j++) {
			if (ban[icecream[i]].at(j) == target) {
				return true;
			}
		}
	}
	return false;
}
void backTracking(vector<int> ban[], int icecream[], int k, long long& count, int n, int m, int start) {
	if (k == 3) {
		count++;
		return;
	}
	for (int i = start; i <= n; i++) {
		icecream[k] = i;
		bool isSkip = isBan(ban, icecream, m, k, i);
		if (isSkip) {
			continue;
		}
		backTracking(ban, icecream, k + 1, count, n, m, i+1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>* ban = new vector<int>[n+1];
	for (int i = 0; i <= n; i++) {
		ban[i].push_back(0);
	}
	int icecream[3];

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ban[a].push_back(b);
		ban[b].push_back(a);
	}
	long long count = 0;
	backTracking(ban, icecream, 0, count, n, m, 1);
	cout << count;
}