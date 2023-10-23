// �� �������� 23889��


// ���̵�� : 
// ���� ������ ������ ���� ����� �𷡼��� ���� ���� �μ��� �ִ�. + ���� �μ��� ���� ������ �ȴ�.
// ���� ������ ���ÿ��� ���� ���� ������ ���ñ��� �ı��Ǵ� �𷡼��� ���� ���� ���� m�� ���� �ȴ�.
// ex) 1 4 5 ���ÿ��� ���� ������ 
// ���� 1���� ����ؼ� 4���� ���µ� �𷡼��� �󸶳� �μ�����
// ���� 4���� ����ؼ� 5���� ���µ� �𷡼��� �󸶳� �μ�����
// ���� 5���� ����ؼ� ������ ���µ� �𷡼��� �󸶳� �μ�����
// ��� �Ŀ� �𷡼��� ���� �μ��� m���� ����

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int idx; //���� ������ ��ġ
	int count; // ���� �μ��� �𷡼��� ����
}Pair;


int compare(Pair a, Pair b) {
	if (a.count == b.count) { // ���� ���� ���� �𷡼��� ��ų���ִ� ��찡 2���� �� ��� ���������� ���� 
		return a.idx < b.idx;
	}
	return a.count > b.count;
}

// startPoint���� ���� ������ endPoint���� ���� ����ٰ� ������ �� �󸶳� ���� �𷡼��� �μ����� ���
int howManyDestroy(int* city, int startPoint, int endPoint) {
	int sum = 0;
	for (int i = startPoint; i < endPoint; i++) {
		sum += city[i];
	}
	return sum;
}

int main(void) {
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k; // n : ������ ���� m : ���� ���� k : ���� ����
	int* city = new int[n]; // �� ���ÿ� �󸶳� ���� �𷡼��� �������� ����
	int* rock = new int[k]; // ���� ������ �����ϴ� ������ ����
	int* wall = new int[m]; // ���� ������ �ϴ� ��ġ�� ����
	Pair* arr = new Pair[k]; // ���� ������ �����ϴ� ��ġ�� �� �� �μ��� �Ǵ� �𷡼��� ������ ����
	for (int i = 0; i < n; i++) {
		cin >> city[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> rock[i];
		rock[i]--; //�ε����� 0���� ����������, ���� ������ ��ġ�� 1���� �����ϹǷ� 1�� ���ش�
	}


	for (int i = 0; i < k; i++) {
		if (i == k - 1) { // ������ ���� ������ �� ���� ������ ���ñ��� �𷡼��� �μ���.
			arr[i].count = howManyDestroy(city, rock[i], n);
			arr[i].idx = rock[i];
		}
		else { // �׿��� ���� ������ ������ ������ �����.
			arr[i].count = howManyDestroy(city, rock[i], rock[i + 1]);
			arr[i].idx = rock[i];
		}

	}
	sort(arr, arr + k, compare); // �𷡼��� ���� �μ� ������ ����
	
	for (int i = 0; i < m; i++) { // ���� �ľ��ϴ� ��ġ�� ����
		wall[i] = arr[i].idx + 1;
	}
	sort(wall, wall + m); // ��ġ�� ������������ ���� 
	for (int i = 0; i < m; i++) {
		cout << wall[i] << "\n";
	}

	delete[] arr;
	delete[] wall;
	delete[] rock;
	delete[] city;
}