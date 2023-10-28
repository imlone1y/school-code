#include <cstdlib>
#include <ctime>
#include <iostream>

#define SIZE 100

using namespace std;

class Node {
public:
  Node() {
    next = NULL;
    pre = NULL;
  }
  Node(int n) {
    data = n;
    next = NULL;
    pre = NULL;
  }
  int getData() { return data; }
  Node *getNext() { return next; }
  Node *getPre() { return pre; }
  void setData(int d) { data = d; }
  void setNext(Node *n) { next = n; }
  void setPre(Node *p) { pre = p; }

private:
  int data;
  Node *next, *pre;
};

class List {
public:
  List() { list = NULL; }
  List(int n) { generate(n); }

  void generate(int n) {
    len = n;
    int j;
    list = NULL;
    for (j = 0; j < n; j++)
      generate();
  }

  void generate() {
    Node *buf = new Node(rand() % 100);
    buf->setNext(list);
    if (list != NULL)
      list->setPre(buf);
    list = buf;
  }

  void bubbleSort() {
    for (int a = 0; a < len; a++) {
      Node *i = list;
      for (int b = 0; b < len - a - 1; b++, i = i->getNext()) {
        if (i->getData() > i->getNext()->getData()) {
          int temp = i->getData();
          i->setData(i->getNext()->getData());
          i->getNext()->setData(temp);
        }
      }
    }
  }

  void selectionSort() {
    Node *sort = list;
    for (int a = 0; a < len - 1; a++, sort = sort->getNext()) {
      Node *i = sort;
      Node *j = sort;
      int min = i->getData();
      for (int b = a; b < len; b++, i = i->getNext()) {
        if (i->getData() < min) {
          j = i;
          min = i->getData();
        }
      }
      int temp = j->getData();
      j->setData(sort->getData());
      sort->setData(temp);
    }
  }

  void insertionSort() {
    Node *sort = list;
    sort->setPre(nullptr);
    sort = sort->getNext();
    for (int a = 1; a < len; a++, sort = sort->getNext()) {
      Node *i = sort;
      while (i->getData() < i->getPre()->getData() && i->getPre() != nullptr) {
        int temp = i->getPre()->getData();
        i->getPre()->setData(i->getData());
        i->setData(temp);
        if (i->getPre()->getPre() != nullptr)
          i = i->getPre();
      }
    }
  }
  void print() {
    Node *cur = list;
    while (cur != NULL) {
      cout << cur->getData() << " ";
      cur = cur->getNext();
    }
    cout << endl;
  }

private:
  Node *list;
  int len;
};

int main() {
  srand(time(NULL));
  List *l = new List(10);
  l->print();
  l->bubbleSort();
  l->print();

  l = new List(10);
  l->print();
  l->insertionSort();
  l->print();

  l = new List(10);
  l->print();
  l->selectionSort();
  l->print();
}
