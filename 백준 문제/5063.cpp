//น้มุ : TGN - 5063น๘

#include <iostream>

using namespace std;

int main(void) {
	int t = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		int r = 0, e = 0, c = 0;
		cin >> r >> e >> c;

		if (e-c > r) {
			cout << "advertise\n";
		}
		else if (e-c == r) {
			cout << "does not matter\n";
		}
		else {
			cout << "do not advertise\n";
		}
	}
}