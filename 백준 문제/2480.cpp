#include <iostream>

using namespace std;

int main() {
	int dice1, dice2, dice3;
	int reward = 0;
	cin >> dice1 >> dice2 >> dice3;
	if (dice1 == dice2) {
		if (dice2 == dice3) {
			reward = 10000 + dice1 * 1000;
		}
		else {
			reward = 1000 + dice1 * 100;
		}
	}
	else {
		if (dice1 == dice3) {
			reward = 1000 + dice1 * 100;
		}
		else if (dice2 == dice3) {
			reward = 1000 + dice2 * 100;
		}
		else {
			if (dice1 > dice2) {
				if (dice1 > dice3) {
					reward = dice1 * 100;
				}
				else {
					reward = dice3 * 100;
				}
			}
			else {
				if (dice2 > dice3) {
					reward = dice2 * 100;
				}
				else {
					reward = dice3 * 100;
				}
			}
		}
	}

	cout << reward;

}