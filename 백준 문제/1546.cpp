#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	double* score = new double[num];
	double max = 0;
	for (int i = 0; i < num; i++) {
		cin >> score[i];
	}
	for (int i = 0; i < num; i++) {
		if (max < score[i]) {
			max = score[i];
		}
	}
	for (int i = 0; i < num; i++) {
		score[i] = (score[i] / max) * 100;
	}
	double sum = 0;
	for (int i = 0; i < num; i++) {
		sum += score[i];
	}
	cout << sum / num;
}