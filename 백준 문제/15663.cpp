// N°ú M (9) - 15663¹ø

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


void backTracking(int* arr, int* res, bool* vis, string* str, int n, int m, int k, int& j) {
	if (k == m) {
		string str2;
		for (int i = 0; i < m; i++) {
			str2.append(to_string(res[i]));
			str2.append(" ");
		}
		str[j]=str2;
		j++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			res[k] = arr[i];
			backTracking(arr, res, vis, str, n, m, k+1, j);
			vis[i] = false;
		}
	}
}
bool compareTo(string a, string b) {
	int aSt = 0;
	int bSt = 0;
	int aEn = 0;
	int bEn = 0;
	while (true) {
		
		aEn = a.find(" ", aSt);
		bEn = b.find(" ", bSt);
		if (aEn == string::npos) {
			return false;
		}
		
		if (stoi(a.substr(aSt, aEn - aSt)) > stoi(b.substr(bSt, bEn - bSt))) {
			return false;
		}
		else if (stoi(a.substr(aSt, aEn - aSt)) < stoi(b.substr(bSt, bEn - bSt))) {
			return true;
		}
		aSt = aEn + 1;
		bSt = bEn + 1;
	}
	
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0;
	cin >> n >> m;
	int* arr = new int[n];
	int* res = new int[m];
	bool* vis = new bool[n];
	int size = 1;
	for (int i = n; i > n - m; i--) {
		size *= i;
	}
	string* str = new string[size];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		vis[i] = false;
	}
	sort(arr, arr + n);
	int j = 0;
	backTracking(arr, res, vis, str, n, m, 0, j);
	sort(str, str + j, compareTo);
	for (int i = 0; i < j; i++) {
		if (i < j - 1) {
			if (str[i].compare(str[i + 1]) == 0) {
				continue;
			}
		}
		cout << str[i] << "\n";
	}
	delete[] arr;
	delete[] vis;
	delete[] res;
	delete[] str;

}