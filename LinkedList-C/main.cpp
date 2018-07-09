// Copyright © Jin Lim. All rights reserved.
#include <iostream>
#include <assert.h>
using namespace std;

struct node {
    int data;
    node *next;
};

class LinkedList {
    node *head;
    node *tail;
    
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    };
    void createNode(int value);
    void insertNodeAtStart(int value);
    void insertNodeAtEnd(int value);
    void insertNodeAtPosition(int position, int value);
    void deleteNodeAtPosition(int position);
    void deleteNodeAtStart();
    void deleteNodeAtEnd();
    void display();
};

void LinkedList::createNode(int value){
    assert (head == NULL && "List is not empty");
    node *temp = new node;
    temp->data = value;
    temp->next = nullptr;
    
    head = temp;
    tail = temp;
    // delete temp; --> I wanted to free memory. but I can't. It will make list unworkable.
    temp = nullptr;
};

void LinkedList::insertNodeAtStart(int value){
    node *temp = new node;
    temp->data = value;
    
    temp->next = head;
    head = temp;
    // delete temp; --> I wanted to free memory. but I can't. It will make list unworkable.
    temp = nullptr;
};

void LinkedList::insertNodeAtEnd(int value){
    node *temp = new node;
    temp->data = value;
    temp->next = nullptr;
    
    tail->next = temp;
    tail = tail->next;
    
    // delete temp; --> I wanted to free memory. but I can't. It will make list unworkable.
    temp = nullptr;
};

void LinkedList::insertNodeAtPosition(int position, int value){
    node *count = new node;
    count = head;
    for (int i = 1; i < position-1; ++i){
        count = count->next;
    }
    
    node *temp = new node;
    temp->data = value;
    
    temp->next = count->next;
    count->next = temp;
    
    delete temp;
    temp = nullptr;
};

void LinkedList::deleteNodeAtPosition(int position){
    node *count = new node;
    node *backward = new node;
    count = head;
    for (int i = 1; i < position; ++i){
        backward = count;
        count = count->next;
    }
    
    backward->next = count->next;
    delete count;
    count = nullptr;
};

void LinkedList::deleteNodeAtStart(){
    node *temp = new node;
    temp = head;
    delete temp;
    
    head = head->next;
    temp = nullptr;
}

void LinkedList::deleteNodeAtEnd(){
    node *temp = new node;
    node *lastBefore = new node;
    temp = head;
    
    while(temp->next != NULL){
        lastBefore = temp;
        temp = temp->next;
    }
    
    tail = lastBefore;
    tail->next = nullptr;
    
    delete lastBefore;
    lastBefore = nullptr;
    // delete temp;
    temp = nullptr;
};

void LinkedList::display(){
    node *displayNode = new node;
    displayNode = head;
    while(displayNode != nullptr){
        cout << displayNode->data << endl;
        displayNode = displayNode->next;
    }
};

int main(){
    LinkedList *list1 = new LinkedList();
    list1->createNode(4);
    list1->insertNodeAtEnd(6);
    list1->insertNodeAtEnd(7);
    list1->insertNodeAtEnd(8);
    list1->insertNodeAtEnd(8);
    list1->insertNodeAtEnd(8);
    list1->insertNodeAtStart(3);
    list1->insertNodeAtStart(2);
    list1->insertNodeAtPosition(4, 5);
    list1->deleteNodeAtPosition(4);
    list1->deleteNodeAtPosition(2);
    list1->deleteNodeAtStart();
    list1->deleteNodeAtStart();
    list1->deleteNodeAtEnd();
    list1->deleteNodeAtEnd();
    
    list1->display();
    return 0;
};
