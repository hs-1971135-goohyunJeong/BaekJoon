// 백준 : 임시 반장 정하기 - 1268번

#include <iostream>
#include <vector>
using namespace std;

// 가장 많이 반이 겹친 학생을 찾는 것이 아닌 가장 다양한 학생들과 같은 반이었던 학생을 찾는 것임
// 학년별로 반을 적어두고 같은 반을 만났을 때 2차원 배열에 둘 다 표시
// 마지막에 가장 다양하게 만난 학생을 2차원 배열에서 확인
void clear(int** vec, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vec[i][j] = 0;
		}
	}
}
// 만난 학생 수를 계산하는 함수
int sum(int count[], int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += count[i];
	}
	return result;
}
// 같은 반이었던 학생들을 1로 표시
void mark(int** count, vector<int>& arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] == arr[j]) { // 같은 반일때
				count[i][j] = 1;
				count[j][i] = 1;
			}
		}
	}
}
// 학생들이 같은 반이었는지 확인
void check(int** std, int** count, int n) {
	for (int i = 0; i < 5; i++) {
		vector<int> arr; // 학년 마다 학생들이 어떤 반이었는지 저장
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