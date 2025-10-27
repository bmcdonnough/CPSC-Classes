#include "OurCPSC3120Tree.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
class OurCPSC3120Tree{
 public:
  OurCPSC3120Tree(void);
  OurCPSC3120Tree(OurCPSC3120Tree&);
  ~OurCPSC3120Tree(void);
  OurCPSC3120Tree* getParent(void);
  OurCPSC3120Tree* getLeft(void);
  OurCPSC3120Tree* getRight(void);
  int getValue(void);
  void setParent(OurCPSC3120Tree&);
  void setLeft(OurCPSC3120Tree&);
  void setRight(OurCPSC3120Tree&);
  void setValue(int);
  void insert(int);
  void printPreorder(void);
  void printInorder(void);
  void printPostorder(void);
  void rotateLeft(void);
  void rotateRight(void);
  void rotateLeftRight(void);
  void rotateRightLeft(void);
  void deleteNode(int);
    
 private:
  int value;
  OurCPSC3120Tree *parent;
  OurCPSC3120Tree *left;
  OurCPSC3120Tree *right;
  int getHeight();
  void balanceTree();
  void printInfo();
};
 */

OurCPSC3120Tree::OurCPSC3120Tree(){
  value = 0;
  parent = NULL;
  left = NULL;
  right = NULL;
}

OurCPSC3120Tree::OurCPSC3120Tree( OurCPSC3120Tree &t ){
  setParent( *t.getParent() );
  setLeft( *t.getLeft() );
  setRight( *t.getRight() );
  setValue( t.getValue() );
}

OurCPSC3120Tree::~OurCPSC3120Tree(){
}

int OurCPSC3120Tree::getValue(){
  return value;
}

OurCPSC3120Tree* OurCPSC3120Tree::getLeft(){
  return left;
}

OurCPSC3120Tree* OurCPSC3120Tree::getRight(){
  return right;
}

OurCPSC3120Tree* OurCPSC3120Tree::getParent(){
  return parent;
}

void OurCPSC3120Tree::setValue( int v ){
  value = v;
  return;
}

void OurCPSC3120Tree::setParent( OurCPSC3120Tree &newParent ){
  parent = &newParent;
}

void OurCPSC3120Tree::setLeft( OurCPSC3120Tree &newLeft ){
  left = &newLeft;
  return;
}

void OurCPSC3120Tree::setRight( OurCPSC3120Tree &newRight ){
  right = &newRight;
  return;
}

void OurCPSC3120Tree::printInfo(){
  cerr << this << endl;
  cerr << "---------------" << endl;
  cerr << "Value : " << getValue() << endl;
  cerr << "Parent: " << getParent() << endl;
  cerr << "Left  : " << getLeft() << endl;
  cerr << "Right : " << getRight() << endl;
  cerr << "Height: " << getHeight() << endl;
  cerr << "===============" << endl;
  if( getLeft() ){
    getLeft()->printInfo();
  }
  if( getRight() ){
    getRight()->printInfo();
  }
}

void OurCPSC3120Tree::printPreorder(){
  cout << getValue();
  if( getLeft() && getLeft()->getValue() ){
    cout << ",";
    getLeft()->printPreorder();
  }
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printPreorder();
  }

  return;
}

void OurCPSC3120Tree::printInorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printInorder();
    cout << ",";
  }
  cout << getValue();
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printInorder();
  }

  return;
}

void OurCPSC3120Tree::printPostorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printPostorder();
    cout << ",";
  }
  if( getRight() && getRight()->getValue() ){
    getRight()->printPostorder();
    cout << ",";
  }
  cout << getValue();
  return;
}

void OurCPSC3120Tree::insert( int val ){
  if( !getValue() ){
    setValue( val );
  }
  else if( val < getValue() && !getLeft() ){
    left = new OurCPSC3120Tree();
    getLeft()->setParent( *this );
    getLeft()->insert( val );
  }
  else if( val > getValue() && !getRight() ){
    right = new OurCPSC3120Tree();
    getRight()->setParent( *this );
    getRight()->insert( val );
  }
  else if( val < getValue() ){
    getLeft()->insert( val );
  }
  else{
    getRight()->insert( val );
  }

  balanceTree();
  
  return;
}

int OurCPSC3120Tree::getHeight(){
  if( !getValue() ){
    return 0;
  }
  if( !getLeft() && !getRight() ){
    return 1;
  }
  if( getLeft() && !getRight() ){
    return getLeft()->getHeight() + 1;
  }
  if( !getLeft() && getRight() ){
    return getRight()->getHeight() + 1;
  }
  
  return fmax( getLeft()->getHeight() , getRight()->getHeight() ) + 1;
}

void OurCPSC3120Tree::balanceTree(){
  if( !getRight() && getLeft() && !getLeft()->getLeft() && getLeft()->getHeight() >= 2 ){
    rotateLeftRight();
    return;
  }
  if( !getRight() && getLeft() && getLeft()->getLeft() && getLeft()->getRight() && getLeft()->getRight()->getHeight() > getLeft()->getLeft()->getHeight() ){
    rotateLeftRight();
    return;
  }
  if( !getLeft() && getRight() && !getRight()->getRight() && getRight()->getHeight() >= 2 ){
    rotateRightLeft();
    return;
  }
  if( !getLeft() && getRight() && getRight()->getRight() && getRight()->getLeft() && getRight()->getLeft()->getHeight() > getRight()->getRight()->getHeight() ){
    rotateRightLeft();
    return;
  }
  if( !getLeft() && getRight() && getRight()->getHeight() >= 2 ){
    rotateLeft();
    return;
  }
  if( getLeft() && getRight() && getRight()->getHeight() >= ( getLeft()->getHeight() + 2 ) ){
    rotateLeft();
    return;
  }
  if( !getRight() && getLeft() && getLeft()->getHeight() >= 2 ){
    rotateRight();
    return;
  }
  if( getRight() && getLeft() && getLeft()->getHeight() >= ( getRight()->getHeight() + 2 ) ){
    rotateRight();
    return;
  }
}

void OurCPSC3120Tree::rotateLeftRight(){
  getLeft()->rotateLeft();
  rotateRight();
  return;
}

void OurCPSC3120Tree::rotateRightLeft(){
  getRight()->rotateRight();
  rotateLeft();
  return;
}

void OurCPSC3120Tree::rotateLeft(){
  //Change the root of the tree
  OurCPSC3120Tree* newRoot = this->getRight();
  if(newRoot == nullptr){
    return;
  }
  int tempValue = value;
  value = newRoot->value;
  newRoot->value = tempValue;

  right = newRoot->right;
  if(getRight()){
    right->parent = this;
  }

  newRoot->right = newRoot->left;
  newRoot->left = left;
  if(getLeft()){
    left->parent = newRoot;
  }

  left = newRoot;
  newRoot->parent = this;
  return;
}

void OurCPSC3120Tree::rotateRight(){
  //Change the root of the tree
  OurCPSC3120Tree* newRoot = this->getLeft();
  if(newRoot == nullptr){
    return;
  }
  int tempValue = value;
  value = newRoot->value;
  newRoot->value = tempValue;

  left = newRoot->left;
  if(getLeft()){
    left->parent = this;
  }

  newRoot->left = newRoot->right;
  newRoot->right = right;
  if(getRight()){
    right->parent = newRoot;
  }

  right = newRoot;
  newRoot->parent = this;
  return;
}

void OurCPSC3120Tree::deleteNode( int val ){
  if (this == nullptr){
    return;
  }

  if (val < value && left != nullptr){
    left->deleteNode(val);
  }
  else if(val > value && right != nullptr){
    right->deleteNode(val);
  }
  else{
    //Leaf node (no children)
    if(left == nullptr && right == nullptr){
      if(parent != nullptr){
        if(parent->left == this){
          parent->left = nullptr;
        }
        else{
          parent->right = nullptr;
        }
      }
      delete this;
    }
    //One child
    else if(left == nullptr){
      OurCPSC3120Tree* tempNode = right;
      value = tempNode->value;
      left = tempNode->left;
      right = tempNode->right;
      if(left){
        left->parent = this;
      }
      if (right)
      {
        right->parent = this;
      }
      delete tempNode;
    }
    else if(right == nullptr){
      OurCPSC3120Tree* tempNode = left;
      value = tempNode->value;
      left = tempNode->left;
      right = tempNode->right;
      if(left){
        left->parent = this;
      }
      if (right)
      {
        right->parent = this;
      }
      delete tempNode;
    }
    //Two children
    else{
      OurCPSC3120Tree* heir = right;
      while(heir->left != nullptr){
        heir = heir->left;
      }
      value = heir->value;
      right->deleteNode(val);
    }
  }
  return;
}