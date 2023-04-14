#pragma once
#include <string.h>
#include <string>
#include <iostream>
#include "Exams.h"

class clStudent {
private:
	std::string name = "";
	std::string surname = "";
	std::string patronymic = "";
	int birthDay;
	int birthMonth;
	int birthYear;
	int startStudyYear;
	std::string faculty = "";
	std::string department = "";
	std::string group = "";
	std::string ID = "";
	bool sex = false;
	clExam exam;
public:
	clStudent() {
		std::string name = "emptyName";
		std::string surname = "emptySurname";
		std::string patronymic = "emptyPatronymic";
		unsigned short birthDay = 01;
		unsigned short birthMonth = 01;
		unsigned short birthYear = 1970;
		unsigned short startStudyYear = 2000;
		std::string faculty = "emptyFaculty";
		std::string department = "emptyDepartment";
		std::string group = "emptyGroup";
		std::string ID = "empty ID";
		bool sex = false;
		clExam exam;
	};
	void getInitials(std::string name, std::string surname, std::string patronymic) {
		this->name = name;
		this->surname = surname;
		this->patronymic = patronymic;
	}
	void getData(int birthDay, int birthMonth, int birthYear, int startStudyYear) {
		this->birthDay = birthDay;
		this->birthMonth = birthMonth;
		this->birthYear = birthYear;
		this->startStudyYear = startStudyYear;
	}
};
