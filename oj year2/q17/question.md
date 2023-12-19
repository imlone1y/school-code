# Description
In computer science, a trie, also called digital tree or prefix tree, is a type of k-ary search tree, a tree data structure used for locating specific keys from within a set. These keys are most often strings, with links between nodes defined not by the entire key, but by individual characters.

Trie - Wikipedia

Please finish the constructor and member function in class Trie.

## Sample Input 1
```
insert to
insert tea
print
insert ten
print
insert inn
print
insert in
print
insert i
print
search inn
search innn
search t
exit
```

## Sample Output 1
```
[]
  t
    o
    ea
[]
  t
    o
    e
      a
      n
[]
  t
    o
    e
      a
      n
  inn
[]
  t
    o
    e
      a
      n
  in
    n
[]
  t
    o
    e
      a
      n
  i
    n
      n
exist
not exist
not exist
```


```cpp
#include <iostream>
#include <string>

using namespace std;

class Trie
{
public:
	/*
	construct a Trie.
	*/
	Trie();
	/*
	search trie for key, return true if exist, false if not.
	*/
	bool search(string key);
	/*
	insert value into trie.
	*/
	void insert(string value);
	/*
	display trie in pre-order, each element in a line, display space befoer element base on the level of 	the element. level 1 for 2 space, level 2 for 4 space, level 3 for 6 space and so on, root is level 	0.
	*/
	void preorder();
}

int main()
{
	Trie *trie = new Trie();
	string command, key, value;
	while(1)
	{
		cin>>command;
		if(command == "insert")
		{
			cin>>value;
			trie->insert(value);
		}
		else if(command == "search")
		{
			cin>>key;
			if(trie->search(key))
				cout << "exist" << endl;
			else
				cout << "not exist" << endl;
		}
		else if(command == "print")
		{
			trie->preorder();
		}
		else if(command == "exit")
		{
			break;
		}
	}
}
```
