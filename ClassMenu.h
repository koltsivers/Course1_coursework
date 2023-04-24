#pragma once
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "ClassStudent.h"
using namespace std;

class ClassMenu
{
private:
	string upTitle;
	string items[100];
	bool isTakenItem = false;
public:
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
	//int swappingTable(int _choice, ClassMenu _menu) {
	//	int currentItem = _choice;
	//	int key = _getch();
	//	while (((key = _getch()) != '\n') && key != EOF) {
	//		//Стрелка вверх/ w
	//		if (key == 119) {
	//			currentItem++;
	//			for (int i = 0; i < _menu.getItemCount(); i++)
	//			{
	//				;
	//			}
	//			cout << currentItem << endl;
	//		}
	//		//Стрелка вниз / s
	//		if (key == 115) {
	//			currentItem--;
	//			cout << currentItem << endl;

	//		}
	//		//Enter
	//		if (key == 13) {
	//			return currentItem;

	//		}
	//		else {
	//			return 000000000000000000000000;
	//		}
	//	}
	//}

	int get_variant(int _count) {
		int variant;
		char s[100];
		cin >> s; 

		while (sscanf_s(s, "%d", &variant) != 1 || variant < 0 || variant > _count) {
			cout << "Неверный ввод, попрбуйте снова: ";
			cin >> s;
		}
		return variant;
	}


	int switchTable(ClassMenu _mainMenu, ClassMenu _studentMenu) {
		int variant = get_variant(5);
		do {
			_mainMenu.drawMenu();
			switch (variant) {
				case 0:
					//Добавление студента
					break;
				case 1:
					//Поиск студента по ID
					cout << 1 << endl;
					break;
				case 2:
					//Удалить студента
					cout << 2 << endl;
					break;
				case 3:
					//Зашифровать данные
					cout << 3 << endl;
					break;
				case 4:
					//Выполнить вариант 60
					cout << 4 << endl;
					break;
			}
			if (variant != 5) { system("pause"); }

		} while (variant != 5);

		return 0;
	}

	void completeIndividualVar() {

	}
	void exitTable() {
		cout << "Произведен выход из работы" << endl;
		exit(0);
	}

};


class IndividualVarinant {

};

class Encryption {

};
