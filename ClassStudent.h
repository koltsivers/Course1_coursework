#pragma once
#include <string.h>
#include <string>
#include <iostream>
#include "Exams.h"
class clStudent {
private:
	char name[40];
	char surname[40];
	char patronymic[40];
	unsigned short birthDay;
	unsigned short birthMonth;
	unsigned short birthYear;
	unsigned short startStudyYear;
	char faculty[40];
	char department[40];
	char group[40];
	char ID[40];
	char sex[40];
	clExam exam;
public:
	clStudent();
	clStudent(char[]);
	clStudent(const char*, const char*, const char*,
		const unsigned short, const unsigned short, \
		const unsigned short, const unsigned short, \
		const char*, const char*, const char*, \
		const char*, const char*, clExam);
	clStudent(const char*, const char*, const char*,
		const unsigned short, const unsigned short, \
		const unsigned short, const unsigned short, \
		const char*, const char*, const char*, \
		const char*, const char*);
	clStudent(const clStudent&);
	int addExam(const unsigned short, const char[], const unsigned short);
	void editName(const char*);
	void editSurname(const char*);
	void editPatronymic(const char*);
	void editFacility(const char*);
	void editDepartment(const char*);
	void editGroup(const char*);
	void editID(const char*);
	void editSex(const char*);
	void editBirth(const unsigned short&, const unsigned short&, const unsigned short&);
	void editStartStudyYear(const unsigned short&);
	clStudent(const clStudent&);
	~clStudent();
};

clStudent::clStudent() {
	strcpy_s(this->name, "n");
	strcpy_s(this->surname, "s");
	strcpy_s(this->patronymic, "p");
	this->birthDay = 0;
	this->birthMonth = 0;
	this->birthYear = 0;
	this->startStudyYear = 0;
	strcpy_s(this->faculty, "f");
	strcpy_s(this->department, "d");
	strcpy_s(this->group, "g");
	strcpy_s(this->ID, "i");
	strcpy_s(this->sex, "s");
}
clStudent::clStudent(char ID[40]){
	strcpy_s(this->name, "n");
	strcpy_s(this->surname, "s");
	strcpy_s(this->patronymic, "p");
	this->birthDay = 0;
	this->birthMonth = 0;
	this->birthYear = 0;
	this->startStudyYear = 0;
	strcpy_s(this->faculty, "f");
	strcpy_s(this->department, "d");
	strcpy_s(this->group, "g");
	strcpy_s(this->ID, ID);
	strcpy_s(this->sex, "s");
}
clStudent::clStudent(const char* name, const char* surname, const char* patronymic, \
	const unsigned short birthDay, const unsigned short birthMonth, const unsigned short birthYear,\
	const unsigned short startStudyYear, const char* faculty, const char* department, const char* group, \
	const char* ID, const char* sex, clExam exam) {
	strcpy_s(this->name, name);
	strcpy_s(this->surname, surname);
	strcpy_s(this->patronymic, patronymic);
	this->birthDay = birthDay;
	this->birthMonth = birthMonth;
	this->birthYear = birthYear;
	this->startStudyYear = startStudyYear;
	strcpy_s(this->faculty, faculty);
	strcpy_s(this->department, department);
	strcpy_s(this->group, group);
	strcpy_s(this->ID, ID);
	strcpy_s(this->sex, sex);
	this->exam = exam;
}
//bool clStudent::operator==(const clStudent& student) {
//	return (strcmp(this->ID, student.ID) == 0);
//}
clStudent::clStudent(const clStudent& student) {
	strcpy_s(this->name, student.name);
	strcpy_s(this->surname, student.surname);
	strcpy_s(this->patronymic, student.patronymic);
	this->birthDay = student.birthDay;
	this->birthMonth = student.birthMonth;
	this->birthYear = student.birthYear;
	this->startStudyYear= student.startStudyYear;
	strcpy_s(this->faculty, student.faculty);
	strcpy_s(this->department, student.department);
	strcpy_s(this->group, student.group);
	strcpy_s(this->ID, student.ID);
	strcpy_s(this->sex, student.sex);
	this->exam = student.exam;
}
//Student Student::operator=(const Student& student)
clStudent::clStudent(const clStudent& student) {
	strcpy_s(this->name, student.name);
	strcpy_s(this->surname, student.surname);
	strcpy_s(this->patronymic, student.patronymic);
	this->birthDay = student.birthDay;
	this->birthMonth = student.birthMonth;
	this->birthYear = student.birthYear;
	this->startStudyYear = student.startStudyYear;
	strcpy_s(this->faculty, student.faculty);
	strcpy_s(this->department, student.department);
	strcpy_s(this->group, student.group);
	strcpy_s(this->ID, student.ID);
	strcpy_s(this->sex, student.sex);
	this->exam = student.exam;
} 