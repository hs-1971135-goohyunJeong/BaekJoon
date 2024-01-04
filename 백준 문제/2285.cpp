// 우체국 - 2285번

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Node {
	int vil;
	int peo;
};
using namespace std;

long long calcDistance(vector<Node>& vec, int n, int idx) {
	long long distance = 0;
	for (int i = 0; i < n; i++) {
		distance = distance + abs(vec.at(i).vil - vec.at(idx).vil) * vec.at(i).peo;
	}
	return distance;
}

int findPost(vector<Node>& vec, int n) {
	int totalPeople = 0;
	for (int i = 0; i < n; i++) {
		totalPeople += vec.at(i).peo;
	}
	long long min = calcDistance(vec, n, 0);
	int idx = vec.at(0).vil;
	int nextPeople = totalPeople - vec.at(0).peo;
	int prevPeople = vec.at(0).peo;
	long long prevDistance = min;
	for (int i = 1; i < n; i++) {
		long long distance = prevDistance - nextPeople + prevPeople;
		if (min > distance) {
			min = distance;
			idx = vec.at(i).vil;
		}
		nextPeople -= vec.at(i).peo;
		prevPeople += vec.at(i).peo;
		prevDistance = distance;
	}
	return idx;
}

int findPost2(vector<Node>& vec, int n) {
	long long totalPeople = 0;
	for (int i = 0; i < n; i++) {
		totalPeople += vec.at(i).peo;
	}
	int idx = vec.at(0).vil;
	long long nextPeople = totalPeople;
	long long prevPeople = 0;
	for (int i = 0; i < n; i++) {
		nextPeople -= vec.at(i).peo;
		prevPeople += vec.at(i).peo;
		if (nextPeople <= prevPeople) {
			idx = vec.at(i).vil;
			return idx;
		}

	}
}
bool compare(Node& a, Node& b) {
	return a.vil < b.vil;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	int x = 0;
	int a = 0;
	vector<Node> vec;
	for (int i = 0; i < n; i++) {
		cin >> x >> a;
		Node node;
		node.vil = x;
		node.peo = a;
		vec.push_back(node);
	}
	sort(vec.begin(), vec.end(), compare);
	//cout << findPost(vec, n);
	//cout << "\n";
	cout << findPost2(vec, n);
}