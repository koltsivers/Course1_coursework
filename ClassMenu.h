#pragma once
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>


class ClassMenuEdit {
private:
	int key;
public:
	int getKey(int key) {
		this->key = key;
	}
	void checkKeyGetch(int _count) {
		//стрелка вверх
		int count = _count;
		if (key == 37) {
			for (int i = 0; i < count;i++) {

			}
		}
		//стрелка вправо
		if (key == 37) {

		}
		if (key == 13) {

		}
	}
};

class ClassMenu
{
private:
	std::string upTitle;
	std::string items[100];
public:

	ClassMenu(std::string upTitle) {
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
	void addItemMenu(std::string _item) {
		int count = getItemCount();
		items[count] = _item;
	}
	void deleteItemMenu(std::string _item) {
		int count = getItemCount();
		items[count] = "";
	}
	void drawMenu() {
		system("cls");
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout << upTitle << std::endl;
		int count = getItemCount();
		for (int i = 0; i < count; i++) {
			std::cout << i << "."  << items[i] << std::endl;
		}
	}
};
