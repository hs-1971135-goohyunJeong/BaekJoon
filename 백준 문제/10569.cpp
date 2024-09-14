// 백준 : 다면체 - 10569번

#include <iostream>

using namespace std;

// 면의 개수 = 2 - 정점 개수 + 모서리 개수

int main() {
	int t = 0;
	int v = 0, e = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> v >> e;
		cout << 2 - v + e << "\n";
	}
	

}