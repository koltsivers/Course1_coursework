#pragma once
#include <string.h>

struct Exam {
	char nameLesson[40] = "";
	unsigned short grade;
	bool empty = true;

};

class clExam {
private:

public:
	Exam lessons[9][10];
	int firstIsEmpty(const unsigned short);
	unsigned short countLessons(const unsigned short);
	unsigned short addLesson(const unsigned short, const char[], const unsigned short, const unsigned short);
	void clearLesson();
	void wtiteExamFile(FILE*);
	void readExamFile(FILE*);
	clExam operator= (const clExam&);
	~clExam();
};
int clExam::firstIsEmpty(const unsigned short _numSession) {
	for (int i = 0; i < 10; i++){
		if (lessons[_numSession][i].empty) {
			return i;
		}
	}
	return -1;
}
unsigned short clExam::countLessons(const unsigned short _numSession) {
	unsigned short countS = 0;
	for (int  i = 0; i < 10; i++) {
		if (!lessons[_numSession][i].empty) {
			countS++;
		}
	}
	return countS;
}
unsigned short clExam::addLesson(const unsigned short _numSession, const char _nameLesson[40], const unsigned short _grade, const unsigned short _numLesson) {
	if (_numLesson == -1) {
		int firstEmpty = firstIsEmpty(_numSession);
		if (firstEmpty < 10) {
			if (firstEmpty == -1) {
				return -1;
			}
			else {
				strcpy_s(this->lessons[_numSession][firstEmpty].nameLesson, _nameLesson);
				this->lessons[_numSession][firstEmpty].grade = _grade;
				this->lessons[_numSession][firstEmpty].empty = false;
				return 0;
			}
		}

		else {
			return 1;
		}
	}

	else {
		strcpy_s(this->lessons[_numSession][_numLesson].nameLesson, _nameLesson);
		this->lessons[_numSession][_numLesson].grade = _grade;
		this->lessons[_numSession][_numLesson].empty = false;
		return 0;
	}	
}
clExam::~clExam() {
}

void clExam::clearLesson() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			if (!lessons[i][j].empty) {
				strcpy(this->lessons[i][j].nameLesson, "");
				lessons[i][j].empty = true;
			}
		}
	}
}
void clExam::wtiteExamFile(FILE* file) {
	fwrite(lessons, sizeof(lessons), 1, file);
}
void clExam::readExamFile(FILE* file) {
	fread(lessons, sizeof(lessons), 1, file);
}
clExam clExam::operator= (const clExam& _exam) {
	for (int i = 0; i < 9; i++) {
		for (int  j = 0; i < 10; i++) {
			if (!_exam.lessons[i][j].empty) {
				strcpy_s(this->lessons[i][j].nameLesson, _exam.lessons[i][j].nameLesson);
				this->lessons[i][j].grade, _exam.lessons[i][j].grade;
				this->lessons[i][j].empty, _exam.lessons[i][j].empty;
			}
		}
	}
	return *this;
};

