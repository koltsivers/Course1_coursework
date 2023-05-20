#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include "ClassMenu.h"
#include "ClassStudent.h"
#include "ClassExams.h"
using namespace std;

void crypt() {
	srand(time(NULL));
	const int SIZE = 64;
	char* pass = new char[SIZE];
	for (int i = 0; i < SIZE; i++){
		switch(rand() % 3) {
		case 0 :
			pass[i] = rand() % 10 + '0';
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';
		}
	}
	pass[63] = '\0';

	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in file.bin -out file.bin.enc -pass pass:";
	command += pass;
	system(command.c_str());

	if (remove("dbFile.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}

	ofstream file;
	file.open("key.txt", ios::binary);
	file.write(pass, 65);
	file.close();

	command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
	system(command.c_str());

	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
}

void decrypt() {
	string command = "openssl\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
	system(command.c_str());

	if (remove("key.txt.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}

	char* pass = new char[64];
	ifstream file;
	file.open("key.txt", ios::binary);
	file.read(pass, 65);
	file.close();

	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	
	command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in file.bin.enc -out file.bin -pass pass:";
	command += pass;
	system(command.c_str());


	if (remove("dbFile.txt.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}

}
void WRITE(FILE* file) {
	fopen_s(&file, "dbFile.txt", "w");
	ClassList <ClassStudent> tempStudents;
	
	ClassStudent Dany("Атавин", "Даниил", "Антонович", 07, 02, 2005, 2022, "ИКБ", "КБ-02", "БИСО-01-22", "22Б8660", "Мужской");
	Dany.fillExam(0, "Физика", 5); Dany.fillExam(0, "История", 5); Dany.fillExam(0, "Лин.Алгебра", 5); Dany.fillExam(0, "Мат.Анализ", 5); Dany.fillExam(0, "ОИБ", 5);
	Dany.fillExam(1, "Физика", 5); Dany.fillExam(1, "Философия", 5); Dany.fillExam(1, "Физкультура", 5); Dany.fillExam(1, "Англ.Язык", 5); Dany.fillExam(1, "Ознак.Практика", 5);
	tempStudents.addElem(Dany);
	
	ClassStudent Maxim("Бовин", "Максим", "Олегович", 23, 05, 2003, 2022, "ИКБ", "КБ-03", "БАСО-03-22", "22Б8661", "Мужской");
	Maxim.fillExam(0, "Физика", 4); Maxim.fillExam(0, "История", 5); Maxim.fillExam(0, "Лин.Алгебра", 4); Maxim.fillExam(0, "Мат.Анализ", 4);
	Maxim.fillExam(1, "Физика", 4); Maxim.fillExam(1, "Философия", 3); Maxim.fillExam(1, "Физкультура", 5); Maxim.fillExam(1, "Англ.Язык", 4);
	tempStudents.addElem(Maxim);

	ClassStudent Ksenia("Брайнин", "Ксения", "Алексеевна", 30, 10, 2004, 2022, "ИКБ", "КБ-03", "БАСО-03-22", "22Б1003", "Женский");
	Ksenia.fillExam(0, "Физика", 3); Ksenia.fillExam(0, "История", 3); Ksenia.fillExam(0, "Лин.Алгебра", 4); Ksenia.fillExam(0, "Мат.Анализ", 3); Ksenia.fillExam(0, "ОИБ", 4);
	Ksenia.fillExam(1, "Физика", 4); Ksenia.fillExam(1, "Философия", 3); Ksenia.fillExam(1, "Физкультура", 5);
	tempStudents.addElem(Ksenia);

	ClassStudent Alina("Грибанова", "Алина", "Владимировна", 01, 02, 2004, 2022, "ИКБ", "КБ-03", "БАСО-03-22", "22Б0864", "Женский");
	Alina.fillExam(0, "Лин.Алгебра", 4); Alina.fillExam(0, "Мат.Анализ", 4); Alina.fillExam(0, "ОИБ", 4);
	Alina.fillExam(1, "Философия", 3); Alina.fillExam(1, "Англ.Язык", 4); Alina.fillExam(1, "Ознак.Практика", 5);
	tempStudents.addElem(Alina);
	
	ClassStudent Ilya("Долгов", "Илья", "Сергеевич", 15, 03, 2003, 2022, "ИКБ", "КБ-03", "БАСО-03-22", "22Б0866", "Мужской");
	Ilya.fillExam(0, "Физика", 5); Ilya.fillExam(0, "История", 5); Ilya.fillExam(0, "Лин.Алгебра", 5); Ilya.fillExam(0, "Мат.Анализ", 5); Ilya.fillExam(0, "ОИБ", 5);
	Ilya.fillExam(1, "Физика", 5); Ilya.fillExam(1, "Философия", 3); Ilya.fillExam(1, "Физкультура", 5); Ilya.fillExam(1, "Ознак.Практика", 5);
	tempStudents.addElem(Ilya);
	
	ClassStudent Nastya("Ерофеева", "Анастасия", "Александрова", 06, 06, 2004, 2022, "ИКБ", "КБ-02", "БАСО-03-22", "22Б0868", "Женский");
	Nastya.fillExam(0, "Физика", 3); Nastya.fillExam(0, "История", 4); Nastya.fillExam(0, "Лин.Алгебра", 5); Nastya.fillExam(0, "Мат.Анализ",5);
	Nastya.fillExam(1, "Физика", 3); Nastya.fillExam(1, "Философия", 3); Nastya.fillExam(1, "Физкультура", 4); Nastya.fillExam(1, "Англ.Язык", 3); Nastya.fillExam(1, "Ознак.Практика", 4);
	tempStudents.addElem(Nastya);
	
	ClassStudent Alex("Кондрашкин", "Александр", "Олегович", 06, 11, 2004, 2022, "ИКБ", "КБ-02", "БИСО-01-22", "22Б0875", "Мужской");
	Alex.fillExam(0, "Физика", 5); Alex.fillExam(0, "История", 5); Alex.fillExam(0, "Лин.Алгебра", 5); Alex.fillExam(0, "Мат.Анализ", 5); Alex.fillExam(0, "ОИБ", 4);
	Alex.fillExam(1, "Физика", 4); Alex.fillExam(1, "Философия", 5); Alex.fillExam(1, "Физкультура", 5); Alex.fillExam(1, "Англ.Язык", 5); Alex.fillExam(1, "Ознак.Практика", 4);
	tempStudents.addElem(Alex);
	
	ClassStudent Vlad("Королев", "Владислав", "Денисович", 12, 01, 2004, 2022, "ИКБ", "КБ-02", "БИСО-01-22", "22Б0877", "Мужской");
	Vlad.fillExam(0, "Физика", 4); Vlad.fillExam(0, "История", 5); Vlad.fillExam(0, "Лин.Алгебра", 4); Vlad.fillExam(0, "Мат.Анализ", 4); Vlad.fillExam(0, "ОИБ", 4);
	Vlad.fillExam(1, "Физика", 4); Vlad.fillExam(1, "Философия", 3); Vlad.fillExam(1, "Физкультура", 5); Vlad.fillExam(1, "Англ.Язык", 4); Vlad.fillExam(1, "Ознак.Практика", 5);
	tempStudents.addElem(Vlad);

	ClassStudent Kostya("Папин", "Константин", "Михайлович", 25, 01, 2005, 2022, "ИКБ", "КБ-04", "ББББ-06-22", "22Б0884", "Мужской");
	Kostya.fillExam(0, "Физика", 3); Kostya.fillExam(0, "История", 5); Kostya.fillExam(0, "Мат.Анализ", 4); Kostya.fillExam(0, "ОИБ", 4);
	Kostya.fillExam(1, "Философия", 3); Kostya.fillExam(1, "Физкультура", 5); Kostya.fillExam(1, "Англ.Язык", 4); Kostya.fillExam(1, "Ознак.Практика", 5);
	tempStudents.addElem(Kostya);

	ClassStudent Artem("Франк", "Артём", "Александрович", 23, 04, 2004, 2022, "ИКБ", "КБ-04", "ББББ-06-22", "22Б0896", "Мужской");
	Artem.fillExam(0, "Физика", 3); Artem.fillExam(0, "История", 4); Artem.fillExam(0, "Лин.Алгебра", 4); Artem.fillExam(0, "Мат.Анализ", 4); 
	Artem.fillExam(1, "Физика", 4); Artem.fillExam(1, "Философия", 3); Artem.fillExam(1, "Физкультура", 5); Artem.fillExam(1, "Англ.Язык", 4);
	Artem.fillExam(1, "Ознак.Практика", 3);
	tempStudents.addElem(Artem);

	char firstWord[30] = "Студент номер";
	char secondWord[30] = "Год рождения/поступления";
	char thirdWord[30] = "Данные учёбы";
	char fourthWord[30] = "Пол";
	char specialSymb[40] = "---------------------------------------";
	fprintf_s(file, "%s\n", specialSymb);
	for (int i = 0; i < tempStudents.getSize(); i++) {
		fprintf_s(file, "%s %d: %s %s %s\n%s: %d.%d.%d, %d\n%s: %s %s %s %s\n%s: %s\n", firstWord, (i + 1), \
			tempStudents[i].getSurname(), tempStudents[i].getName(), tempStudents[i].getPatronymic(), secondWord, \
			tempStudents[i].getBirthDay(), tempStudents[i].getBirthMonth(), tempStudents[i].getBirthYear(), \
			tempStudents[i].getYearStart(), thirdWord, tempStudents[i].getInstitute(), tempStudents[i].getDepartment(),
			tempStudents[i].getGroup(), tempStudents[i].getID(), fourthWord, tempStudents[i].getSex());

		int countOfExams = 0;
		for (int ses = 0; ses < 9; ses++) {
			for (int les = 0; les < 10; les++) {
				if (!tempStudents[i].getExam().lessons[ses][les].empty) {
					countOfExams++;
				}
			}
		}

		fprintf_s(file, "Число сданных экзаменов: %d\n", countOfExams);
		for (int s = 0; s < 9; s++) {
			for (int l = 0; l < 10; l++) {
				if (!tempStudents[i].getExam().lessons[s][l].empty) {
					fprintf_s(file, "Сессия %d, экзамен %d: %s %d\n", (s + 1), (l + 1), \
						tempStudents[i].getExam().lessons[s][l].nameLesson, tempStudents[i].getExam().lessons[s][l].grade);
				}
			}
		}
		fprintf_s(file, "%s\n", specialSymb);
	}
	fclose(file);
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	string compilanceCourseWork = "Выполнение курсовой работы...";
	for (int i = 0; i < compilanceCourseWork.length()+1; i++) {
		if (i < compilanceCourseWork.length()) {
			cout << compilanceCourseWork[i];
			Sleep(25);
		}
	}

	system("cls");
	FILE* file = NULL;
	WRITE(file);
	ClassMenu mainMenu;
	mainMenu.draw(file);



