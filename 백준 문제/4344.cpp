#include <iostream>

using namespace std;

int* input(int* size) {
	int student;
	cin >> student;
	
	int* scores = new int[student];

	for (int i = 0; i < student; i++) {
		cin >> scores[i];
	}
	*size = student;
	return scores;
}

double percentage(int score[], int size) {
	
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += score[i];
	}
	double average = sum / size;
	int per=0;
	for (int i = 0; i < size; i++) {
		if (average < score[i]) {
			per++;
		}
	}
	return ((double)per / size) * 100;
}

int main() {
	int num;
	cin >> num;
	int** score = new int*[num]; 
	int* size = new int[num];     
	for (int i = 0; i < num; i++) { 
		score[i] = input(&size[i]);  
	}
	for (int i = 0; i < num; i++) {
		cout.precision(3);
		cout << fixed;
		cout << percentage(score[i], size[i]) <<"%" << endl; 
	}
	
	delete[] score;

	return 0;
}