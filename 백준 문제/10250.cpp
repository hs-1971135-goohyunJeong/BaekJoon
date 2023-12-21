#include <iostream>
#include <string>

using namespace std;

string calc(int h, int w, int n) {
	string result="";
	int x = 0;
	int y = 0;
	while (true) {
		n -= h;
		x++;
		if (n <= 0) {
			n += h;
			break;
		}
		
	}
	y = n;
	string tmp = to_string(y);
	result.append(tmp);
	tmp = to_string(x);
	if (x < 10) {
		result.append("0");
		result.append(tmp);
	}
	else {
		result.append(tmp);
	}
	
	return result;
}
int main(void) {
	int t;
	cin >> t;
	string* str = new string[t];
	for (int i = 0; i < t; i++) {
		int h, w, n;
		cin >> h >> w >> n;
		str[i] = calc(h, w, n);
	}
	for (int i = 0; i < t; i++) {
		cout << str[i] << endl;
	}
	delete[] str;
}