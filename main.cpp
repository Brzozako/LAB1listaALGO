#include <iostream>
#include <time.h>
#include <string>
using namespace std;

template<typename T>
class List {
private:
    struct Node {
    public:
        T data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;
    int size;

public:
    List();
    ~List();

    void pushFront(T data);
    void pushBack(T data);
    void popFront();
    void popBack();
    void display();

};

template<typename T>
List<T>::List(){
    head=nullptr;
    tail=nullptr;
    size=0;
}

template<typename T>
List<T>::~List() {
    while(head!=nullptr){
        Node* tmp=head;
        head =head->next;
        delete tmp;
    }
}

template <typename T>
void List<T>::pushFront(T data) {
    Node* addNode=new Node{data, nullptr,head};
    if(head!= nullptr)
        head->prev=addNode;
    head=addNode;
    if(tail== nullptr)
        tail=addNode;
    size++;
}

template <typename T>
void List<T>::pushBack(T data) {
    Node* addNode=new Node{data, tail, nullptr};
    if(tail!= nullptr)
        tail->next=addNode;
    tail=addNode;
    if(head== nullptr)
        head=addNode;
    size++;
}

template <typename T>
void List<T>::popFront() {
    if(head!= nullptr) {
        Node* tmp=head;
        head=head->next;
        if (head!= nullptr)
            head->prev=nullptr;
        delete tmp;
        size--;
    }
}

template <typename T>
void List<T>::popBack() {
    if(tail!= nullptr) {
        Node* tmp=tail;
        tail=tail->next;
        if (tail!= nullptr)
            tail->prev=nullptr;
        delete tmp;
        size--;
    }
}

template <typename T>
void List<T>::display() {
    Node* current=head;
    while(current!= nullptr){
        cout<<current->data<<" ";
        current=current->next;
    } cout<<endl;
}

int main() {
    List<int> TWlistINT;

    TWlistINT.pushBack(1);
    TWlistINT.pushBack(2);
    TWlistINT.pushBack(3);
    TWlistINT.display();
    TWlistINT.popFront();
    TWlistINT.display();
    TWlistINT.popBack();
    TWlistINT.display();

    List<string> TWlistSTRING;
    TWlistSTRING.pushBack("Dzien");
    TWlistSTRING.pushBack("Dobry");
    TWlistSTRING.display();

    return 0;

}
