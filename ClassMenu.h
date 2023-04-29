#pragma once
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "List.h"
#include "ClassStudent.h"
using namespace std;
struct ListMenu {
	clList <string> mainMenu;
	clList <string> studentMenu;
	clList <string> sexMenu;
	clList <string> examsMenu;
};

class ClassMenu
{
private:
	string upTitle;
	string items[100];
	bool isTakenItem = false;
public:
	ClassMenu() : upTitle("Заголовок") {}

	ClassMenu(string upTitle) {
		this->upTitle = upTitle;
	}
	int getItemCount() {
		int count = 0;
		for (int i = 0; i < 100; i++) {
			if (items[i].length() > 0) {
				count++;
			}
		}
		return count;
	}
	void addItemMenu(string _item) {
		int count = getItemCount();
		items[count] = _item;
	}
	void deleteItemMenu(string _item) {
		int count = getItemCount();
		items[count] = "";
	}
	string getItemMenu(int _count) {
		return items[_count];
	}

	void drawMenu() {
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << upTitle << endl;
		int count = getItemCount();
		for (int i = 0; i < count; i++) {
			cout << i << "." << items[i] << endl;
		}
	}

	int getVariant(int _count) {
		int variant;
		char s[100];
		cin >> s; 

		while (sscanf_s(s, "%d", &variant) != 1 || variant < 0 || variant > _count) {
			cout << "Неверный ввод, попрбуйте снова: ";
			cin >> s;
		}
		return variant;
	}


	void switchMainTable(int _variant, ClassMenu _mainMenu, ClassMenu _studentMenu) {
		int variant = _variant;
		clStudent student;
		do {
			_mainMenu.drawMenu();
			switch (variant) {
				case 0:
					//Добавление студента
					system("cls");
					cout << 0 << endl;
					break;
				case 1:
					system("cls");
					//Поиск студента по ID
					cout << 1 << endl;
					break;
				case 2:
					system("cls");
					//Удалить студента
					cout << 2 << endl;
					break;
				case 3:
					system("cls");
					//Зашифровать данные
					cout << 3 << endl;
					break;
				case 4:
					system("cls");
					//Выполнить вариант 60
					cout << 4 << endl;
					break;
			}
			if (variant != 5) { system("pause"); }
		\
		//Выход из меню/подменю
		} while (variant != 5);

		return exitTable();
	}

	void switchStudentTable(int _variant, ClassMenu _studentMenu) {
		int variant = _variant;
		const unsigned int SIZE = 3;
		string arInitials[SIZE] = {"Имя", "Фамилия", "Отчество"};
		do {
			_studentMenu.drawMenu();
			switch (variant) {
			case 0:
				
				break;
			case 1:
				//_student.addDate();
				break;
			case 2:
				//_student.addInstituteData();
				break;
			case 3:
				//_student.addSex();
				break;
			case 4:
				//_student.addExams();
				break;
			}
			if (variant != 5) { system("pause"); }

		} while (variant != 5);
	}
	//Вариант 60. Найти и распечатать все данные о студентах, которые 
	//успевают с наибольшим и наименьшим успехом в одной, нескольких или всех
	//сессиях, выбираемых по желанию пользователя, с указанием интервала года
	//рождения.
	void completeIndividualVar() {

	}
	void exitTable() {
		system("cls");
		cout << "Произведен выход из работы\n";
		exit(0);
	}

};

class IndividualVarinant {

};

class Encryption {

};
