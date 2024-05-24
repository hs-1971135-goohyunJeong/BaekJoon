// 백준 : 진짜 공간 - 1350번

#include <iostream>
#include <vector>
using namespace std;


long long getCount(vector<long long>& files, int size) {
	long long count = 0;

	for (int i = 0; i < files.size(); i++) {
		int tmp = files.at(i) / size;
		if (files.at(i) % size != 0) {
			tmp++;
		}
		count += tmp;
	}
	return count;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	vector<long long> files;
	int size = 0;
	cin >> n; 
	for (int i = 0; i < n; i++) {
		long long tmp = 0;
		cin >> tmp;
		files.push_back(tmp);
	}
	cin >> size;
	long long count = getCount(files, size);
	cout << count * size;
}