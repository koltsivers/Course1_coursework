#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include "ClassList.h"
#include "ClassStudent.h"
using namespace std;
struct ListMenu {
	ClassList <string> listMainMenu;
	ClassList <string> listNewStudentMenu;
	ClassList <string> listCurrentStudentMenu;
	ClassList <string> listSex;
	ClassList <string> listSafeStudent;
	ClassList <string> listExams;
	ClassList <string> listVar60_1;
	ClassList <string> listVar60_clear;
	ClassList <string> listVar60_2;
	ClassList <string> listVar60_temp;
	ClassList <string> AddLast;
};


struct StructStudent {
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
	char sex[30];
	ClassExam exam;
	int countFill = 0;
	double averageGrade = 0;
};

class ClassMenu
{
private:
	ClassList <ClassStudent> students;
	bool firstEditSes = true;
	bool skipInput = false;
	bool choiceSex = false;
	bool changeExam = false;
	bool before_changeExam = false;
	bool addExam = false;
	bool before_addExam = false;
	bool before_editExam = false;
	bool editExam = false;
	bool firstPage2 = true;
	bool firstPage4 = true;
	bool firstPage1Exam = true;
	bool allAddedFirst = true;
	unsigned long long page = 0;
	const unsigned short maxCountOfStudents = 1000;
	int numsSes[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};


	size_t len, CHOICE = 1, choice;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c;
	char key;
	ListMenu listMenu;
	StructStudent studentMenu;

public:
	ClassMenu() {

		listMenu.listMainMenu.addElem("5. Выход");
		listMenu.listMainMenu.addElem("4. Выполнить вариант 60");
		listMenu.listMainMenu.addElem("3. Сохранить БД студентов в файл: dbFile.txt");
		listMenu.listMainMenu.addElem("2. Добавить студента в базу данных");
		listMenu.listMainMenu.addElem("1. Отобразить/изменить данные о студентах");

		listMenu.listCurrentStudentMenu.addElem("Назад");
		listMenu.listCurrentStudentMenu.addElem("12. Вывести все данные о студенте");
		listMenu.listCurrentStudentMenu.addElem("11. Добавить результаты сессии");
		listMenu.listCurrentStudentMenu.addElem("10. Изменить пол");
		listMenu.listCurrentStudentMenu.addElem("9. Изменить номер зачетной книжки");
		listMenu.listCurrentStudentMenu.addElem("8. Изменить институт");
		listMenu.listCurrentStudentMenu.addElem("7. Изменить кафедру");
		listMenu.listCurrentStudentMenu.addElem("6. Изменить группу");
		listMenu.listCurrentStudentMenu.addElem("5. Изменить год поступления");
		listMenu.listCurrentStudentMenu.addElem("4. Изменить дату рождения");
		listMenu.listCurrentStudentMenu.addElem("3. Изменить отчество");
		listMenu.listCurrentStudentMenu.addElem("2. Изменить фамилию");
		listMenu.listCurrentStudentMenu.addElem("1. Изменить имя");

		listMenu.listNewStudentMenu.addElem("Назад");
		listMenu.listNewStudentMenu.addElem("11. Добавить данные о сессиях");
		listMenu.listNewStudentMenu.addElem("10. Выберите пол");
		listMenu.listNewStudentMenu.addElem("9. Введите номер зачетной книжки");
		listMenu.listNewStudentMenu.addElem("8. Введите институт");
		listMenu.listNewStudentMenu.addElem("7. Введите кафедру");
		listMenu.listNewStudentMenu.addElem("6. Введите группу");
		listMenu.listNewStudentMenu.addElem("5. Введите год поступления");
		listMenu.listNewStudentMenu.addElem("4. Введите дату рождения");
		listMenu.listNewStudentMenu.addElem("3. Введите отчество");
		listMenu.listNewStudentMenu.addElem("2. Введите фамилию");
		listMenu.listNewStudentMenu.addElem("1. Введите имя");

		listMenu.listSex.addElem("2. Мужской");
		listMenu.listSex.addElem("1. Женский");

		listMenu.listSafeStudent.addElem("Да");
		listMenu.listSafeStudent.addElem("Нет");

		listMenu.listExams.addElem("Назад");
		listMenu.listExams.addElem("Сессия 9");
		listMenu.listExams.addElem("Сессия 8");
		listMenu.listExams.addElem("Сессия 7");
		listMenu.listExams.addElem("Сессия 6");
		listMenu.listExams.addElem("Сессия 5");
		listMenu.listExams.addElem("Сессия 4");
		listMenu.listExams.addElem("Сессия 3");
		listMenu.listExams.addElem("Сессия 2");
		listMenu.listExams.addElem("Сессия 1");

		listMenu.listVar60_1.addElem("Назад");
		listMenu.listVar60_1.addElem("Выполнить рассчеты");
		listMenu.listVar60_1.addElem("Очистить выбор сессий");
		listMenu.listVar60_1.addElem("Выбрать все сессии");
		listMenu.listVar60_1.addElem("Сессия 9");
		listMenu.listVar60_1.addElem("Сессия 8");
		listMenu.listVar60_1.addElem("Сессия 7");
		listMenu.listVar60_1.addElem("Сессия 6");
		listMenu.listVar60_1.addElem("Сессия 5");
		listMenu.listVar60_1.addElem("Сессия 4");
		listMenu.listVar60_1.addElem("Сессия 3");
		listMenu.listVar60_1.addElem("Сессия 2");
		listMenu.listVar60_1.addElem("Сессия 1");

		listMenu.listVar60_clear.addElem("Назад");
		listMenu.listVar60_clear.addElem("Выполнить рассчеты");
		listMenu.listVar60_clear.addElem("Очистить выбор сессий");
		listMenu.listVar60_clear.addElem("Выбрать все сессии");
		listMenu.listVar60_clear.addElem("Сессия 9");
		listMenu.listVar60_clear.addElem("Сессия 8");
		listMenu.listVar60_clear.addElem("Сессия 7");
		listMenu.listVar60_clear.addElem("Сессия 6");
		listMenu.listVar60_clear.addElem("Сессия 5");
		listMenu.listVar60_clear.addElem("Сессия 4");
		listMenu.listVar60_clear.addElem("Сессия 3");
		listMenu.listVar60_clear.addElem("Сессия 2");
		listMenu.listVar60_clear.addElem("Сессия 1");

		listMenu.listVar60_2.addElem("Назад");
		listMenu.listVar60_2.addElem("Выполнить рассчеты");
		listMenu.listVar60_2.addElem("Очистить выбор сессий");
		listMenu.listVar60_2.addElem("Выбрать все сессии");
		listMenu.listVar60_2.addElem("Сессия 9 - выбрано");
		listMenu.listVar60_2.addElem("Сессия 8 - выбрано");
		listMenu.listVar60_2.addElem("Сессия 7 - выбрано");
		listMenu.listVar60_2.addElem("Сессия 6 - выбрано");
		listMenu.listVar60_2.addElem("Сессия 5 - выбрано");
		listMenu.listVar60_2.addElem("Сессия 4 - выбрано");
		listMenu.listVar60_2.addElem("Сессия 3 - выбрано");
		listMenu.listVar60_2.addElem("Сессия 2 - выбрано");
		listMenu.listVar60_2.addElem("Сессия 1 - выбрано");

		listMenu.AddLast.addElem("Назад");
		listMenu.AddLast.addElem("Добавить");



	}


	void var60() {
		int countOfStudents = students.getSize();
		for (int index = 0; index < countOfStudents; index++) {
			double averageGrade = 0;
			int countSes = 0;
			for (int i = 0; i < 9; i++) {
				int countLes = 0;
				int sumGrades = 0;
				if (numsSes[i] != -1) {
					countSes++;
					for (int j = 0; j < 10; j++) {
						if (!students[index].getExam().lessons[i][j].empty) {
							sumGrades += students[index].getExam().lessons[i][j].grade;
							countLes++;
						}
					}
					if (countLes == 0) { averageGrade = 0; }
					else { averageGrade += ((sumGrades * 1.0) / countLes);}
				}
			}
			averageGrade = (averageGrade * 1.0) / countSes;
			averageGrade = int(averageGrade * 100) / 100.0;
			if (averageGrade > 0) { students[index].addAverageGrade(averageGrade); }
		}
		

		ClassStudent temp;
		for (int i = 0; i < students.getSize() - 1; i++) {
			for (int j = 0; j < students.getSize() - 1; j++) {
				if (students[j + 1].getAverageGrade() > students[j].getAverageGrade()) {
					temp = students[j + 1];
					students[j + 1] = students[j];
					students[j] = temp;
				}
			}
		}


		int interval1,  interval2;
		cout << "Введите год, c которого начинается интервал: ";
		cin >> interval1;
		cout << "Введите год, которым заканчивается интервал: ";
		cin >> interval2;
		while (interval1 > interval2) {
			cout << "Неверное определение интервала, попробуйте снова\n";
			cout << "Введите год, c которого начинается интервал: ";
			cin >> interval1;
			cout << "Введите год, которым заканчивается интервал: ";
			cin >> interval2;
		}
		char _key = 0;
		while (_key != 13) {
			system("cls");
			cout << "Список студентов, отсортированный по успеваемости\n";

			for (int i = 0; i < students.getSize(); i++) {
				if ((interval1 <= students[i].getBirthYear()) && (students[i].getBirthYear() <= interval2)) {
					cout << students[i];
					cout << " " << students[i].getGroup() << " ";
					cout << " " << students[i].getID() << " ";
					cout << " " << students[i].getAverageGrade() << endl;
				}
			}
			cout << "Для возвращения назад нажмите Enter\n";
			_key = _getch();
		}
	}

	

	void clearStudent() {
		strcpy_s(studentMenu.name, "");
		strcpy_s(studentMenu.surname, "");
		strcpy_s(studentMenu.patronymic, "");
		studentMenu.birthDay = 0;
		studentMenu.birthMonth = 0;
		studentMenu.birthYear = 0;
		studentMenu.yearStart = 0;
		strcpy_s(studentMenu.institute, "");
		strcpy_s(studentMenu.department, "");
		strcpy_s(studentMenu.group, "");
		strcpy_s(studentMenu.ID, "");
		strcpy_s(studentMenu.sex, "");
		studentMenu.exam.clear();
		studentMenu.countFill = 0;
	}

	bool checkStringMenu(char _str[]) {
		string AlphabetRU = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
		unsigned short count = 0;
		for (int i = 0; i < strlen(_str); i++) {
			for (int j = 0; j < (int)(AlphabetRU.size()); j++) {
				if (_str[i] == AlphabetRU[j]) {
					count++;
				}
			}
		}
		if (count == strlen(_str)) { return true; }
		else { return false; }
	}
	bool checkGroupMenu(char _group[]) {
		string ourGroup = "БИСО-01-22";
		unsigned short count = 0;
		if (_group == ourGroup) {
			cout << "Наш человек!" << endl;
			system("pause");
			return true;
		}
		if (strlen(_group) != 10) { return false; }


	}
	bool checkIDMenu(char _ID[]) {
		string Digits = "0123456789";
		string AlphabetRU = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
		unsigned short count = 0;
		if (strlen(_ID) != 7) { return false; }
		for (int i = 0; i < strlen(_ID); i++) {
			for (int j = 0; j < (int)(AlphabetRU.size()); j++) {
				if ((_ID[i] == AlphabetRU[j]) && (i == 2)) {
					count++;
				}
			}
			for (int k = 0; k < (int)(Digits.size()); k++) {
				if ((_ID[i] == Digits[k]) && ((i == 0) || (i == 1) || (i == 3) || (i == 4) || (i == 5) || (i == 6))) {
					count++;
				}
			}
		}
		if (count == strlen(_ID)) { return true; }
		else { return false; }
	}

	bool checkDateMenu(const unsigned short _birthDay, const unsigned short _birthMonth, const unsigned short _birthYear) {
		string months31 = "13571012";
		if ((_birthYear % 4 == 0) && (_birthYear % 100 == 0) && (_birthYear % 400 == 0)) {
			if (_birthMonth == 2) {
				if (_birthDay == 29) {
					return true;
				}
				else { return false; }
			}
			else { return false; }
		}
		else {
			if ((_birthMonth <= 12) && (_birthMonth >= 1)) {
				for (int i = 0; i < (int)(months31.size()); i++) {
					if (_birthMonth == (int)(months31[i])) {
						if ((_birthDay <= 31) && (_birthDay >= 1)) {
							return true;
						}
						else { return false; }
					}
					else {
						if ((_birthDay <= 30) && (_birthDay >= 1)) {
							return true;
						}
						else { return false; }
					}
				}
			}
			else { return false; }
		}
	}

	bool checkYearStartMenu(const unsigned short _yearStart) {
		if ((_yearStart >= 1947) && (_yearStart <= 2022)) { return true; }
		else { return false; }
	}
	bool checkGradeMenu(const unsigned short _grade) {
		if ((_grade < 0) && (_grade > 5)) { return false; }
		else { return true; }
	}
	void printDate(const unsigned short& day, const unsigned short& month, const unsigned short& year, int wLine) {
		int w = 10;
		int delta = (wLine - w) / 2 - 1;
		cout.width(delta); cout << " ";
		if (day > 9) {
			cout << day;
		}
		else {
			cout << "0" << day;
		}
		cout << ".";
		if (month > 9) {
			cout << month;
		}
		else {
			cout << "0" << month;
		}
		cout << ".";
		cout << year;
		cout.width(delta); cout << " ";
	}



	void setName() {
		cout << "Введите имя студента: ";
		cin.getline(studentMenu.name, 30);
		while (!checkStringMenu(studentMenu.name)) {
			cout << "Имя содержит недопустимые символы, повторите ввод: ";
			cin >> studentMenu.name;
		}
		studentMenu.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setSurname() {
		cout << "Введите фамилию студента: ";
		cin.getline(studentMenu.surname, 30);
		while (!checkStringMenu(studentMenu.name)) {
			cout << "Фамилия содержит недопустимые символы, повторите ввод: ";
			cin >> studentMenu.surname;
		}
		studentMenu.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setPatronymic() {
		cout << "Введите отчество студента: ";
		cin.getline(studentMenu.patronymic, 30);
		while (!checkStringMenu(studentMenu.patronymic)) {
			cout << "Отчество содержит недопустимые символы, повторите ввод: ";
			cin >> studentMenu.patronymic;
		}
		studentMenu.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setBirthday() {
		cout << "Введите день рождения: ";
		cin >> studentMenu.birthDay;
		cout << "\nВведите месяц рождения: ";
		cin >> studentMenu.birthMonth;
		cout << "\nВведите год рождения: ";
		cin >> studentMenu.birthYear;
		while (!checkDateMenu(studentMenu.birthDay, studentMenu.birthMonth, studentMenu.birthYear)) {
			cout << "Введено неверное значение даты, повторите ввод: \n";
			cout << "Введите день рождения: ";
			cin >> studentMenu.birthDay;
			cout << "\nВведите месяц рождения: ";
			cin >> studentMenu.birthMonth;
			cout << "\nВведите год рождения: ";
			cin >> studentMenu.birthYear;
		}
		studentMenu.countFill += 3;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setYearStart() {
		cout << "Введите год начала учебной деятельности: ";
		cin >> studentMenu.yearStart;
		while (!checkYearStartMenu(studentMenu.yearStart)) {
			cout << "Введено неверное значение даты, повторите ввод: ";
			cin >> studentMenu.yearStart;
		}
		studentMenu.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}
	void setGroup() {
		cout << "Введите группу студента: ";
		cin.getline(studentMenu.group, 30);
		while (!checkGroupMenu(studentMenu.group)) {
			cout << "Введено неверное значение группы, повторите ввод: ";
			cin >> studentMenu.group;
		}
		studentMenu.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}

	void setInstitute() {
		cout << "Введите институт студента: ";
		cin.getline(studentMenu.institute, 30);
		while (!checkStringMenu(studentMenu.name)) {
			cout << "Институт содержит недопустимые символы, повторите ввод: ";
			cin >> studentMenu.surname;
		}
		studentMenu.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}

	void setDepartment() {
		cout << "Введите кафедру студента: ";
		cin.getline(studentMenu.department, 30);
		studentMenu.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;
	}

	void setID() {
		cout << "Введите студенческий билет студента: ";
		cin.getline(studentMenu.ID, 10);
		while (!checkIDMenu(studentMenu.ID)) {
			cout << "Введено неверное значение билета, повторите ввод: ";
			cin >> studentMenu.ID;
		}
		studentMenu.countFill++;
		CHOICE = page % maxCountOfStudents;
		system("cls");
		skipInput = true;

	}
	void setSex() {
		if (page % 10 == 1) { strcpy_s(studentMenu.sex, "Ж"); }
		else { strcpy_s(studentMenu.sex, "М"); }
		studentMenu.countFill++;
		CHOICE = 10;
		system("cls");
		skipInput = true;
		CHOICE = page % maxCountOfStudents;
	}
	void setExam(int _lessonNum = -1) {
		unsigned short numSess = page % 10 - 1;
		unsigned short grade;
		char nameLesson[30] = "";
		cout << "Введите название дисциплины: ";
		if (!firstEditSes)
			cin.ignore();
		cin >> nameLesson;
		cout << "\nВведите оценку за экзамен (2-5 оценка, 0-1 зачет/незачет):";
		cin >> grade;
		while (!checkGradeMenu(grade)) {
			cout << "Введено неверное значение, повторите ввод: ";
			cin >> grade;
		}
		studentMenu.exam.addLesson(numSess, nameLesson, grade, _lessonNum);
		firstEditSes = false;
		skipInput = true;
	}

	void writeToFile(FILE* _file) {
		fopen_s(&_file, "dbFile.txt", "w");
		char firstWord[30] = "Студент номер";
		char secondWord[30] = "Год рождения/поступления";
		char thirdWord[30] = "Данные учёбы";
		char fourthWord[30] = "Пол";
		char specialSymb[40] = "---------------------------------------";
		fprintf_s(_file, "%s\n", specialSymb);
		for (int i = 0; i < students.getSize(); i++) {
			fprintf_s(_file, "%s %d: %s %s %s\n%s: %d.%d.%d, %d\n%s: %s %s %s %s\n%s: %s\n", firstWord, (i + 1), \
				students[i].getSurname(), students[i].getName(), students[i].getPatronymic(), secondWord, \
				students[i].getBirthDay(), students[i].getBirthMonth(), students[i].getBirthYear(), \
				students[i].getYearStart(), thirdWord, students[i].getInstitute(), students[i].getDepartment(),
				students[i].getGroup(), students[i].getID(), fourthWord, students[i].getSex());

			int countOfExams = 0;
			for (int ses = 0; ses < 9; ses++) {
				for (int les = 0; les < 10; les++) {
					if (!students[i].getExam().lessons[ses][les].empty) {
						countOfExams++;
					}
				}
			}

			fprintf_s(_file, "Число сданных экзаменов: %d\n", countOfExams);
			for (int s = 0; s < 9; s++) {
				for (int l = 0; l < 10; l++) {
					if (!students[i].getExam().lessons[s][l].empty) {
						fprintf_s(_file, "Сессия %d, экзамен %d: %s %d\n", (s + 1), (l + 1), \
							students[i].getExam().lessons[s][l].nameLesson, students[i].getExam().lessons[s][l].grade);
					}
				}
			}
			fprintf_s(_file, "%s\n", specialSymb);
		}
		fclose(_file);
		fopen_s(&_file, "dbFile.txt", "a+");
	}


	bool page_0(const unsigned int& _currentChoice) {
		len = listMenu.listMainMenu.getSize();
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		cout << listMenu.listMainMenu[_currentChoice] << endl;
		if (_currentChoice + 1 == len) return false;
		return true;


	}

	bool page_1(const unsigned int& _currentChoice) {
		len = students.getSize() + 2;
		ClassStudent tempStudent;
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		if (_currentChoice == 0) cout << "Удалить студента" << endl;

		else if (_currentChoice + 1 <= len - 1) {
			cout << students[_currentChoice - 1] << endl;
		}
		else cout << "Назад";
		if (_currentChoice + 1 == len) return false;
		return true;

	}
	bool page_2(const unsigned int& _currentChoice) {
		if (firstPage2) {
			cout << "Имя: " << studentMenu.name << "\nФамилия: " << studentMenu.surname << "\nОтчество: " << studentMenu.patronymic << endl;
			cout << "Дата рождения: "; printDate(studentMenu.birthDay, studentMenu.birthMonth, studentMenu.birthYear, 7);
			cout << "\nГод начала обучения: " << studentMenu.yearStart << "\nПол: " << (choiceSex ? (studentMenu.sex == 0 ? "Женский" : "Мужской") : "") << endl;
			cout << "Номер зачетной книжки: " << studentMenu.ID << "\nГруппа: " << studentMenu.group;
			cout << "\nИнститут: " << studentMenu.institute << "\nКафедра: " << studentMenu.department << endl;
			firstPage2 = false;
		}
		len = listMenu.listNewStudentMenu.getSize();
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		cout << listMenu.listNewStudentMenu[_currentChoice] << endl;
		if (_currentChoice + 1 == len) return false;
		return true;

	}
	bool page_3(FILE* _file) {
		len = 1;
		system("cls");
		cout << "БД записана в файл 'dbFile.txt' \n";
		//writeToFile(_file);
		system("PAUSE");
		page = 0;
		skipInput = true;
		return false;

	}

	bool page_4(const unsigned int& _currentChoice) {
		if (firstPage4) {
			cout << "Выберите сессии, в которых хотите увидеть средние\nоценки студентов с интервалом года рождения.\nНаведитесь на интересующую Вас сессию и нажмите Enter:" << endl;
			firstPage4 = false;
		}
		len = listMenu.listVar60_1.getSize();
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		cout << listMenu.listVar60_1[_currentChoice] << endl;
		if (_currentChoice + 1 == len) return false;
		return true;
	}
	bool page_printDeleteStudents(const unsigned int& _currentChoice) {
		len = students.getSize() + 1;
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		if (_currentChoice + 1 != len) {
			cout << students[_currentChoice] << endl;
			return true;
		}
		cout << "Назад";
		return false;


	}
	bool page_printEditList(const unsigned int& _currentChoice) {
		len = listMenu.listCurrentStudentMenu.getSize();
		(CHOICE == _currentChoice + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
		cout << listMenu.listCurrentStudentMenu[_currentChoice] << endl;
		firstEditSes = true;
		if (_currentChoice + 1 == len) return false;
		return true;


	}


	void draw(FILE* file) {
		fopen_s(&file, "dbFile.txt", "a+");
		int tempLenFile = 10;
		for (int i = 1; i <= tempLenFile; i++) {
			ClassStudent tempStudent;
			char studentWord[7], numWord[5], specialSymb[40], yearWord[3], yearChoiceWord[25], dataWord[10], knowWord[10], sexWord[10];
			int numStudent = 0;
			char name[30], surname[30], patronymic[30], institute[30], department[30], group[30], ID[30], sex[30];
			unsigned short birthDay = 0, birthMonth = 0, birthYear = 0, yearStart = 0;

			fscanf_s(file, "%s", specialSymb, _countof(specialSymb));

			fscanf_s(file, "%s", studentWord, _countof(studentWord));
			fscanf_s(file, "%s", numWord, _countof(numWord));
			fscanf_s(file, "%d:", &numStudent);
			fscanf_s(file, "%s", surname, _countof(surname));
			fscanf_s(file, "%s",name, _countof(name));
			fscanf_s(file, "%s", patronymic, _countof(patronymic));

			fscanf_s(file, "%s", yearWord, _countof(yearWord));
			fscanf_s(file, "%s:", yearChoiceWord, _countof(yearChoiceWord));
			fscanf_s(file, "%d.", &birthDay);
			fscanf_s(file, "%d.", &birthMonth);
			fscanf_s(file, "%d,", &birthYear);
			fscanf_s(file, "%d", &yearStart);

			fscanf_s(file, "%s", dataWord, _countof(dataWord));
			fscanf_s(file, "%s", knowWord, _countof(knowWord));
			fscanf_s(file, "%s", institute, _countof(institute));
			fscanf_s(file, "%s", department, _countof(department));
			fscanf_s(file, "%s", group, _countof(group));
			fscanf_s(file, "%s", ID, _countof(ID));

			fscanf_s(file, "%s:", sexWord, _countof(sexWord));
			fscanf_s(file, "%s", sex, _countof(sex));

			tempStudent.addName(name); tempStudent.addSurname(surname); tempStudent.addPatronymic(patronymic);
			tempStudent.addBirth(birthDay, birthMonth, birthYear); tempStudent.addYearStart(yearStart);
			tempStudent.addInstitute(institute); tempStudent.addDepartment(department); tempStudent.addGroup(group); tempStudent.addID(ID); tempStudent.addSex(sex);

			char numExamsWord[10], passWord[10], examsWord[10];
			int countExams;
			fscanf_s(file, "%s ", numExamsWord, _countof(numExamsWord));
			fscanf_s(file, "%s ", passWord, _countof(passWord));
			fscanf_s(file, "%s: ", examsWord, _countof(examsWord));
			fscanf_s(file, "%d", &countExams);
			for (int j = 1; j <= countExams; j++){
				char nameOfLesson[30], sesWord[6], examWord[7];
				int numSes, numExam, grade;
				fscanf_s(file, "%s", sesWord, _countof(sesWord));
				fscanf_s(file, "%d,", &numSes);
				fscanf_s(file, "%s", examWord, _countof(examWord));
				fscanf_s(file, "%d:", &numExam);
				fscanf_s(file, "%s", nameOfLesson, _countof(nameOfLesson));
				fscanf_s(file, "%d", &grade);
				tempStudent.fillExam(numSes - 1, nameOfLesson, grade);
			}
			fscanf_s(file, "%s", specialSymb, _countof(specialSymb));
			students.addElem(tempStudent);
		}


		while (true) {
			system("cls"); // очищаем экран
			SetConsoleTextAttribute(h, 0x0007);
			cout << "Меню:" << endl;

			skipInput = false;

			for (int i = 0; i < 15; i++) {
				if (page == 0) {
					if (!page_0(i)) break;
				}
				if (page == 1) {
					if (!page_1(i)) break;
				}
				if (page == 2) {
					if (!page_2(i)) break;
				}
				if (page == 3) {
					if (!page_3(file)) break;
				}
				if (page == 4) {
					if (!page_4(i)) break;
				}
				if (page == maxCountOfStudents + 1) {
					if (!page_printDeleteStudents(i)) break;
				}
				if (page >= maxCountOfStudents + 2 and page <= 2 * maxCountOfStudents - 1) {
					if (!page_printEditList(i)) break;
				}

				if (page / maxCountOfStudents >= maxCountOfStudents + 2 and page / maxCountOfStudents <= 2 * maxCountOfStudents - 1 or (page == ((maxCountOfStudents + 2) * maxCountOfStudents + 10) * maxCountOfStudents + 1 or page == ((maxCountOfStudents + 2) * maxCountOfStudents + 10) * maxCountOfStudents + 2) or changeExam or addExam or editExam) {

					if (page == ((maxCountOfStudents + 2) * maxCountOfStudents + 10) * maxCountOfStudents + 1 or page == ((maxCountOfStudents + 2) * maxCountOfStudents + 10) * maxCountOfStudents + 2) {
						setSex();
						students[(int)(page / maxCountOfStudents / maxCountOfStudents % maxCountOfStudents - 2)].addSex(studentMenu.sex);
						page = page / maxCountOfStudents / maxCountOfStudents;
					}
					else if (changeExam) {
						if (firstPage1Exam)
							cout << "Изменить/добавить предмет:\n";
						firstPage1Exam = false;
						students[page / maxCountOfStudents / maxCountOfStudents % maxCountOfStudents - 2].copyExam(studentMenu.exam);
						len = studentMenu.exam.countLessons(page % 10 - 1) + 2;
						if (i < len - 2) {
							int grade = studentMenu.exam.lessons[page % maxCountOfStudents - 1][i].grade;
							(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
							cout << studentMenu.exam.lessons[page % maxCountOfStudents - 1][i].nameLesson << " Оценка: ";
							if (grade == 1 or grade == 0) {
								if (grade == 1) cout << "Зачёт\n";
								else cout << "Незачёт\n";
							}
							else cout << grade << "\n";

						}
						if (i + 1 == len - 1) {
							(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
							cout << listMenu.AddLast[0] << "\n";
						}
						else if (i == len - 1) {
							(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
							cout << listMenu.AddLast[1] << "\n";
						}
						before_addExam = true;
						before_editExam = true;
						if (i == len - 1) {
							break;
						}

					}
					else if (addExam) {
						setExam();
						students[(int)(page / maxCountOfStudents / maxCountOfStudents % maxCountOfStudents - 2)].addExam(studentMenu.exam);
						changeExam = true;
						addExam = false;
						skipInput = true;
						break;

					}
					else if (editExam) {
						setExam(choice - 1);
						students[(int)(page / maxCountOfStudents / maxCountOfStudents % maxCountOfStudents - 2)].addExam(studentMenu.exam);
						changeExam = true;
						addExam = false;
						skipInput = true;
						break;

					}
					else if (page % 1000 == 1) {
						setName();
						students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].addName(studentMenu.name);
						page = page / maxCountOfStudents;
						break;
					}
					else if (page % maxCountOfStudents == 2) {
						setSurname();
						students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].addSurname(studentMenu.surname);
						page = page / maxCountOfStudents;
						break;
					}
					else if (page % maxCountOfStudents == 3) {
						setPatronymic();
						students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].addPatronymic(studentMenu.patronymic);
						page = page / maxCountOfStudents;
						break;
					}
					else if (page % maxCountOfStudents == 4) {
						setBirthday();
						students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].addBirth(studentMenu.birthDay, studentMenu.birthMonth, studentMenu.birthYear);
						page = page / maxCountOfStudents;
						break;
					}
					else if (page % maxCountOfStudents == 5) {
						setYearStart();
						students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].addYearStart(studentMenu.yearStart);
						page = page / maxCountOfStudents;
						break;
					}
					else if (page % maxCountOfStudents == 6) {
						setGroup();
						students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].addGroup(studentMenu.group);
						page = page / maxCountOfStudents;
						break;
					}
					else if (page % maxCountOfStudents == 7) {
						setDepartment();
						students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].addDepartment(studentMenu.department);
						page = page / maxCountOfStudents;
						break;
					}
					else if (page % maxCountOfStudents == 8) {
						setInstitute();
						students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].addInstitute(studentMenu.institute);
						page = page / maxCountOfStudents;
						break;
					}
					else if (page % maxCountOfStudents == 9) {
						setID();
						students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].addID(studentMenu.ID);
						page = page / maxCountOfStudents;
						break;
					}

					else if (page % maxCountOfStudents == 10) {
						len = 3;
						(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						if (i + 1 < len) cout << listMenu.listSex[i] << endl;
						else {
							cout << "Назад";
							break;
						}
					}
					else if (page % maxCountOfStudents == 11) {
						len = listMenu.listExams.getSize();
						(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						cout << listMenu.listExams[i] << endl;
						before_changeExam = true;
						if (i + 1 == len) break;
					}
					else if (page % maxCountOfStudents == 12) {
						system("cls");
						char _key = 0;
						while (_key != 13) {
							students[(int)(page / maxCountOfStudents % maxCountOfStudents - 2)].printAllData();
							cout << "Для выхода нажмите Enter\n";
							_key = _getch();
							system("cls");

						}
						page = page / maxCountOfStudents;
						skipInput = true;
						break;

					}

				}
				if (page >= (maxCountOfStudents + 1) * maxCountOfStudents + 1 and page <= (maxCountOfStudents + 1) * maxCountOfStudents + maxCountOfStudents - 1) {
					len = students.getSize();
					size_t index = (page - (maxCountOfStudents + 1) * maxCountOfStudents) - 1;
					cout << students[index];
					students.removeElem(index);
					len--;
					system("cls");
					page = 1; CHOICE = 1; i = 0;
					skipInput = true;

				}
				if (page > 2 * maxCountOfStudents) {
					if (page == 2 * maxCountOfStudents + 1) {
						setName();
						CHOICE = page % maxCountOfStudents;
						system("cls");
						skipInput = true;
						page = 2;
					}
					if (page == 2 * maxCountOfStudents + 2) {
						setSurname();
						CHOICE = page % maxCountOfStudents;
						system("cls");
						skipInput = true;
						page = 2;
					}
					if (page == 2 * maxCountOfStudents + 3) {
						setPatronymic();
						CHOICE = page % maxCountOfStudents;
						system("cls");
						skipInput = true;
						page = 2;
					}
					if (page == 2 * maxCountOfStudents + 4) {
						setBirthday();
						CHOICE = page % maxCountOfStudents;
						system("cls");
						skipInput = true;
						page = 2;
					}
					if (page == 2 * maxCountOfStudents + 5) {
						setYearStart();
						CHOICE = page % maxCountOfStudents;
						system("cls");
						skipInput = true;
						page = 2;
					}
					if (page == 2 * maxCountOfStudents + 6) {
						setGroup();
						CHOICE = page % maxCountOfStudents;
						system("cls");
						skipInput = true;
						page = 2;
					}
					if (page == 2 * maxCountOfStudents + 7) {
						setDepartment();
						CHOICE = page % maxCountOfStudents;
						system("cls");
						skipInput = true;
						page = 2;
					}
					if (page == 2 * maxCountOfStudents + 8) {
						setInstitute();
						CHOICE = page % maxCountOfStudents;
						system("cls");
						skipInput = true;
						page = 2;
					}
					if (page == 2 * maxCountOfStudents + 9) {
						setID();
						page = 2;
					}
					if (page == 2 * maxCountOfStudents + 10) {
						len = 3;
						(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						if (i + 1 < len) cout << listMenu.listSex[i] << endl;
						else {
							cout << "Назад";
							break;
						}
					}
					if (page == (2 * maxCountOfStudents + 10) * maxCountOfStudents + 1 or page == (2 * maxCountOfStudents + 10) * maxCountOfStudents + 2) {
						setSex();
						page = 2;
						choiceSex = true;
					}
					if (page == 2 * maxCountOfStudents + 11) {
						len = listMenu.listExams.getSize();
						(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
						cout << listMenu.listExams[i] << endl;
						if (i + 1 == len) break;

					}
					if (page >= (2 * maxCountOfStudents + 11) * maxCountOfStudents + 1 and page < (2 * maxCountOfStudents + 11) * maxCountOfStudents + 9) {
						setExam();
						page = 2;

					}

					if (page == 2 * maxCountOfStudents + 12) {
						len = 2;
						if (studentMenu.countFill >= 12) {
							ClassStudent newStudent(studentMenu.name, studentMenu.surname, studentMenu.patronymic, studentMenu.birthDay, \
								studentMenu.birthMonth, studentMenu.birthYear, studentMenu.yearStart, studentMenu.institute, studentMenu.department, \
								studentMenu.group, studentMenu.ID, studentMenu.sex, studentMenu.exam);
							students.addElem(newStudent);
							page = 0;
							tempLenFile++;
							skipInput = true;
						}
						else {

							if (allAddedFirst)cout << "Вы ввели не все данные о студенте, вы уверенны что хотите выйти?\nCтудент не будет занесен в базу данных\n";
							(CHOICE == i + 1 ? SetConsoleTextAttribute(h, 0x000A) : SetConsoleTextAttribute(h, 0x0007));
							cout << listMenu.listSafeStudent[i] << endl;
							if (i + 1 == len) break;
							allAddedFirst = false;
						}
					}
					//var60
					if (page > 4 * maxCountOfStudents) {
						if (page == 4 * maxCountOfStudents + 1) {
							listMenu.listVar60_1.insertElem(1, "Сессия 1 - выбрано");
							listMenu.listVar60_1.removeElem(0);
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							numsSes[0] = 1;
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 2) {
							listMenu.listVar60_1.insertElem(2, "Сессия 2 - выбрано");
							listMenu.listVar60_1.removeElem(1);
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							numsSes[1] = 2;
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 3) {
							listMenu.listVar60_1.insertElem(3, "Сессия 3 - выбрано");
							listMenu.listVar60_1.removeElem(2);
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							numsSes[2] = 3;
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 4) {
							listMenu.listVar60_1.insertElem(4, "Сессия 4 - выбрано");
							listMenu.listVar60_1.removeElem(3);
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							numsSes[3] = 4;
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 5) {
							listMenu.listVar60_1.insertElem(5, "Сессия 5 - выбрано");
							listMenu.listVar60_1.removeElem(4);
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							numsSes[4] = 5;
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 6) {
							listMenu.listVar60_1.insertElem(6, "Сессия 6 - выбрано");
							listMenu.listVar60_1.removeElem(5);
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							numsSes[5] = 6;
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 7) {
							listMenu.listVar60_1.insertElem(7, "Сессия 7 - выбрано");
							listMenu.listVar60_1.removeElem(6);
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							numsSes[6] = 7;
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 8) {
							listMenu.listVar60_1.insertElem(8, "Сессия 8 - выбрано");
							listMenu.listVar60_1.removeElem(7);
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							numsSes[7] = 8;
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 9) {
							listMenu.listVar60_1.insertElem(9, "Сессия 9 - выбрано");
							listMenu.listVar60_1.removeElem(8);
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							numsSes[8] = 9;
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 10) {
							//Выбор всех
							listMenu.listVar60_1 = listMenu.listVar60_2;
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							for (int i = 0; i < 9; i++) {
								numsSes[i] = i + 1;
							}
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 11) {
							//Очитска выбора
							listMenu.listVar60_1 = listMenu.listVar60_clear;
							CHOICE = page % maxCountOfStudents;
							system("cls");
							skipInput = true;
							for (int i = 0; i < 9; i++) {
								numsSes[i] = -1;
							}
							page = 4;
						}
						if (page == 4 * maxCountOfStudents + 12) {
							//Произведение рассчетов
							var60();
							page = 4;
							skipInput = true;
						}

						
					}
				}
			}
			firstPage1Exam = true;
			firstPage2 = true;
			firstPage4 = true;
			if (skipInput) continue;

			// ждем нажатия клавиши
			key = _getch();

			// обрабатываем нажатие клавиши
			switch (key) {
			case 72: // стрелка вверх
				CHOICE--;
				if (CHOICE < 1) CHOICE = len;
				break;
			case 80: // стрелка вниз
				CHOICE++;
				if (CHOICE > len) CHOICE = 1;
				break;
			case 13: // Enter
				system("cls");
				if (CHOICE == len) {
					if (page == 0) {
						fclose(file);
						SetConsoleTextAttribute(h, 0x0007);
						return;
					}
					//var60
					else if (page == 4) {
						page = 4 * maxCountOfStudents + 10;
					}
					//
					else if (page == 2) {
						page = 2 * maxCountOfStudents + 12;
					}
					else if (page == 2 * maxCountOfStudents + 12) {
						clearStudent();
						page = 0;
					}
					else if (changeExam) {
						changeExam = false;
						before_addExam = false;
						before_editExam = false;
						editExam = false;
						before_changeExam = false;
						page = page / maxCountOfStudents;
					}
					else if (page % maxCountOfStudents == 11 and before_changeExam) {
						before_changeExam = false;
						page = page / maxCountOfStudents;
					}
					else page = page / maxCountOfStudents;

				}
				else {
					if (before_changeExam) {
						changeExam = true;
						before_changeExam = false;
						page = page * maxCountOfStudents + CHOICE;
					}
					else if (page == 2 * maxCountOfStudents + 12) page = page / maxCountOfStudents;
					else if (CHOICE == len - 1 and before_addExam) {
						before_addExam = false;
						changeExam = false;
						addExam = true;
					}
					else if (before_editExam) {
						before_editExam = false;
						changeExam = false;
						editExam = true;
					}
					else page = page * maxCountOfStudents + CHOICE;


				}
				choice = CHOICE;
				CHOICE = 1;

				choiceSex = false;
			}
		}
	}
};
