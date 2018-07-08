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
    void display();
};

void LinkedList::createNode(int value){
    assert (head == NULL && "List is not empty");
    node *temp = new node;
    temp->data = value;
    temp->next = nullptr;
    
    head = temp;
    tail = temp;
    // delete temp;
    temp = nullptr;
};

void LinkedList::insertNodeAtStart(int value){
    node *temp = new node;
    temp->data = value;
    
    temp->next = head;
    head = temp;
    // delete temp;
    temp = nullptr;
};

void LinkedList::insertNodeAtEnd(int value){
    node *temp = new node;
    temp->data = value;
    temp->next = nullptr;
    
    tail->next = temp;
    tail = tail->next;
    
    // delete temp;
    temp = nullptr;
};

void LinkedList::display(){
    node *displayNode = new node;
    displayNode = head;
    while(displayNode != nullptr)
    {
        cout<<displayNode->data<<"\t";
        displayNode=displayNode->next;
    }
};


int main(){
    LinkedList *list1 = new LinkedList();
    list1->createNode(4);
    list1->insertNodeAtEnd(5);
    list1->insertNodeAtEnd(6);
    list1->insertNodeAtEnd(7);
    list1->insertNodeAtEnd(8);
    list1->insertNodeAtStart(3);
    
    list1->display();
};
