#pragma once
#include <windows.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
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
		else {
			cout << endl;
		}
	}




	system("pause");
	return 0;

};