#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int a = 0, b = 0, v = 0;
	cin >> a >> b >> v;
	cout << (int)(ceil((double)(v-a)/(a-b)))+1;
}