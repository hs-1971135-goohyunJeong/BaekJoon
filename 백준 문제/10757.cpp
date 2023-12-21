#include <iostream>
#include <string>

using namespace std;

void initStr(string str ,int arr[]) {
	for (int i = 0; i < str.length(); i++) {
		string newStr = string(1,str[i]);
		arr[i] = stoi(newStr);
	}
}
void init(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

void add(int aa[], int bb[],int result[] ,int aSize, int bSize,int resultSize, int min) {
	int i = aSize-1;
	int j = bSize-1;
	int k = resultSize-1;
	while(true) {
		int keep = result[k];
		result[k] = (keep+aa[i] + bb[j]) % 10;
		result[k - 1] = (result[k-1] + keep + aa[i] + bb[j]) / 10;
		i--;
		j--;
		k--;
		if (i < 0 || j < 0) {
			break;
		}
	}
	if (i >= 0) {
		for (; i >= 0; i--) {
			if (result[k] + aa[i] >= 10) {
				result[k - 1] += (aa[i] + result[k]) / 10;
			}
			result[k] = (result[k]+ aa[i])%10;
			
			k--;
		}
		
	}
	else if (j >= 0) {
		for (; j >= 0; j--) {
			if (result[k] + bb[j] >= 10) {
				result[k - 1] += (bb[j] + result[k]) / 10;
			}
			result[k] = (result[k] + bb[j]) % 10;
			k--;
		}
	}
}
void show(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (i==0 && arr[i] == 0) {
			continue;
		}
		cout << arr[i];
	}
}

int main(void) {
	string a, b;
	cin >> a >> b;
	int* aa = new int[a.length()];
	int* bb = new int[b.length()];
	initStr(a,aa);
	initStr(b,bb);
	int min = a.length() < b.length() ? a.length() : b.length();
	int max = a.length() > b.length() ? a.length() : b.length();
	int* result = new int[max + 1];
	init(result, max + 1);
	add(aa, bb, result, a.length(), b.length(), max+1, min);
	show(result, max + 1);
	delete[] aa;
	delete[] bb;
	delete[] result;
}