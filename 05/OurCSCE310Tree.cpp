#include "OurCSCE310Tree.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
class OurCSCE310Tree{
 public:
  OurCSCE310Tree(void);
  OurCSCE310Tree(OurCSCE310Tree&);
  ~OurCSCE310Tree(void);
  void operator=(OurCSCE310Tree&);
  OurCSCE310Tree* getParent(void);
  OurCSCE310Tree* getLeft(void);
  OurCSCE310Tree* getRight(void);
  int getValue(void);
  void setParent(OurCSCE310Tree*);
  void setLeft(OurCSCE310Tree*);
  void setRight(OurCSCE310Tree*);
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
  int getHeight();
  
 private:
  int value;
  OurCSCE310Tree* parent;
  OurCSCE310Tree* left;
  OurCSCE310Tree* right;
};
 */

OurCSCE310Tree::OurCSCE310Tree(){
  value = 0;
  parent = NULL;
  left = NULL;
  right = NULL;
}

OurCSCE310Tree::OurCSCE310Tree( OurCSCE310Tree& other){
  delete parent;
  delete left;
  delete right;
  value = other.getValue();
  parent = other.getParent();
  left = other.getLeft();
  right = other.getRight();
}

void OurCSCE310Tree::operator=( OurCSCE310Tree& other){
  delete parent;
  delete left;
  delete right;
  value = other.getValue();
  parent = other.getParent();
  left = other.getLeft();
  right = other.getRight();
}

OurCSCE310Tree::~OurCSCE310Tree(){
  delete left;
  left = NULL;
  delete right;
  right = NULL;
  value = 0;
}

OurCSCE310Tree* OurCSCE310Tree::getParent(){
  return parent;
}

OurCSCE310Tree* OurCSCE310Tree::getLeft(){
  return left;
}

OurCSCE310Tree* OurCSCE310Tree::getRight(){
  return right;
}

int OurCSCE310Tree::getValue(){
  return value;
}

void OurCSCE310Tree::setParent( OurCSCE310Tree* par ){
  parent = par;
}

void OurCSCE310Tree::setLeft( OurCSCE310Tree* lft ){
  left = lft;
}

void OurCSCE310Tree::setRight( OurCSCE310Tree* rght ){
  right = rght;
}

void OurCSCE310Tree::setValue( int val ){
  value = val;
}

void OurCSCE310Tree::insert( int val ){
  if( !getValue() ){
    setValue( val );
  }
  else if( ( val < getValue() && !getLeft() ) || ( val < getValue() && !getLeft()->getValue() ) ){
    left = new OurCSCE310Tree();
    left->setParent( this );
    left->setValue( val );
  }
  else if( ( val > getValue() && !getRight() ) || ( val > getValue() && !getRight()->getValue() ) ){
    right = new OurCSCE310Tree();
    right->setParent( this );
    right->setValue( val );
  }
  else if( val < getValue() ){
    getLeft()->insert( val );
  }
  else{
    getRight()->insert( val );
  }

  if( getLeft() && getLeft()->getRight() && !getRight() || getLeft() && getLeft()->getRight() && getRight() && getLeft()->getHeight() > getRight()->getHeight() + 1 && getLeft()->getRight()->getHeight() > getLeft()->getLeft()->getHeight() + 1 ){
    rotateLeftRight();
  }
  else if( getRight() && getRight()->getLeft() && !getLeft() || getRight() && getRight()->getLeft() && getLeft() && getRight()->getHeight() > getLeft()->getHeight() + 1 && getRight()->getLeft()->getHeight() > getRight()->getRight()->getHeight() + 1 ){
    rotateRightLeft();
  }
  else if( getLeft() && !getRight() && getLeft()->getHeight() > 1 || getLeft() && getRight() && getLeft()->getHeight() > getRight()->getHeight() + 1 ){
    rotateRight();
  }
  else if( getRight() && !getLeft() && getRight()->getHeight() > 1 || getRight() && getLeft() && getRight()->getHeight() > getLeft()->getHeight() + 1 ){
    rotateLeft();
  }
}

void OurCSCE310Tree::printPreorder(){
  if( getValue() ){
    cout << getValue();
  }
  if( getLeft() && getLeft()->getValue() ){
    cout << ",";
    getLeft()->printPreorder();
  }
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printPreorder();
  }
}

void OurCSCE310Tree::printInorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printInorder();
    cout << ",";
  }
  if( getValue() ){
    cout << getValue();
  }
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printInorder();
  }
}

void OurCSCE310Tree::printPostorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printPostorder();
    cout << ",";
  }
  if( getRight() && getRight()->getValue() ){
    getRight()->printPostorder();
    cout << ",";
  }
  if( getValue() ){
    cout << getValue();
  }
}

int OurCSCE310Tree::getHeight(){
  if( getLeft() && getLeft()->getValue() && ( !getRight() || !getRight()->getValue() ) ){
    return getLeft()->getHeight() + 1;
  }
  else if( getRight() && getRight()->getValue() && ( !getLeft() || !getLeft()->getValue() ) ){
    return getRight()->getHeight() + 1;
  }
  else if( getRight() && getLeft() && getRight()->getValue() && getLeft()->getValue() ){
    return fmax( getRight()->getHeight() , getLeft()->getHeight() ) + 1;
  }
  else if( getValue() && ( !getLeft() || !getLeft()->getValue() ) && ( !getRight() || !getRight()->getValue() ) ){
    return 1;
  }
  return 0;
}

void OurCSCE310Tree::rotateLeftRight(){
  getLeft()->rotateLeft();
  rotateRight();
}

void OurCSCE310Tree::rotateRightLeft(){
  getRight()->rotateRight();
  rotateLeft();
}

void OurCSCE310Tree::rotateLeft(){

  int tempRight = this->getRight()->getValue();
  OurCSCE310Tree* rightNode = this->getRight();
  OurCSCE310Tree* leftNode = this->getLeft();

  this->getRight()->setValue(this->getValue());
  this->setValue(tempRight);

  this->setRight(this->getRight()->getRight());

  this->setLeft(rightNode);
  this->getLeft()->setRight(rightNode->getLeft());
  this->getLeft()->setLeft(leftNode);

}

void OurCSCE310Tree::rotateRight(){

  int tempLeft = this->getLeft()->getValue();
  OurCSCE310Tree* leftNode = this->getLeft();
  OurCSCE310Tree* rightNode = this->getRight();

  this->getLeft()->setValue(this->getValue());
  this->setValue(tempLeft);

  this->setLeft(this->getLeft()->getLeft());

  this->setRight(leftNode);
  this->getRight()->setLeft(leftNode->getRight());
  this->getRight()->setRight(rightNode);
  
}

void OurCSCE310Tree::deleteNode( int key ){

  //delete root
  OurCSCE310Tree* node = this;
  if (node->getValue() == key) {
    while (node->getLeft() != NULL) {
      node = node->getLeft();
    }
    this->setValue(node->getValue());
  }

}
