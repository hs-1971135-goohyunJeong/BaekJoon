// ���� : �ӽ� ���� ���ϱ� - 1268��

#include <iostream>
#include <vector>
using namespace std;

// ���� ���� ���� ��ģ �л��� ã�� ���� �ƴ� ���� �پ��� �л���� ���� ���̾��� �л��� ã�� ����
// �г⺰�� ���� ����ΰ� ���� ���� ������ �� 2���� �迭�� �� �� ǥ��
// �������� ���� �پ��ϰ� ���� �л��� 2���� �迭���� Ȯ��
void clear(int** vec, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vec[i][j] = 0;
		}
	}
}
// ���� �л� ���� ����ϴ� �Լ�
int sum(int count[], int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += count[i];
	}
	return result;
}
// ���� ���̾��� �л����� 1�� ǥ��
void mark(int** count, vector<int>& arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] == arr[j]) { // ���� ���϶�
				count[i][j] = 1;
				count[j][i] = 1;
			}
		}
	}
}
// �л����� ���� ���̾����� Ȯ��
void check(int** std, int** count, int n) {
	for (int i = 0; i < 5; i++) {
		vector<int> arr; // �г� ���� �л����� � ���̾����� ����
		for (int j = 0; j < n; j++) {
			arr.push_back(std[j][i]);
		}
		mark(count, arr, n);
	}

}
int** createMat(int n, int m) {
	int** mat = new int* [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m];
	}
	return mat;
}
void deleteMat(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
void printMat(int** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	
	int leader = 1;
	int max = 0;
	cin >> n;
	int** std = createMat(n, 5);
	int** count = createMat(n, n);
	clear(count, n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			int tmp = 0;
			cin >> tmp;
			std[i][j] = tmp;
		}
	}
	check(std, count, n);
	//printMat(count, n, n);
	for (int i = 0; i < n; i++) {
		int tmp = sum(count[i], n);
		if (max < tmp) {
			max = tmp;
			leader = i + 1;
		}
	}
	cout << leader;
	deleteMat(std, n);
	deleteMat(count, n);
}