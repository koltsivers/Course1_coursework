#pragma once
#include <string.h>
#include <string>
#include <iostream>
#include "ClassExams.h"
using namespace std;
class ClassStudent {
private:
	char name[30];
	char surname[30];
	char patronymic[30];
	unsigned short birthDay;
	unsigned short birthMonth;
	unsigned short birthYear;
	unsigned short yearStart;
	char institute[30];
	char department[30];
	char group[30];
	char ID[30];
	bool sex = false;
	ClassExam exam;
	float averageGrade;
public:
	ClassStudent() {
		strcpy_s(this->name, "Имя");
		strcpy_s(this->surname, "Фамилия");
		strcpy_s(this->patronymic, "Отчество");
		this->birthDay = 0;
		this->birthMonth = 0;
		this->birthYear = 0;
		this->yearStart = 0;
		strcpy_s(this->institute, "Институт");
		strcpy_s(this->department, "Кафедра");
		strcpy_s(this->group, "Группа");
		strcpy_s(this->ID, "ID");
		sex = false;
	};

	ClassStudent(char ID[10]) {
		strcpy_s(this->name, "Имя");
		strcpy_s(this->surname, "Фамилия");
		strcpy_s(this->patronymic, "Отчество");
		this->birthDay = 0;
		this->birthMonth = 0;
		this->birthYear = 0;
		this->yearStart = 0;
		strcpy_s(this->institute, "Институт");
		strcpy_s(this->department, "Кафедра");
		strcpy_s(this->group, "Группа");
		strcpy_s(this->ID, "ID");
		sex = false;
	};
	//13 элементов
	ClassStudent(const char* name, const char* surname, const char* patronymic,\
		const unsigned short birthDay, const unsigned short birthMonth, const unsigned short birthYear, \
		const unsigned short yearStart, const char* institute, const char* department, \
		const char* group,  const char* ID, const bool sex, const ClassExam& exam) {
		strcpy_s(this->name, name);
		strcpy_s(this->surname, surname);
		strcpy_s(this->patronymic, patronymic);
		this->birthDay = birthDay;
		this->birthMonth = birthMonth;
		this->birthYear = birthYear;
		this->yearStart = yearStart;
		strcpy_s(this->institute, institute);
		strcpy_s(this->department, department);
		strcpy_s(this->group, group);
		strcpy_s(this->ID, ID);
		this->sex = sex;
		this->exam = exam;
	};
	//12 элементов
	ClassStudent(const char* name, const char* surname, const char* patronymic, \
		const unsigned short birthDay, const unsigned short birthMonth, const unsigned short birthYear, \
		const unsigned short yearStart, const char* institute, const char* department, \
		const char* group, const char* ID, const bool sex) {
		strcpy_s(this->name, name);
		strcpy_s(this->surname, surname);
		strcpy_s(this->patronymic, patronymic);
		this->birthDay = birthDay;
		this->birthMonth = birthMonth;
		this->birthYear = birthYear;
		this->yearStart = yearStart;
		strcpy_s(this->institute, institute);
		strcpy_s(this->department, department);
		strcpy_s(this->group, group);
		strcpy_s(this->ID, ID);
		this->sex = sex;
		this->exam = exam;
	};

	ClassStudent(const ClassStudent& student) {
		strcpy_s(this->name, student.name);
		strcpy_s(this->surname, student.surname);
		strcpy_s(this->patronymic, student.patronymic);
		this->birthDay = student.birthDay;
		this->birthMonth = student.birthMonth;
		this->birthYear = student.birthYear;
		this->yearStart = student.yearStart;
		strcpy_s(this->institute, student.institute);
		strcpy_s(this->department, student.department);
		strcpy_s(this->group, student.group);
		strcpy_s(this->ID, student.ID);
		this->sex = student.sex;
		this->exam = student.exam;
	}


	bool operator==(const ClassStudent& student) {
		return (strcmp(this->ID, student.ID) == 0);
	}

	bool operator<(const ClassStudent& student)
	{
		if (strlen(this->ID) < strlen(student.ID)) 
			return true;
		else if (strlen(this->ID) > strlen(student.ID)) 
			return false;
		if (strcmp(this->ID, student.ID) < 0)
			return true;
		return false;
	}

	friend std::ostream& operator<< (std::ostream& out, const ClassStudent& student) {
		out << student.name << ' ';
		out << "" << student.surname[0] << '.';
		out << "" << student.patronymic[0] << '.';
		out.fill(' ');
		out.width(10 - strlen(student.name));
		std::ios::left;
		out << "" << student.group;
		return out;
	};

	float getAverageGrade() {
		return averageGrade;
	}

	char* getName() {
		return name;
	}
	char* getSurname() {
		return surname;
	}
	char* getPatronymic() {
		return patronymic;
	}
	unsigned short getBirthDay() {
		return birthDay;
	}
	unsigned short getBirthMonth() {
		return birthMonth;
	}
	unsigned short getBirthYear() {
		return birthYear;
	}
	unsigned short getYearStart() {
		return yearStart;
	}
	char* getInstitute() {
		return institute;
	}
	char* getDepartment() {
		return department;
	}
	char* getGroup() {
		return group;
	}
	char* getID() {
		return ID;
	}
	char getSex() {
		if (sex == 0) { return 'Ж'; }
		else { return 'М'; }
	}
	ClassExam getExam() {
		return exam;
	}
	void addAverageGrade(float  averageGrade){
		this->averageGrade = averageGrade;
	}
	void addName(const char* name) {
		strcpy_s(this->name, name);
	}
	void addSurname(const char* surname) {
		strcpy_s(this->surname, surname);
	}
	void addPatronymic(const char* patronymic) {
		strcpy_s(this->patronymic, patronymic);
	}
	void addBirth(const unsigned short birthDay, const unsigned short birthMonth, const unsigned short birthYear) {
		this->birthDay = birthDay;
		this->birthMonth = birthMonth;
		this->birthYear = birthYear;
	}
	void addYearStart(const unsigned short yearStart) {
		this->yearStart = yearStart;
	}
	void addInstitute(const char* institute) {
		strcpy_s(this->institute, institute);
	}
	void addDepartment(const char* department) {
		strcpy_s(this->department, department);
	}
	void addGroup(const char* group) {
		strcpy_s(this->group, group);
	}
	void addID(const char* ID) {
		strcpy_s(this->ID, ID);
	}
	void addSex(const bool sex) {
		this->sex = sex;
	}

	int fillExam(const unsigned short _numSess, const char* _nameLesson, \
		const unsigned short _grade, const unsigned short _numLesson = -1) {
		return exam.addLesson(_numSess, _nameLesson, _grade, _numLesson);
	}

	void addExam(const ClassExam& exam) {
		this->exam = exam;
	}

	void copyExam(ClassExam& exam) {
		this->exam = exam;
	}

	void printDate() {
		cout << "Дата рождения: " << birthDay << "." << birthMonth << "." << birthYear;
	}

	void printAllData() {
		cout << "Имя: " << this->name << endl;
		cout << "Фамилия: " << this->surname << endl;
		cout << "Отчество: " << this->patronymic << endl;
		printDate();
		cout << "Начало учебы: " << this->yearStart << endl;
		cout << "Направление: " << this->institute << endl;
		cout << "Институт: " << this->department << endl;
		cout << "Номер группы: " << this->group << endl;
		cout << "Номер студ. билета: " << this->ID<< endl;
		cout << "Пол: " << this->sex<< endl;
		exam.print();
	}

};
