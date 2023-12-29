#include <iostream>
#include <vector>

using namespace std;

void searchDivisor(int n, int arr[]) {
	int j = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			arr[j] = i;
			j++;
		}
	}
}
int sumDivisor(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}
int countDivisor(int n) {
	int count = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			count++;
		}
	}
	return count;
}
bool isPerfect(int n, int arr[], int count) {
	searchDivisor(n, arr);
	if (n == sumDivisor(arr, count)) {
		return true;
	}
	else {
		return false;
	}

	
}
void resultPrint(int n) {
	int count = countDivisor(n);
	int* arr = new int[count];
	if (isPerfect(n, arr, count)) {
		cout << n << " = ";
		for (int i = 0; i < count-1; i++) {
			cout << arr[i] << " + ";
		}
		cout << arr[count - 1] << endl;
	}
	else {
		cout << n << " is NOT perfect." << endl;
	}
	delete[] arr;
}
int main(void) {
	vector <int> v;
	int i = 0;
	int n = 0;
	while (true) {
		cin >> n;
		v.push_back(n);
		if (v[i] == -1) {
			break;
		}
		i++;
	}
	i = 0;
	while (true) {
		if (v[i] == -1) {
			break;
		}
		resultPrint(v[i]);
		i++;
	}
}