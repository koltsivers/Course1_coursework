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

	if (remove("file.txt") != 0) {
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


	if (remove("file.txt.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}

}
void WRITE(FILE* file) {
	fopen_s(&file, "file.txt", "w");
	ClassList <ClassStudent> tempStudents;
	ClassStudent Alex("Алекс", "Жик", "Миха123456", 127, 82, 2004, 2022, "IKB2", "KB-04", "БАСО-07-22", "22Б9123", 1);
	Alex.fillExam(0, "Программирование", 5);
	Alex.fillExam(0, "Психология", 4);
	Alex.fillExam(0, "Информатика", 5);
	Alex.fillExam(1, "История", 5);
	tempStudents.addElem(Alex);
	cout << Alex.getName();
	for (int i = 0; i < tempStudents.getSize(); i++) {
		/*fprintf_s(file, "%s %s %s %d %d %d %d %s %s %s %s b \n", \
			tempStudents[i].getSurname(), tempStudents[i].getName(), tempStudents[i].getPatronymic(), \
			tempStudents[i].getBirthDay(), tempStudents[i].getBirthMonth(), tempStudents[i].getBirthYear(), \
			tempStudents[i].getYearStart(), tempStudents[i].getInstitute(), tempStudents[i].getDepartment(),
			tempStudents[i].getGroup(), tempStudents[i].getID(), tempStudents[i].getSex());*/
		cout << tempStudents[i].getName();
		fprintf_s(file, "%s \n", tempStudents[i].getName());
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
			//SetConsoleTextAttribute(hOUTPUT, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << compilanceCourseWork[i];
			Sleep(25);
		}
	}

	system("cls");

	FILE* file = NULL;
	WRITE(file);
	//ClassMenu mainMenu;
	//mainMenu.draw(file);

};
