# Description

請觀察 insert 函數並完成樣板中的 inorder, preorder, postorder 以及 levelorder 四個函數

Observe the function insert and finish four function in the template, inorder, preorder, postorder and levelorder.
```cpp
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Tree
{
public:
	Tree()
	{
		int j;
		for(j = 0;j < 2000;j ++)
			root[j] = -1;
	}
	int insert(int node)
	{
		int index = 0;
		while(index < 2000 && root[index] != -1)
		{
			if(root[index] < node)
				index = index * 2 + 2;
			else
				index = index * 2 + 1;
		}
		root[index] = node;
	}
	void inorder()
	{
	}
	void preorder()
	{
	}
	void postorder()
	{
	}
	void levelorder()
	{
	}
private:
	int root[2000];
};

int main()
{
	Tree *tree = new Tree();
	int j, node;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node = rand();
		tree->insert(node);
	}
	tree->inorder();
	printf("\n");
	tree->preorder();
	printf("\n");
	tree->postorder();
	printf("\n");
	tree->levelorder();
	printf("\n");
}
```
