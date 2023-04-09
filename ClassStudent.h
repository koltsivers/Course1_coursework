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
	bool sex = false;
	clExam exam;
public:
	clStudent();
	clStudent(char[]);
	clStudent(const char*, const char*, const char*,
		const unsigned short, const unsigned short, \
		const unsigned short, const unsigned short, \
		const char*, const char*, const char*, \
		const char*, const bool, clExam);
	clStudent(const char*, const char*, const char*,
		const unsigned short, const unsigned short, \
		const unsigned short, const unsigned short, \
		const char*, const char*, const char*, \
		const bool, const char*);
	clStudent(const clStudent&);
	//addLesson из Exams.h
	unsigned short addExam(const unsigned short, const char[], const unsigned short, const unsigned short);
	void editName(const char*);
	void editSurname(const char*);
	void editPatronymic(const char*);
	void editGroup(const char*);
	void editFaculty(const char*);
	void editDepartment(const char*);
	void editID(const char*);
	void editSex(const bool);
	void editBirth(const unsigned short&, const unsigned short&, const unsigned short&);
	void editStartStudyYear(const unsigned short&);
	clStudent operator= (const clStudent&);
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
	sex = false;
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
	sex = false;
}
clStudent::clStudent(const char* name, const char* surname, const char* patronymic, \
	const unsigned short birthDay, const unsigned short birthMonth, const unsigned short birthYear,\
	const unsigned short startStudyYear, const char* faculty, const char* department, const char* group, \
	const char* ID, const bool sex, clExam exam) {
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
	this->sex = sex;
	this->exam = exam;
}
//bool clStudent::operator==(const clStudent& student) {
//	return (strcmp(this->ID, student.ID) == 0);
//}
clStudent clStudent::operator= (const clStudent& student) {
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
	this->sex = student.sex;
	this->exam = student.exam;
	return *this;
}
//Student Student::operator=(const Student& student)
//clStudent::clStudent(const clStudent& student) {
//	strcpy_s(this->name, student.name);
//	strcpy_s(this->surname, student.surname);
//	strcpy_s(this->patronymic, student.patronymic);
//	this->birthDay = student.birthDay;
//	this->birthMonth = student.birthMonth;
//	this->birthYear = student.birthYear;
//	this->startStudyYear = student.startStudyYear;
//	strcpy_s(this->faculty, student.faculty);
//	strcpy_s(this->department, student.department);
//	strcpy_s(this->group, student.group);
//	strcpy_s(this->ID, student.ID);
//	this->sex = student.sex;
//	this->exam = student.exam;
//} 

unsigned short clStudent::addExam(const unsigned short _numSession, const char _nameLesson[40], const unsigned short _grade, const unsigned short _numLesson) {
	return exam.addLesson(_numSession, _nameLesson, _grade, _numLesson);
}

clStudent::~clStudent() {
};

void clStudent::editName(const char* _name){ 
	strcpy_s(name, _name); 
}
void clStudent::editSurname(const char* _surname) { 
	strcpy_s(surname, _surname); 
}
void clStudent::editPatronymic(const char* _patronymic) { 
	strcpy_s(patronymic, _patronymic); 
}
void clStudent::editGroup(const char* _group) { 
	strcpy_s(group,10, _group); 
}
void clStudent::editFaculty(const char* _faculty) { 
	strcpy_s(faculty, _faculty); 
}
void clStudent::editDepartment(const char* _department) { 
	strcpy_s(department, _department); 
}
void clStudent::editID(const char* _ID) { 
	strcpy_s(ID, 7, _ID); 
}
void clStudent::editSex(const bool _sex) {
	sex = _sex; 
}
void clStudent::editBirth(const unsigned short& _birthDay, \
	const unsigned short& _birthMonth, \
	const unsigned short& _birthYear) {
	birthDay = _birthDay;
	birthMonth = _birthMonth;
	birthYear = _birthYear;
}
void clStudent::editStartStudyYear(const unsigned short& _startYearStudy) {
	startStudyYear = _startYearStudy;
}
