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
		string name = "emptyName";
		string surname = "emptySurname";
		string patronymic = "emptyPatronymic";
		unsigned short birthDay = 01;
		unsigned short birthMonth = 01;
		unsigned short birthYear = 1970;
		unsigned short startStudyYear = 2000;
		string faculty = "emptyFaculty";
		string department = "emptyDepartment";
		string group = "emptyGroup";
		string ID = "empty ID";
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
		for (int  i = 0; i < (int)(ourGroup.size()); i++) {
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
	bool checkDate(int _birthDay, int _birthMonth, int _birthYear, int _startStudyYear) {
		for (int i = 1; i < 32; i++) {
			while (i < 13) {
				if (!(_birthMonth == i)) {
					cout << "Неверная запись месяца рождения" << endl;
					return false;
				}
			}
			if (!(_birthDay == i)) {
				cout << "Неверная запись дня рождения" << endl;
				return false;
			}
			else {
				return true;
			}
		}
		if (!((1905 <= _birthYear <= 2005) && (1947 <= _startStudyYear <= 2022))) {
			cout << "Неверная запись года рождения или поступления" << endl;
			cout << "Пишите правду :)" << endl;
			return false;
		}
		else {
			return true;
		}
	}
	void addInitials(string name, string surname, string patronymic) {
		while (!(checkString(name))) { this->name = name; }
		while (!(checkString(surname))) {this->surname = surname; }
		while (!(checkString(patronymic))) {this->patronymic = patronymic; }
	}
	void addDate(int birthDay, int birthMonth, int birthYear, int startStudyYear) {
		while (!(checkDate(birthDay, birthMonth, birthYear, startStudyYear))) {
			this->birthDay = birthDay;
			this->birthMonth = birthMonth;
			this->birthYear = birthYear;
			this->startStudyYear = startStudyYear;
		}
	}
	void addInstituteData(string faculty, string department, string group, string ID){
		while (!(checkString(faculty))) { this->faculty = faculty; }
		while (!(checkString(department))) { this->faculty = department; }
		while (!(checkGroup(group))) { this->faculty = group; }
		while (!(checkID(ID))) { this->faculty = ID; }
	}
	bool chekingSex(int _sex) {
		if ((_sex == 1) || (_sex == 0)) {
			return true;
		}
		else {
			cout << "Введенно неверное значение\n";
			return false;
		}
	}
	void addSex(bool sex) {
		this->sex = sex;
	}

};
