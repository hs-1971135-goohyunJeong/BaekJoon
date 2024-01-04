// �ñ׳� - 16113��

#include <iostream>
#include <vector>
using namespace std;

// ���̵�� : 1�� ������ ��� ���ڴ� 5 by 3 �� ������ �迭�� ǥ�� ����
// 1��  �������� ������ ����
// �Էµ� ���ڿ��� ���� 5 by cols �� ���·� �ٲ� �� ������ �迭�� ǥ���� ���ڿ� ������ ��
// 1�� �ι�° ������ �Ǿտ� 1�� �����ϴ� ���, ����° ������ �ǵڿ� 1�� ������ ��� (�� ������)
// �׿ܿ��� 1�� �־����� ���
// 5 ##### �� ����ó��

const char ZERO[5][3] = {
	'#','#','#',
	'#','.','#',
	'#','.','#',
	'#','.','#',
	'#','#','#',
};
const char ONE[5][3] = {
	'.','#','.',
	'.','#','.',
	'.','#','.',
	'.','#','.',
	'.','#','.',
};
const char ONEv2[5][2] = {
	'#','.',
	'#','.',
	'#','.',
	'#','.',
	'#','.',
};
const char ONEv3[5][2] = {
	'.','#',
	'.','#',
	'.','#',
	'.','#',
	'.','#',
};
const char TWO[5][3] = {
	'#','#','#',
	'.','.','#',
	'#','#','#',
	'#','.','.',
	'#','#','#',
};
const char THREE[5][3] = {
	'#','#','#',
	'.','.','#',
	'#','#','#',
	'.','.','#',
	'#','#','#',
};
const char FOUR[5][3] = {
	'#','.','#',
	'#','.','#',
	'#','#','#',
	'.','.','#',
	'.','.','#',
};
const char FIVE[5][3] = {
	'#','#','#',
	'#','.','.',
	'#','#','#',
	'.','.','#',
	'#','#','#',
};
const char SIX[5][3] = {
	'#','#','#',
	'#','.','.',
	'#','#','#',
	'#','.','#',
	'#','#','#',
};
const char SEVEN[5][3] = {
	'#','#','#',
	'.','.','#',
	'.','.','#',
	'.','.','#',
	'.','.','#',
};
const char EIGHT[5][3] = {
	'#','#','#',
	'#','.','#',
	'#','#','#',
	'#','.','#',
	'#','#','#',
};
const char NINE[5][3] = {
	'#','#','#',
	'#','.','#',
	'#','#','#',
	'.','.','#',
	'#','#','#',
};

void changeNumber(char** str, int rows, int cols) {
	char window[5][3] = { '.','.','.','.','.','.' ,'.','.','.' ,'.','.','.' ,'.','.','.' };
	bool isNotThis = false;
	vector<char> number;
	for (int i = 0; i < cols-2; i++) {
		isNotThis = false;
		window[0][0] = str[0][i];
		window[0][1] = str[0][i+1];
		window[0][2] = str[0][i+2];
		window[1][0] = str[1][i];
		window[1][1] = str[1][i + 1];
		window[1][2] = str[1][i + 2];
		window[2][0] = str[2][i];
		window[2][1] = str[2][i + 1];
		window[2][2] = str[2][i + 2];
		window[3][0] = str[3][i];
		window[3][1] = str[3][i + 1];
		window[3][2] = str[3][i + 2];
		window[4][0] = str[4][i];
		window[4][1] = str[4][i + 1];
		window[4][2] = str[4][i + 2];
		//for (int r = 0; r < 5; r++) {
		//	for (int c = 0; c < 3; c++) {
		//		cout << window[r][c];
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (window[r][c] != ZERO[r][c]) {
					isNotThis = true;
					break;
				}
			}
			if (isNotThis) {
				break;
			}
		}
		if (isNotThis == false) {
			number.push_back('0');
			continue;
		}
		isNotThis = false;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (window[r][c] != ONE[r][c]) {
					isNotThis = true;
					break;
				}
			}
			if (isNotThis) {
				break;
			}
		}
		if (isNotThis == false) {
			number.push_back('1');
			continue;
		}
		if (i == 0) {
			isNotThis = false;
			for (int r = 0; r < 5; r++) {
				for (int c = 0; c < 2; c++) {
					if (window[r][c] != ONEv2[r][c]) {
						isNotThis = true;
						break;
					}
				}
				if (isNotThis) {
					break;
				}
			}
			if (isNotThis == false) {
				number.push_back('1');
				continue;
			}
		}
		if (i == cols - 3) {
			isNotThis = false;
			for (int r = 0; r < 5; r++) {
				for (int c = 1; c < 3; c++) {
					if (window[r][c] != ONEv3[r][c - 1]) {
						isNotThis = true;
						break;
					}
				}
				if (isNotThis) {
					break;
				}
			}
			if (isNotThis == false) {
				number.push_back('1');
				continue;
			}
		}
		isNotThis = false;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (window[r][c] != TWO[r][c]) {
					isNotThis = true;
					break;
				}
			}
			if (isNotThis) {
				break;
			}
		}
		if (isNotThis == false) {
			number.push_back('2');
			continue;
		}
		isNotThis = false;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (window[r][c] != THREE[r][c]) {
					isNotThis = true;
					break;
				}
			}
			if (isNotThis) {
				break;
			}
		}
		if (isNotThis == false) {
			number.push_back('3');
			continue;
		}
		isNotThis = false;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (window[r][c] != FOUR[r][c]) {
					isNotThis = true;
					break;
				}
			}
			if (isNotThis) {
				break;
			}
		}
		if (isNotThis == false) {
			number.push_back('4');
			continue;
		}
		isNotThis = false;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (window[r][c] != FIVE[r][c]) {
					isNotThis = true;
					break;
				}
			}
			if (isNotThis) {
				break;
			}
		}
		if (isNotThis == false) {
			number.push_back('5');
			continue;
		}
		isNotThis = false;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (window[r][c] != SIX[r][c]) {
					isNotThis = true;
					break;
				}
			}
			if (isNotThis) {
				break;
			}
		}
		if (isNotThis == false) {
			number.push_back('6');
			continue;
		}
		isNotThis = false;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (window[r][c] != SEVEN[r][c]) {
					isNotThis = true;
					break;
				}
			}
			if (isNotThis) {
				break;
			}
		}
		if (isNotThis == false) {
			number.push_back('7');
			continue;
		}
		isNotThis = false;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (window[r][c] != EIGHT[r][c]) {
					isNotThis = true;
					break;
				}
			}
			if (isNotThis) {
				break;
			}
		}
		if (isNotThis == false) {
			number.push_back('8');
			continue;
		}
		isNotThis = false;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 3; c++) {
				if (window[r][c] != NINE[r][c]) {
					isNotThis = true;
					break;
				}
			}
			if (isNotThis) {
				break;
			}
		}
		if (isNotThis == false) {
			number.push_back('9');
			continue;
		}
	}
	for (int i = 0; i < number.size(); i++) {
		cout << number.at(i);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	int cols = n / 5;
	char** str = new char* [5];
	for (int i = 0; i < 5; i++) {
		str[i] = new char[cols];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> str[i][j];
		}
	}
	// 5 ##### �� ó���ϴ� �κ�
	if (n == 5) {
		bool isOne = true;
		for (int i = 0; i < 5; i++) {
			if (str[i][0] != '#') {
				isOne = false;
			}
		}
		if (isOne) {
			cout << "1";
		}
		return 0;
	}
	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < cols; j++) {
	//		cout << str[i][j];
	//	}
	//	cout << "\n";
	//}
	changeNumber(str, 5, cols);
}