#pragma once
#include <string>
#include "ClassStudent.h"
using namespace std;
struct Exam {
	char nameLesson[30] = "";
	unsigned short grade;
	bool empty = true;

};

class ClassExam {
private:
public:
    Exam lessons[9][10];

    int firstIsEmpty(const unsigned short _numSess) {
        for (int i = 0; i < 10; i++) {
            if (lessons[_numSess][i].empty)  return i;
        }
        return -1;
    }

    unsigned short countLessons(const unsigned short _numSess) {
        unsigned short countLes = 0;
        for (int i = 0; i < 10; i++) {
            if (!lessons[_numSess][i].empty) countLes++;
        }
        return countLes;
    }

    float findAverageGrade(const unsigned short _numSess) {
        unsigned short countLes = 0;
        unsigned short sumGrades = 0;
        for (int i = 0; i < 10; i++) {
            if (!lessons[_numSess][i].empty) {
                countLes++;
                sumGrades = lessons[_numSess][i].grade;
            }
        }
        return (sumGrades / countLes);
    }


    ClassExam operator=(const ClassExam& exam) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                if (!exam.lessons[i][j].empty) {
                    strcpy_s(this->lessons[i][j].nameLesson, exam.lessons[i][j].nameLesson);
                    this->lessons[i][j].grade = exam.lessons[i][j].grade;
                    this->lessons[i][j].empty = exam.lessons[i][j].empty;
                }
            }
        }
        return(*this);
    }


    int addLesson(const unsigned short _numSess, const char _nameLesson[30], const unsigned short _grade, const int _lessonNum) {
        if (_lessonNum == -1) {
            int firstEmp = firstIsEmpty(_numSess);
            if (firstEmp < 10) {
                if (firstEmp == -1) {
                    return -1;
                }
                else {
                    strcpy_s(this->lessons[_numSess][firstEmp].nameLesson, _nameLesson);
                    this->lessons[_numSess][firstEmp].grade = _grade;
                    this->lessons[_numSess][firstEmp].empty = false;
                    return 0;
                }
            }
            else return 1;
        }
        else {
            strcpy_s(this->lessons[_numSess][_lessonNum].nameLesson, _nameLesson);
            this->lessons[_numSess][_lessonNum].grade = _grade;
            this->lessons[_numSess][_lessonNum].empty = false;
            return 0;
        }
    }

    void clear()
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 10; j++) {
                if (!lessons[i][j].empty) {
                    strcpy_s(this->lessons[i][j].nameLesson, "");
                    lessons[i][j].empty = true;
                }
            }
    }

    void print() {
        for (int i = 0; i < 9; i++) {
           cout << "Сессия " << i + 1 << "\n";
            int len = countLessons(i);
            if (len == 0) 
            cout << "Отсутствуют данные о сессиях\n";
            else {
                for (int j = 0; j < len; j++) {
                    cout << lessons[i][j].nameLesson << " ";
                    if (lessons[i][j].grade <= 2) {
                        cout << (lessons[i][j].grade == 0 ? "Незачет\n" : "Зачет\n");
                    }
                    else {
                        cout << lessons[i][j].grade << "\n";
                    }
                }
            }
        }
    }
    ~ClassExam() {};
};

