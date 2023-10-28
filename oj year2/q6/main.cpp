
#include <cstdlib>
#include <iostream>

using namespace std;

class Node {
public:
  Node() {
    data = 0;
    next = NULL;
  }
  int data;
  struct Node *next;
};

class Set {
public:
  Set() { element = nullptr; }

  int addElement(int e) {
    Node *i = element;
    if (i == nullptr) {
      element = new Node;
      element->data = e;
      element->next = nullptr;
      return 1;
    }
    while (i->next != nullptr) {
      if (i->data == e)
        return 0;
      i = i->next;
    }
    if (i->data == e)//會漏判最後一個
      return 0;
    Node *newNode = new Node;
    //cout << "newNode position=" << newNode << endl;
    //cout << "i position=" << i << endl;
    i->next = newNode;
    newNode->data = e;
    newNode->next = nullptr;
    /*cout << "list:";
    for (Node *j = element; j != nullptr; j = j->next)
      cout << j->data << " ";
    cout << endl;*/
    return 1;
  }

  Set *unions(Set *b) {
    Set *c = new Set;
    Node *i = element;
    while (i != nullptr) {
      c->addElement(i->data);
      i = i->next;
    }
    i = b->element;
    while (i != nullptr) {
      c->addElement(i->data);
      i = i->next;
    }
    return c;
  }

  Set *intersetcions(Set *b) {
    Set *c = new Set;
    Node *i = element;
    while (i != nullptr) {
      if (b->contains(i->data))
        c->addElement(i->data);
      i = i->next;
    }
    return c;
  }

  bool contains(int a) {
    Node *i = element;
    while (i != nullptr) {
      if (i->data == a)
        return 1;
      i = i->next;
    }
    return 0;
  }

  bool equivalent(Set *b) {
    Node *i = element;
    while (i != nullptr) {
      if (!b->contains(i->data))
        return 0;
      i = i->next;
    }
    return 1;
  }

  void listAll() {
    Node *cur = element;
    while (cur != NULL) {
      cout << cur->data << " ";
      cur = cur->next;
    }
    cout << endl;
  }

private:
  Node *element;
};

int main() {
  Set *a = new Set();
  Set *b = new Set();
  Set *c;
  Node *cur;

  a->addElement(1);
  a->addElement(2);
  a->addElement(3);
  b->addElement(3);
  b->addElement(4);
  b->addElement(5);
  b->addElement(5);

  //a->listAll();
  //b->listAll();

  c = a->unions(b);
  c->listAll();

  c = a->intersetcions(b);
  c->listAll();

  if (a->equivalent(b) == 0)
    cout << "Not equivalent.\n";
  else
    cout << "Equivalent!\n";
}
