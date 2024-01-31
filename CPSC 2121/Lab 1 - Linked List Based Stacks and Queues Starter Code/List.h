/*
 * Name: Benjamin McDonnough
 * Date Submitted: 08/31/23
 * Lab Section: 006
 * Assignment Name: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
  start = nullptr;
  mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  Node<T>* temp = start;

  while(start != nullptr){
    temp = start;
    start = start-> next;

    delete temp;
    mySize--;
  }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  if(!(start == nullptr)){
    return false;
  }
  return true;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  if(empty()){
    start = new Node<T>(value);
  }
  else{
    Node<T>* temp = new Node<T>(value);

    temp->next = start;

    start = temp;
  }
  mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  if(empty()){
    start = new Node<T>(value);
  }
  else{
    Node<T>* iter = start;
  
    for(int i = 0; i < mySize-1; i++){
      iter = iter->next;
    }

    Node<T>* newNode = new Node<T>(value);
    newNode->next = nullptr;

    iter->next = newNode;
  }
  mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  if(empty()){
    start = new Node<T>(value);
  }
  else{
    Node<T>* iter = start;

    if(j == 0){
      insertStart(value);
      return;
    }
    else if(mySize < j){
      return;
    }
    else{
      for(int i = 0; i < j-1; i++){
        iter = iter->next;
      }
    }
    

    Node<T>* newNode = new Node<T>(value);
    newNode->next = iter->next;

    iter->next = newNode;
  }
  mySize++;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  if(empty()){
    return;
  }
  Node<T>* temp = start;

  start = start->next;
  delete temp;
  mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  if(empty()){
    return;
  }
  Node<T>* temp = start;

  for(int i = 0; i < mySize-1; i++){
    temp = temp->next;
  }

  delete temp;
  mySize--;  
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  if(empty()){
    return;
  }
  Node<T>* temp = start;
  Node<T>* temp2 = start;

  if(mySize < j){
    return;
  }

  for(int i = 0; i < j; i++){
    temp = temp->next;
  }

  for(int i = 0; i < j-1; i++){
    temp2 = temp2->next;
  }

  temp2->next = temp->next;

  delete temp;
  mySize--;
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  if(start == nullptr){
    return T();
  }

  return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  if(start == nullptr){
    return T();
  }

  Node<T>* iter = start;
  
  for(int i = 0; i < mySize - 1; i++){
    iter = iter->next;
  }

  return iter->value;
  
}
//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){

  if(start == nullptr){
    return T();
  }

  Node<T>* iter = start;
  for(int i = 0; i < j; i++){
    iter = iter->next;
  }

  return iter->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  Node<T>* iter = start;
  for(int i = 0; i < mySize-1; i++){
    if(iter->value == key){
      return i;
    }
    
    iter = iter->next;
  }

  return -1;
}
