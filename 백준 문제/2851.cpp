// 백준 : 슈퍼 마리오 - 2851번

#include <iostream>

using namespace std;
#define SIZE 10

// 100을 넘기면 100을 넘기전의 값과 비교하여 100에 가까운 것을 결과로 삼는다.
int solve(int arr[]) {
	int sum = 0;
	int i;
	for (i = 0; i < SIZE; i++) {
		sum += arr[i];
		if (sum >= 100) {
			break;
		}
	}
	
	if (sum != 100) {
		int compare = sum - arr[i];
		if (sum - 100 > 100 - compare) {
			sum = compare;
		}
	}
	return sum;
	
}
int main() {
	int arr[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}
	cout << solve(arr);
	
}