// 돌 굴러가유 23889번


// 아이디어 : 
// 돌을 굴리는 시점에 벽을 세우면 모래성을 가장 적게 부술수 있다. + 많이 부수는 돌을 막으면 된다.
// 돌을 굴리는 도시에서 다음 돌을 굴리는 도시까지 파괴되는 모래성이 가장 많은 것을 m개 고르면 된다.
// ex) 1 4 5 도시에서 돌을 굴리면 
// 돌이 1에서 출발해서 4까지 가는데 모래성을 얼마나 부수는지
// 돌이 4에서 출발해서 5까지 가는데 모래성을 얼마나 부수는지
// 돌이 5에서 출발해서 끝까지 가는데 모래성을 얼마나 부수는지
// 계산 후에 모래성을 많이 부수는 m개를 고르기

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int idx; //돌이 구르는 위치
	int count; // 돌이 부수는 모래성의 개수
}Pair;


int compare(Pair a, Pair b) {
	if (a.count == b.count) { // 만약 가장 많은 모래성을 지킬수있는 경우가 2가지 일 경우 사전순으로 정렬 
		return a.idx < b.idx;
	}
	return a.count > b.count;
}

// startPoint에서 돌을 굴리고 endPoint에서 돌이 멈춘다고 가정할 때 얼마나 많은 모래성을 부수는지 계산
int howManyDestroy(int* city, int startPoint, int endPoint) {
	int sum = 0;
	for (int i = startPoint; i < endPoint; i++) {
		sum += city[i];
	}
	return sum;
}

int main(void) {
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k; // n : 도시의 개수 m : 벽의 개수 k : 돌의 개수
	int* city = new int[n]; // 각 도시에 얼마나 많은 모래성을 가지는지 저장
	int* rock = new int[k]; // 돌이 구르기 시작하는 지점을 저장
	int* wall = new int[m]; // 벽을 세워야 하는 위치를 저장
	Pair* arr = new Pair[k]; // 돌이 구르기 시작하는 위치와 그 때 부수게 되는 모래성의 개수를 저장
	for (int i = 0; i < n; i++) {
		cin >> city[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> rock[i];
		rock[i]--; //인덱스는 0부터 시작하지만, 돌이 구르는 위치는 1부터 시작하므로 1을 빼준다
	}


	for (int i = 0; i < k; i++) {
		if (i == k - 1) { // 마지막 돌을 굴리면 그 돌은 마지막 도시까지 모래성을 부순다.
			arr[i].count = howManyDestroy(city, rock[i], n);
			arr[i].idx = rock[i];
		}
		else { // 그외의 돌은 다음에 굴려질 돌에서 멈춘다.
			arr[i].count = howManyDestroy(city, rock[i], rock[i + 1]);
			arr[i].idx = rock[i];
		}

	}
	sort(arr, arr + k, compare); // 모래성을 많이 부순 순서로 정렬
	
	for (int i = 0; i < m; i++) { // 벽을 쳐야하는 위치를 저장
		wall[i] = arr[i].idx + 1;
	}
	sort(wall, wall + m); // 위치를 오름차순으로 정렬 
	for (int i = 0; i < m; i++) {
		cout << wall[i] << "\n";
	}

	delete[] arr;
	delete[] wall;
	delete[] rock;
	delete[] city;
}