// RGB°Å¸® - 1149¹ø

#include <iostream>
#include <vector>
#include <algorithm>

#define R 0
#define G 1
#define B 2
using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	vector<int> red;
	vector<int> green;
	vector<int> blue;
	int** cost = new int*[n];
	for (int i = 0; i < n; i++) {
		int r = 0, g = 0, b = 0;
		cin >> r >> g >> b;
		red.push_back(r);
		green.push_back(g);
		blue.push_back(b);
		cost[i] = new int[3];
	}
	cost[0][R] = red.at(0);
	cost[0][G] = green.at(0);
	cost[0][B] = blue.at(0);
	for (int i = 1; i < n; i++) {
		cost[i][R] = min(cost[i - 1][G], cost[i - 1][B]) + red[i];
		cost[i][G] = min(cost[i - 1][R], cost[i - 1][B]) + green[i];
		cost[i][B] = min(cost[i - 1][G], cost[i - 1][R]) + blue[i];
	}
	cout << min({ cost[n - 1][R], cost[n - 1][B], cost[n - 1][G] });
	
	for (int i = 0; i < n; i++) {
		delete[] cost[i];
	}
	delete[] cost;
}