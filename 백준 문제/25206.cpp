#include <iostream>
#include <string>

using namespace std;

class Subject {
private:
	string name;
	double time;
	double grade;
public:
	Subject(string name, string time, string grade);
	double getEvaluation();
	double getGrade();
	double getTime();
};
Subject::Subject(string name, string time, string grade) {
	this->name = name;
	this->time = stod(time);
	if (grade == "A+") {
		this->grade = 4.5;
	}
	else if (grade == "A0") {
		this->grade = 4.0;
	}
	else if (grade == "B+") {
		this->grade = 3.5;
	}
	else if (grade == "B0") {
		this->grade = 3.0;
	}
	else if (grade == "C+") {
		this->grade = 2.5;
	}
	else if (grade == "C0") {
		this->grade = 2.0;
	}
	else if (grade == "D+") {
		this->grade = 1.5;
	}
	else if (grade == "D0") {
		this->grade = 1.0;
	}
	else if (grade == "F") {
		this->grade = 0;
	}
	else {
		this->grade = -1.0;
	}
}
double Subject::getEvaluation() {
	return grade * time;
}
double Subject::getGrade() {
	return grade;
}
double Subject::getTime() {
	return time;
}
int main() {
	int size = 20;
	string name;
	string time;
	string grade;
	double totalTime = 0;
	double sum = 0;
	for (int i = 0; i < size; i++) {
		cin >> name >> time >> grade;
		Subject sub(name, time, grade);
		if (sub.getGrade() != -1.0) {
			sum += sub.getEvaluation();
			totalTime += sub.getTime();
		}
	}
	cout << sum / totalTime;
}