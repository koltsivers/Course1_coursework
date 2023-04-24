#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "ClassMenu.h"
#include "ClassStudent.h"
#include "Exams.h"
#include "List.h"
using namespace std;

void writeToFile(FILE* file) {
	fopen_s(&file, "File.txt", "a+");
}
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
	ClassMenu* studentMenu = new ClassMenu("Заполнение данных студента");;
	studentMenu->addItemMenu("Заполнить инициалы");
	studentMenu->addItemMenu("Добавить дату рождения и год поступления");
	studentMenu->addItemMenu("Выбрать пол");
	studentMenu->addItemMenu("Ввести данные о сессии");
	studentMenu->addItemMenu("Выход");

	ClassMenu* sexMenu = new ClassMenu("Выбор пола");
	sexMenu->addItemMenu("Мужской");
	sexMenu->addItemMenu("Женский");
	sexMenu->addItemMenu("Выход");
	return 0;
};
