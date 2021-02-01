#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <ostream>
#include <algorithm>

template<class T>
class DLLNode {
public:
    DLLNode() {
        next = prev = NULL;
    }
    DLLNode(const T& el, DLLNode<T> *n = NULL, DLLNode<T> *p = NULL) {
        info = el; next = n; prev = p;
    }
    T info;
    DLLNode<T> *next, *prev;
};

template<class T>
class DoublyLinkedList {
public:
    DoublyLinkedList() {
        head = tail = NULL;
    }
    ~DoublyLinkedList() {
        clear();
    }
    void addToDLLHead(const T&);
    void addToDLLTail(const T&);
    T deleteFromDLLHead();
    T deleteFromDLLTail();
    bool isEmpty() const {
        return head == NULL;
    }
    void clear();
    std::string getNumAsString();

    void operator=(const DoublyLinkedList<T>&);
protected:
    DLLNode<T> *head, *tail;
    friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& dll) {
        if (dll.head != NULL) {
            for (DLLNode<T> *tmp = dll.head; tmp != NULL; tmp = tmp->next)
                out << tmp->info;
        }
        else {
            out << "0";
        }
        return out;
    }
};

template<class T>
void DoublyLinkedList<T>::addToDLLHead(const T& el) {
    if (head != NULL) {
        head = new DLLNode<T>(el,head,NULL);
        head->next->prev = head;
    }
    else head = tail = new DLLNode<T>(el);
}

template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el) {
    if (tail != NULL) {
        tail = new DLLNode<T>(el,NULL,tail);
        tail->prev->next = tail;
    }
    else head = tail = new DLLNode<T>(el);
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLHead() {
    T el = head->info;
    if (head == tail) { // if only one DLLNode on the list;
        delete head;
        head = tail = NULL;
    }
    else {              // if more than one DLLNode in the list;
        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
    return el;
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail() {
    T el = tail->info;
    if (head == tail) { // if only one DLLNode on the list;
        delete head;
        head = tail = NULL;
    }
    else {              // if more than one DLLNode in the list;
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }
    return el;
}

template<class T>
void DoublyLinkedList<T>::clear() {
    while (head != NULL) {
        deleteFromDLLHead();
    }
}

template<class T>
std::string DoublyLinkedList<T>::getNumAsString()
{
    std::string a;
    for (DLLNode<T> *tmp = head; tmp != NULL; tmp = tmp->next)
        a.push_back(tmp->info + '0');
    return a;
}

template<class T>
void DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &B)
{
    if (this != &B)
    {
        clear();

        for (DLLNode<T> * tmp = B.head; tmp != NULL; tmp = tmp->next)
            this->addToDLLTail(tmp->info);
    }
}

#endif
