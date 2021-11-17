#ifndef OURCSCE310TREE_H
#define OURCSCE310TREE_H
using namespace std;

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

#endif
