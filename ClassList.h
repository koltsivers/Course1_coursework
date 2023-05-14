#pragma once
template<typename T>
class ClassList
{
    struct node {
        T data;
        node* next;
    };

    node* head;
    size_t sizeClassList = 0;

public:

    ClassList() {
        head = NULL;
        sizeClassList = 0;

    };
    ClassList(size_t) {};
    void addElem(T);
    void removeElem(size_t);
    void editElem(size_t, T);
    void insertElem(size_t, T);
    void clear();
    int findElem(T);
    int partition(int, int);
    void quickSort(int, int);
    void bubbleSort(ClassList<T>);

    T& operator[] (int);
    size_t getSize() {
        return sizeClassList;
    };
    ~ClassList();
};

template<typename T>
void ClassList<T>::addElem(T _newData)
{
    node* _newClassList = new node;
    _newClassList->data = _newData;
    if (sizeClassList == 0) {
        _newClassList->next = NULL;
    }
    else {
        _newClassList->next = head;
    }
    head = _newClassList;
    sizeClassList++;
}

template<typename T>
void ClassList<T>::removeElem(size_t _index) {
    if (_index >= 0 && _index < sizeClassList && sizeClassList > 0) {
        node* _current = head;
        node* _old;
        if (_index == 0) {
            _old = head;
            head = _current->next;
            delete _old;
            sizeClassList--;
        }
        else {
            size_t _i = 0;
            while (_current) {
                if (_i == _index - 1) {
                    _old = _current->next->next;
                    delete _current->next;
                    _current->next = _old;
                    sizeClassList--;
                    break;
                }
                _i++;
                _current = _current->next;
            }
        }
    }

}

template<typename T>

void ClassList<T>::editElem(size_t _index, T _editT) {
    if (_index >= 0 && _index < sizeClassList + 1 && sizeClassList > 0) {
        node* _current = new node();
        for (size_t _i = 0; _i < _index; _i++) {
            _current = head->next;
        }
        _current->data = _editT;

    }


}
template<typename T>
void ClassList<T>::insertElem(size_t _index, T _editT) {
    if (_index > 0 && _index < sizeClassList + 1 && sizeClassList > 0) {
        node* _current = new node();
        node* _newClassList = new node();
        _current = head;
        _newClassList->data = _editT;
        for (int _i = 0; _i < _index - 1; _i++) {
            _current = _current->next;
        }
        _newClassList->next = _current->next;
        _current->next = _newClassList;
        sizeClassList++;
    }

}
template<typename T>
int ClassList<T>::findElem(T _elem) {
    node* current = new node;
    size_t _index = 0;
    current = head;
    while (current) {
        if (current->data == _elem) {
            return _index;
        }
        current = current->next;
        _index++;
    }
    return -1;
}
template<typename T>
T& ClassList<T>::operator[](int index)
{

    if (index >= 0 and index < sizeClassList) {
        node* current = new node();
        current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        return current->data;
    }
    else if (sizeClassList + index > 0) {
        node* current = new node();
        current = head;
        for (int i = 0; i < sizeClassList + index; i++) {
            current = current->next;
        }
        return current->data;
    }

}
template <typename T>
void ClassList<T>::clear() {
    node* _current;
    _current = new node;
    for (int i = 0; i < sizeClassList; i++) {
        if (head == NULL)
            break;
        _current = head->next;
        delete head;
        head = _current;
    }
    delete _current;
    sizeClassList = 0;
    head = NULL;
}
template<typename T>
ClassList<T>::~ClassList() {
    node* _current;
    _current = new node;
    for (int i = 0; i < sizeClassList; i++) {
        if (head == NULL)
            break;
        _current = head->next;
        delete head;
        head = _current;
    }
    delete _current;
    sizeClassList = 0;
    head = NULL;
}

