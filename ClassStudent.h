#pragma once
#include <string.h>
#include <string>
#include <iostream>
#include "Exams.h"
using namespace std;
class clStudent {
private:
	string name = "";
	string surname = "";
	string patronymic = "";
	int birthDay;
	int birthMonth;
	int birthYear;
	int startStudyYear;
	string faculty = "";
	string department = "";
	string group = "";
	string ID = "";
	bool sex = false;
	clExam exam;
public:
	clStudent() {
		string name = "Name";
		string surname = "Surname";
		string patronymic = "Patronymic";
		unsigned short birthDay = 0;
		unsigned short birthMonth = 0;
		unsigned short birthYear = 0;
		unsigned short startStudyYear = 0;
		string faculty = "Faculty";
		string department = "Department";
		string group = "Group";
		string ID = "ID";
		bool sex = false;
		clExam exam;
	};
	bool checkString(string _str) {
		string Digits = "0123456789";
		string str = _str;
		for (int i = 0; i < (int)(str.size()); i++) {
			for (int j = 0; j < (int)(Digits.size()); j++) {
				if (str[i] == Digits[j]) {
					cout << "Имя/фамилия/отчество не должны содержать цифр" << endl;
					return false;
				}
				else {
					return true;
				}
			}
		}
	}
	bool checkGroup(string _group) {
		string group = _group;
		string Digits = "0123456789";
		string AlphabetRU = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
		string ourGroup = "БИСО-01-22";
		for (int i = 0; i < (int)(ourGroup.size()); i++) {
			for (int j = 0; j < (int)(_group.size()); j++) {
				if (_group[j] == ourGroup[i]) {
					cout << "Наш человек!" << endl;
				}
			}
		}
		if (group.length() != 10) {
			cout << "Неверная длина записи группы" << endl;
			return false;
		}
		for (int i = 0; i < (int)(group.size()); i++) {
			for (int j = 0; j < (int)(AlphabetRU.size()); j++) {
				while (i < 4) {
					if (!(group[i] == AlphabetRU[j])) {
						cout << "Неверная длина записи" << endl;
						return false;
					}
				}
				if (!((i == 4) && (i == 7) && (group[i] == (char)("-")))) {
					cout << "Неверная запись группы" << endl;
					return false;
				}
				else {
					for (int k = 0; k < (int)(Digits.size()); k++) {
						if (!((i == 5) && (i == 6) && (i == 8) && (i == 9) && (group[i] = Digits[k]))) {
							cout << "Неверная запись группы" << endl;
							return false;
						}
						else {
							return true;
						}
					}
				}
			}
		}
	}
	bool checkID(string _id) {
		string Digits = "0123456789";
		string AlphabetRU = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
		string id = _id;
		if (id.length() != 7) {
			cout << "Неверная длина записи номера" << endl;
			return false;
		}
		for (int i = 0; i < (int)(id.size()); i++) {
			for (int j = 0; j < (int)(AlphabetRU.size()); j++) {
				if (id[i] == Digits[j]) {
					if (!((i == 3) && (id[i] == AlphabetRU[j]))) {
						cout << "Неверная запись номера" << endl;
						return false;
					}
					else {
						return true;
					}
				}
				else {
					cout << "Неверная запись номера" << endl;
					return false;
				}
			}
		}
	}
	bool checkDate(const unsigned short birthDay, const unsigned short birthMonth, const unsigned short birthYear) {
		if ((birthYear % 4 == 0) && (birthYear % 100 == 0) && (birthYear % 400 == 0)) {
			if (birthMonth == 2){
				if (birthDay == 29) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			if (1 <= birthMonth <= 12) {
				if ((birthMonth == 1) || (birthMonth == 3) || (birthMonth == 5) || \
					(birthMonth == 7) || (birthMonth == 8) || (birthMonth == 10) ||
					(birthMonth == 12)) {
					if (1 <= birthDay <= 31) {
						return true;
					}
					else {
						return false;
					}
				}
				else {
					if (1 <= birthDay <= 30) {
						return true;
					}
					else {
						return false;
					}
				}
			}
			else {
				return false;
			}
		}
	}

	bool checkSex(const unsigned short _sex) {
		if ((_sex == 1) || (_sex == 0)) {
			return true;
		}
		else {
			cout << "Введенно неверное значение\n";
			return false;
		}
	}
	void addName(const string& name) {
		while (!(checkString(name))) {
			this->name = name;
		}
	}
	void addSurname(const string& surname) {
		while (!(checkString(surname))) {
			this->surname = surname;
		}
	}
	void addPatronymic(const string& patronymic) {
		while (!(checkString(patronymic))) {
			this->patronymic = patronymic;
		}
	}
	void addData(const unsigned short birthDay, const unsigned short birthMonth, const unsigned short birthYear) {
		while (!(checkDate(birthDay, birthMonth, birthYear))) {
			this->birthDay = birthDay;
			this->birthMonth = birthMonth;
			this->birthYear = birthYear;
		}
	}
	void addSStartStudyYear() {

	}
	void addFaculty(const string& faculty) {
		while (!(checkString(faculty))) {
			this->faculty = faculty;
		}
	}
	void addDepartment(const string& department) {
		while (!(checkString(department))) {
			this->department = department;
		}
	}
	void addGroup(const string& group) {
		while (!(checkGroup(group))) {
			this->group = group;
		}
	}
	void addID(const string& ID) {
		while (!(checkID(ID))) {
			this->ID = ID;
		}
	}
	void addSex(const bool sex) {
		while (!(checkSex(sex))) {
			this->sex = sex;
		}
	}

};
