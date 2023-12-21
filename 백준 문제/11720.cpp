#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int n,sum=0;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < n; i++) {
		string cpy(1, str[i]);
		sum += stoi(cpy);
	}
	cout << sum;
}