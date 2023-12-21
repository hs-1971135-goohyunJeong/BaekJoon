#include <iostream>

using namespace std;

int main() {
	int thour;
	int tminute;
	int time;

	cin >> thour >> tminute;
	cin >> time;

	thour += (tminute + time) / 60;
	tminute = (tminute + time) % 60;
	thour = thour % 24;

	cout << thour <<" " << tminute;

}