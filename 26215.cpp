 //�� ġ��� 26215��

#include <iostream>
#include <algorithm>
using namespace std;

//�׻� ���� ���� ���� ���� ���� �켱������ ġ�쵵���Ѵ�
int sweep(int* arr, int n) {
	int minutes = 0;
	int fp = n-1;// ���� ���� ���� ���� ���� ����Ű�� ������, ���� ���� ���� ���� ���� ������ �ε����� ��
	int sp = 0;
	if (n == 1) { // ���� �ϳ��� ���� ����ŭ �ð��� �ɸ�
		if (arr[0] > 1440) {
			return -1;
		}
		return arr[0];
	}
	while (true) {
		sort(arr, arr + n); // ���� ���� ���� ������������ ���� -> ���� ���� ���� ���� ������ �ε����� ��
		if (arr[fp] <= 0) { // ���� ���� ���� ���� ���� 0�����̸� �ݺ� ����
			break;
		}
		
		arr[fp]--;
		if (sp >= 0) { // sp�� ������ sp�� ���̻� ġ�� ���� ����
			if (arr[sp] > 0) { // sp�� ����Ű�� ���� ���� ���� �׿��ִ� ���
				arr[sp]--;
			}
			else { // sp�� ����Ű�� ���� ���̻� ���� ���� ���
				sp++;
				if (fp != sp) { // sp�� ����Ű�� ���� ���� ���� ���� ���� �ƴ϶�� -> �ٸ� ���� ���� ���� ���Ҵٸ�
					arr[sp]--;
				}
				else { // ���� ���� ���� �ϳ��ۿ� ���ٸ�
					sp = -1; 
				}
			}
		}
		minutes++;
	}
	if (minutes > 1440) {
		minutes = -1;
	}
	return minutes;
}



int main(void) {
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	
	cout << sweep(arr, n);
	delete[] arr;
}