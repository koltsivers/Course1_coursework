#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "ClassMenu.h"
#include "ClassStudent.h"
#include "Exams.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	string compilanceCourseWork = "Выполнение курсовой работы...";
	for (int i = 0; i < compilanceCourseWork.length()+1; i++) {
		if (i < compilanceCourseWork.length()) {
			//SetConsoleTextAttribute(hOUTPUT, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << compilanceCourseWork[i];
			Sleep(25);
		}
	}
	system("cls");
	ClassMenu* mainMenu = new ClassMenu("Заглавное меню");
	mainMenu->addItemMenu("Добавить студента");
	mainMenu->addItemMenu("Поиск студента по номеру студенческого билета");
	mainMenu->addItemMenu("Удалить студента");
	mainMenu->addItemMenu("Зашифровать данные");
	mainMenu->addItemMenu("Выполнить вариант 60");
	mainMenu->addItemMenu("Выход");
	mainMenu->drawMenu();
	cout << endl;
	StudentMenu* studentMenu = new StudentMenu("");;
	studentMenu->addItemMenu("Заполнить инициалы");
	studentMenu->addItemMenu("Добавить год рождения и поступления");
	studentMenu->addItemMenu("Выбрать пол");
	studentMenu->addItemMenu("Ввести данные о сессии");
	int countItems = mainMenu->getItemCount();


	int key = _getch();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int firstItem = 0;
	int selectedItem = 0;
	for (int i = 0; i < (int)(mainMenu->getItemCount()); i++){
		//Enter
		if (key == 13) {
			system("cls");
			
		}
		//Arrow up
		if (key == 38) {
			system("cls");
			if (selectedItem - mainMenu->getItemCount() == 1) {
				selectedItem = 0;
				SetConsoleTextAttribute(h, 0x000A);
				mainMenu->getItemMenu(selectedItem);
			}
			else {
				selectedItem++;
			}
			
		}
		//Arrow down
		if (key == 40) {
			system("cls");
			if (selectedItem < firstItem) {
				selectedItem == 5;
				SetConsoleTextAttribute(h, 0x000A);
				mainMenu->getItemMenu(selectedItem);
			}
			else {
				selectedItem--;
			}
			
		}
	}
	return 0;

};
