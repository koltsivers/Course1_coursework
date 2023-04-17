#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "ClassMenu.h"
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
			Sleep(50);
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
	StudentMenu* studentMenu = new StudentMenu("Заполненине данных студента");
	studentMenu->addItemMenu("Заполнить инициалы");
	studentMenu->addItemMenu("Добавить год рождения и поступления");
	studentMenu->addItemMenu("Выбрать пол");
	studentMenu->addItemMenu("Ввести данные о сессии");
	studentMenu->drawMenu();
	system("pause");
	return 0;

};
