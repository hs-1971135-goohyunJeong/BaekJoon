#include <iostream>

using namespace std;


void inputMatrix(int** arr,int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}
void addMatrix(int** first, int** second, int**result, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[i][j] = first[i][j] + second[i][j];
		}
	}
}
void showMatrix(int** arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	int** first = new int* [n];
	int** second = new int* [n];
	int** result= new int* [n];
	for (int i = 0; i < n; i++) {
		first[i] = new int[m];
		second[i] = new int[m];
		result[i] = new int[m];
	}
	inputMatrix(first, n, m);
	inputMatrix(second, n, m);
	addMatrix(first, second, result, n, m);
	showMatrix(result, n, m);
	delete[] first;
	delete[] second;
	delete[] result;
}