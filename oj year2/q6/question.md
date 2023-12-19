# Description

請完成 addElement，unions，intersection，equivalent 這四個函數

addElement 會在集合中增加一個整數的元素，成功的時候回傳真，失敗的時候回傳假。

unions 會將 兩個集合做聯集的運算，然後將結果回傳。

intersection 會將 兩個集合做交集的運算，然後將結果回傳。

equivalent 會判斷兩個集合是否相等，如果相等就回傳真，不相等就回傳假。

Please finish four function addElement, unions, intersection and equivalent.

Function addElement will add an element to the set, return true on success and false on not.

Function unions union two set and return the result.

Function intersection intersect two set and return the result.

Function equivalent return true if two set have the same element, return false if not.
```cpp
#include<iostream>
#include<cstdlib>

using namespace std;

class Node
{
public:
	Node()
	{
		data = 0;
		next = NULL;
	}
	int data;
	struct Node *next;
};

class Set
{
public:
	Set()
	{
	}

	int addElement(int e)
	{
	}

	Set *unions(Set *b)
	{
	}

	Set *intersetcions(Set *b)
	{
	}

	bool equivalent(Set *b)
	{
	}
	
	void listAll()
	{
		Node *cur = element;
		while(cur != NULL)
		{
			cout<<cur->data<<" ";
			cur = cur->next;
		}
	}
private:
	Node *element;
};

int main()
{
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
	
	c = a->unions(b);
	c->listAll();
	
	c = a->intersetcions(b);
	c->listAll();
	
	if(a->equivalent(b) == 0)
		cout<<"Not equivalent.\n";
	else
		cout<<"Equivalent!\n";
}
```
