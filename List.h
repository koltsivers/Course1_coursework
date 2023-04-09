#pragma once

template<typename T>
class clList {
	struct node {
		T data;
		node* next;
	};
	node* head;
	size_t sizeList = 0;

public: 
	List() {
		head = NULL;
		sizeList = 0;
	};
	List(size_t) {};
	void addItem(T);
	void removeElem

};