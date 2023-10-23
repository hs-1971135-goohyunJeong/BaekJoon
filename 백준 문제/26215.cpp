 //눈 치우기 26215번

#include <iostream>
#include <algorithm>
using namespace std;

//항상 가장 많은 눈이 쌓인 곳을 우선적으로 치우도록한다
int sweep(int* arr, int n) {
	int minutes = 0;
	int fp = n-1;// 가장 눈이 많이 쌓인 곳을 가리키는 포인터, 눈이 가장 많은 곳은 가장 마지막 인덱스가 됨
	int sp = 0;
	if (n == 1) { // 집이 하나면 쌓인 눈만큼 시간이 걸림
		if (arr[0] > 1440) {
			return -1;
		}
		return arr[0];
	}
	while (true) {
		sort(arr, arr + n); // 눈이 쌓인 곳을 오름차순으로 정렬 -> 눈이 가장 많은 곳은 마지막 인덱스가 됨
		if (arr[fp] <= 0) { // 눈이 가장 많이 쌓인 곳이 0이하이면 반복 종료
			break;
		}
		
		arr[fp]--;
		if (sp >= 0) { // sp가 음수면 sp는 더이상 치울 눈이 없음
			if (arr[sp] > 0) { // sp가 가리키는 집이 아직 눈이 쌓여있는 경우
				arr[sp]--;
			}
			else { // sp가 가리키는 집이 더이상 눈이 없는 경우
				sp++;
				if (fp != sp) { // sp가 가리키는 곳이 눈이 가장 많은 곳이 아니라면 -> 다른 집이 아직 눈이 남았다면
					arr[sp]--;
				}
				else { // 눈이 남은 집이 하나밖에 없다면
					sp = -1; 
				}
			}
		}
		minutes++;
	}
	if (minutes > 1440) {
		minutes = -1;
	}
	return minutes;
}



int main(void) {
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	
	cout << sweep(arr, n);
	delete[] arr;
}