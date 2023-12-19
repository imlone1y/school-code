# Description

Please finish the class "Red_Black_Tree" and main function to fulfill the requirements.

You can add any function or variable if you want.

Ref:https://www.cs.usfca.edu/

You must use your own data structure and are not allowed to use any build in STL library or you will get up to 0 points.


## Input
> In each test case, your tree should start from an empty tree.

> Each line will contain an operation of the tree till the end-of-file.

> There are two types of operations:

>> 1. insert <data>

>> insert data into your tree

>> 2. delete <data>

>> delete data from your tree


## Output
> The serialized string of the tree.
> Ending with a "\n" of each line.

## Sample Input 1
> insert 20

> insert 40

> insert 60

> insert 80

> insert 50

> delete 61

> delete 60


template <typename ValueType>
class RedBlackTree {
protected:
	enum State { Red, Black };
    struct RedBlackNode {
    	T data;
        State state;
        RedBlackNode *left, *right;
        size_t height() const;
 		size_t size() const; 
    };
    
public: // constructors, destructors
    RedBlackTree();
    RedBlackTree(const RedBlackTree & srcTree);
    ~RedBlackTree();

public: // methods
    void insert(const ValueType &val);
    void remove(const ValueType &val);
    bool exists(const ValueType &val) const;
    size_t height() const;
    size_t size() const;
    std::vector<ValueType> inOrder() const;
    std::vector<ValueType> levelOrder() const;

protected:
    RedBlackNode *root;
};

template <typename T>
void sortByBST(vector<T> &arr) {
    RedBlackTree<T> tree;
    for (auto data: arr)
        tree.insert(data);
    arr = tree.inOrder();
}


