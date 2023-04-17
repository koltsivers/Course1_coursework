#pragma once
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;


//class ClassMenuEdit {
//private:
//	int key;
//public:
//	int getKey(int key) {
//		this->key = key;
//	}
//	void checkKeyGetch(int _count) {
//		//стрелка вверх
//		int count = _count;
//		if (key == 37) {
//			for (int i = 0; i < count;i++) {
//
//			}
//		}
//		//стрелка вправо
//		if (key == 37) {
//
//		}
//		if (key == 13) {
//
//		}
//	}
//};

class ClassMenu
{
private:
	string upTitle;
	string items[100];
public:
	ClassMenu() {
		upTitle = "Заголовок";
	}
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
	void deleteItemMenu(std::string _item) {
		int count = getItemCount();
		items[count] = "";
	}
	void drawMenu() {
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << upTitle << endl;
		int count = getItemCount();
		for (int i = 0; i < count; i++) {
			cout << i << "."  << items[i] << endl;
		}
	}
};

class StudentMenu : public ClassMenu {
private:
	string upStTitle = "";
	string stItems[100];
public:
	StudentMenu(string upStTitle) {
		this->upStTitle = upStTitle;
	}
};
