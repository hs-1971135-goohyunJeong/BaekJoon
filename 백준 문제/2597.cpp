// ���� : �������� - 2597��

#include <iostream>
#include <iomanip>

using namespace std;

void swap(double& a, double& b) {
	double tmp = a;
	a = b;
	b = tmp;
}

// idx �� ��� ������ �÷� (0 : R, 1 : B, 2 :Y)
void fold(double& length, double left[], double right[], double pos, int idx) {
	// �޺κ��� ���� ��
	if (pos > length / 2) {
		length = pos;
		for (int i = 0; i < 3; i++) {
			// pos ���� �ڿ� �ִ� �͵��� pos ���� �Ÿ���ŭ pos �� ������ �Ѿ 
			if (left[i] > pos) {
				double step = left[i] - pos; // �Ѿ�� �Ÿ� ���
				left[i] = pos - step;
			}
			if (right[i] > pos) {
				double step = right[i] - pos;
				right[i] = pos - step;
			}
			if (i == idx) { // idx ��°�� left �� right �� ��ġ�ϰԵ�
				left[idx] = right[idx];
			}
			if (left[i] > right[i]) {
				swap(left[i], right[i]);
			}
		}
	}
	// �պκ��� ���� ��
	else {
		length = length - pos;
		for (int i = 0; i < 3; i++) {
			// pos ���� �տ� �ִ� �͵��� pos ���� �Ÿ���ŭ pos �� �ڷ� �Ѿ 
			if (left[i] < pos) {
				double step = pos - left[i]; // �Ѿ�� �Ÿ� ���
				left[i] = pos + step;
			}
			if (right[i] < pos) {
				double step = pos - right[i];
				right[i] = pos + step;
			}
			if (i == idx) { // idx ��°�� left �� right �� ��ġ�ϰԵ�
				right[idx] = left[idx];
			}
			if (left[i] > right[i]) {
				swap(left[i], right[i]);
			}
			// �պκ��� ������ pos �� ������(0)���� �ΰ� �ٽ� ��ǥ�� ����ؾ���
			left[i] -= pos;
			right[i] -= pos;
		}
	}
	
}

int main(void) {
	double length = 0;
	double left[3];
	double right[3];
	cin >> length;
	for (int i = 0; i < 3; i++) {
		cin >> left[i] >> right[i];
	}
	for (int i = 0; i < 3; i++) {
		if (left[i] == right[i]) {
			continue;
		}
		// ������ ��ġ ��� 
		double pos = (left[i] + right[i]) / 2.0;
		fold(length, left, right, pos, i);
		//cout << fixed << setprecision(1) << length << "\n";
	}

	cout << fixed << setprecision(1) << length <<"\n";

}