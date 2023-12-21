#include <iostream>

using namespace std;

int main(void) {
	int n = 0, k = 0;
	cin >> n >> k;
	int female[6] = { 0 };
	int male[6] = { 0 };
	int gen = 0;
	int year = 0;
	for (int i = 0; i < n; i++) {
		cin >> gen >> year;
		if (gen == 0) {
			female[year - 1]++;
		}
		else {
			male[year - 1]++;
		}
	}
	int count = 0;
	
	for (int i = 0; i < 6; i++) {
		if (female[i] % k == 0) {
			count  += female[i] / k;
		}
		else {
			count += female[i] / k + 1;
		}
	}
	for (int i = 0; i < 6; i++) {
		if (male[i] % k == 0) {
			count += male[i] / k;
		}
		else {
			count += male[i] / k + 1;
		}
	}
	cout << count;
}