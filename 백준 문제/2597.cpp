// 백준 : 줄자접기 - 2597번

#include <iostream>
#include <iomanip>

using namespace std;

void swap(double& a, double& b) {
	double tmp = a;
	a = b;
	b = tmp;
}

// idx 는 접어서 포개는 컬러 (0 : R, 1 : B, 2 :Y)
void fold(double& length, double left[], double right[], double pos, int idx) {
	// 뒷부분이 접힐 때
	if (pos > length / 2) {
		length = pos;
		for (int i = 0; i < 3; i++) {
			// pos 보다 뒤에 있는 것들은 pos 와의 거리만큼 pos 의 앞으로 넘어감 
			if (left[i] > pos) {
				double step = left[i] - pos; // 넘어가는 거리 계산
				left[i] = pos - step;
			}
			if (right[i] > pos) {
				double step = right[i] - pos;
				right[i] = pos - step;
			}
			if (i == idx) { // idx 번째는 left 와 right 가 일치하게됨
				left[idx] = right[idx];
			}
			if (left[i] > right[i]) {
				swap(left[i], right[i]);
			}
		}
	}
	// 앞부분이 접힐 때
	else {
		length = length - pos;
		for (int i = 0; i < 3; i++) {
			// pos 보다 앞에 있는 것들은 pos 와의 거리만큼 pos 의 뒤로 넘어감 
			if (left[i] < pos) {
				double step = pos - left[i]; // 넘어가는 거리 계산
				left[i] = pos + step;
			}
			if (right[i] < pos) {
				double step = pos - right[i];
				right[i] = pos + step;
			}
			if (i == idx) { // idx 번째는 left 와 right 가 일치하게됨
				right[idx] = left[idx];
			}
			if (left[i] > right[i]) {
				swap(left[i], right[i]);
			}
			// 앞부분이 접히면 pos 를 시작점(0)으로 두고 다시 좌표를 계산해야함
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
		// 접히는 위치 계산 
		double pos = (left[i] + right[i]) / 2.0;
		fold(length, left, right, pos, i);
		//cout << fixed << setprecision(1) << length << "\n";
	}

	cout << fixed << setprecision(1) << length <<"\n";

}