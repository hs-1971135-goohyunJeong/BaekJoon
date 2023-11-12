// DOM - 10552��

#include <iostream>
#include <vector>

using namespace std;

#define NOBODY 100000

// �� ä�θ��� �Ⱦ��ϴ� ����� �ε���(���� ���� ������)�� �����ϰ�
// ���� ä���� �Ⱦ��ϴ� ����� ������ ������ �迭�� �ٷ� �����Ѵ�.
// �׸��� ���� �� ����� �����ϴ� ä�η� ���� ä���� �ٲ۴�
// ���� ���� ä���� ������ ������ �ִٸ� ���ѷ����� ���� ���̹Ƿ� ���̻��� Ž���� �ǹ̰� ����.

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0, p = 0;
	cin >> n >> m >> p;
	int* indexHate = new int[m+1];
	vector<int> favoriteChannel;
	vector<int> hateChannel;
	bool* visit = new bool[m+1];
	for (int i = 1; i <= m; i++) {
		indexHate[i] = NOBODY;
		visit[i] = false;
	}

	for (int i = 0; i < n; i++) {
		int love = 0;
		int hate = 0;
		cin >> love >> hate;
		// �ش� ä���� �Ⱦ��ϴ� ����� ���� ���� ��ȣ�� ���� (�ε����� ä�ι�ȣ, ���尪�� �Ⱦ��ϴ� ����� �ε���)
		if (i < indexHate[hate]) {
			indexHate[hate] = i;
		}
		favoriteChannel.push_back(love);
	}

	int count = 0;
	while (true) {
		// ���ѷ����� ����
		if (visit[p] == true) {
			count = -1;
			break;
		}
		visit[p] = true;
		// �ƹ��� �ȽȾ���
		if(indexHate[p] == NOBODY){
			break;
		}
		p = favoriteChannel.at(indexHate[p]);
		count++;
		
		
	}
	cout << count;
	delete[] indexHate;
}