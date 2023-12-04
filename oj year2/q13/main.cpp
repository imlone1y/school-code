#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <stdexcept>

using namespace std;

template <class T> class Node
{
public:
    Node()
    {
        data = new T;
    }
    Node(T d)
    {
        data = new T;
        (*data) = d;
    }
    Node &operator=(T d)
    {
        (*data) = d;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, Node n)
    {
        out << *(n.data);
        return out;
    }
    friend std::ostream &operator<<(std::ostream &out, Node *n)
    {
        out << *(n->data);
        return out;
    }
    void setData(T d)
    {
        *data = d;
    }
    T &getData() const
    {
        return *data;
    }

protected:
    T *data;
};

template <class T> class ListNode : public Node<T>
{
public:
    ListNode() : Node<T>()
    {
        prev = NULL;
        next = NULL;
    }
    ListNode(T d) : Node<T>(d)
    {
        prev = NULL;
        next = NULL;
    }
    ListNode(ListNode *p, ListNode *n) : Node<T>()
    {
        prev = p;
        next = n;
    }
    ListNode(T d, ListNode *p, ListNode *n) : Node<T>(d)
    {
        prev = p;
        next = n;
    }
    ListNode *getNext() const
    {
        return next;
    }
    ListNode *getPrev() const
    {
        return prev;
    }
    void setNext(ListNode *n)
    {
        next = n;
    }
    void setPrev(ListNode *p)
    {
        prev = p;
    }
    ListNode &operator=(T d)
    {
        this->setData(d);
        return *this;
    }

private:
    ListNode *prev, *next;
};

template <class T> class LinkList
{
public:
    LinkList()
    {
        head = NULL;
        tail = NULL;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void addFromHead(T d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (head != NULL)
        {
            head->setPrev(node);
        }
        node->setNext(head);
        head = node;
        if (tail == NULL)
            tail = node;
    }
    void addFromTail(T d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (tail != NULL)
        {
            tail->setNext(node);
        }
        node->setPrev(tail);
        tail = node;
        if (head == NULL)
            head = node;
    }
    void addAfter(ListNode<T> *at, T d)
    {
        if (!exist(at))
            return;
        ListNode<T> *node = new ListNode<T>(d);
        if (at->getNext() != NULL)
            at->getNext()->setPrev(node);
        node->setNext(at->getNext());
        at->setNext(node);
        node->setPrev(at);
        if (node->getNext() == NULL)
            tail = node;
    }
    ListNode<T> *removeFromHead()
    {
        ListNode<T> *n = head;
        if (head != NULL)
        {
            head = head->getNext();
            if (head != NULL)
                head->setPrev(NULL);
            else
                tail = NULL;
            n->setNext(NULL);
        }
        return n;
    }
    ListNode<T> *removeFromTail()
    {
        ListNode<T> *n = tail;
        if (tail != NULL)
        {
            tail = tail->getPrev();
            if (tail != NULL)
                tail->setNext(NULL);
            else
                head = NULL;
            n->setPrev(NULL);
        }
        return n;
    }
    ListNode<T> *remove(ListNode<T> *n)
    {
        if (!exist(n))
            return NULL;
        if (n == head)
            return removeFromHead();
        if (n == tail)
            return removeFromTail();
        n->getPrev()->setNext(n->getNext());
        n->getNext()->setPrev(n->getPrev());
        n->setNext(NULL);
        n->setPrev(NULL);
        return n;
    }
    ListNode<T> *exist(T d)
    {
        ListNode<T> *j = head;
        while (j != NULL)
        {
            if (j->getData() == d)
                return j;
            j = j->getNext();
        }
        return NULL;
    }
    bool exist(ListNode<T> *n)
    {
        ListNode<T> *j = head;
        while (j != NULL)
        {
            if (j == n)
                return true;
            j = j->getNext();
        }
        return false;
    }
    ListNode<T> &operator[](int i)
    {
        ListNode<T> *j = head;
        int k;
        for (k = 0; k < i && j != NULL; k++)
            j = j->getNext();
        if (j == NULL)
            throw std::invalid_argument("index does not exist.");
        return *j;
    }
    int count() const
    {
        int count = 0;
        ListNode<T> *current = head;
        while (current != nullptr)
        {
            count++;
            current = current->getNext();
        }
        return count;
    }
    void print() const
    {
        ListNode<T> *j;
        j = head;
        while (j != NULL)
        {
            std::cout << (*j) << " ";
            j = j->getNext();
        }
        std::cout << std::endl;
    }
    ListNode<T> *getHead()
    {
        return head;
    }

protected:
    ListNode<T> *head, *tail;
};

/*
  Please finish the TreeNode class, TreeNode class respresent a node in a
  general tree. A general tree is different from binary tree, every node in
  binary tree have at most two child node, but a node in general tree may have
  more than two child node.
*/
template <class T> class TreeNode : public Node<T>
{
public:
    TreeNode() : Node<T>()
    {
        child = new LinkList<TreeNode<T> *>();
    }
    TreeNode(T d) : Node<T>(d)
    {
        child = new LinkList<TreeNode<T> *>();
    }
    /*
      Add a child to this node.
    */
    void addChild(TreeNode *n)
    {
        child->addFromTail(n);
    }
    /*
      Add a child to this node.
    */
    void addChild(T d)
    {
        TreeNode<T> *childNode = new TreeNode<T>(d);
        child->addFromTail(childNode);
    }
    /*
      Return the nth child of the node.
    */
    TreeNode<T> *operator[](int n)
    {
        return (*child)[n];
    }
    LinkList<TreeNode<T> *> getChild()
    {
        return *child;
    }
    TreeNode<T> *getChild(int index)
    {
        if (index < 0 || index >= child->count())
        {
            throw std::invalid_argument("Invalid child index.");
        }
        ListNode<TreeNode<T> *> *currentChild = child->getHead();
        for (int i = 0; i < index; i++)
        {
            currentChild = currentChild->getNext();
        }
        return currentChild->getData();
    }
    int getChildCount()
    {
        return child->count();
    }

private:
    LinkList<TreeNode<T> *> *child;
};

/*
  Please finish the Tree class. Tree class respresent a general tree, that means
  node on this tree may have more than two child node.

*/
template <class T> class Tree
{
public:
    Tree()
    {
        root = NULL;
    }
    /*
      return the nth node on this tree with level order.
    */
    TreeNode<T> *operator[](int n)
    {
        if (root == NULL)
            return NULL;

        LinkList<TreeNode<T> *> queue;

        queue.addFromTail(root);

        int count = 0;
        while (!queue.isEmpty())
        {
            TreeNode<T> *current = queue.removeFromHead()->getData();

            if (count == n)
                return current;

            for (int i = 0; i < current->getChildCount(); ++i)
            {
                if (current->getChild(i) != NULL)
                    queue.addFromTail(current->getChild(i));
            }

            ++count;
        }

        return NULL;
    }
    /*
      return the number of nodes on this tree.
    */
    int count()
    {
        return countNodes(root);
    }
    /*
      print all the node on this tree with level order.
    */
    void levelOrder()
    {
        if (root == NULL)
            return;

        LinkList<TreeNode<T> *> queue;
        queue.addFromTail(root);

        while (!queue.isEmpty())
        {
            ListNode<TreeNode<T> *> *node = queue.removeFromHead();
            TreeNode<T> *current = node->getData();
            std::cout << *current << " ";

            for (int i = 0; i < current->getChildCount(); ++i)
            {
                if (current->getChild(i) != NULL)
                    queue.addFromTail(current->getChild(i));
            }
        }

        std::cout << std::endl;
    }
    /*
      print all the node on this tree with preorder.
    */
    void preorder()
    {
        _preorder(root);
        std::cout << std::endl;
    }
    /*
      print all the node on this tree with postorder.
    */
    void postorder()
    {
        _postorder(root);
        std::cout << std::endl;
    }
    /*
      set the root of this tree.
    */
    void setRoot(T d)
    {
        root = new TreeNode<T>(d);
    }

    TreeNode<T> *getRoot()
    {
        return root;
    }

private:
    TreeNode<T> *root;

    int countNodes(TreeNode<T> *node)
    {
        if (node == NULL)
            return 0;

        int count = 1;
        for (int i = 0; i < node->getChildCount(); ++i)
        {
            count += countNodes(node->getChild(i));
        }

        return count;
    }

    void _preorder(TreeNode<T> *node)
    {
        if (node == NULL)
            return;

        std::cout << *node << " ";
        for (int i = 0; i < node->getChildCount(); ++i)
        {
            _preorder(node->getChild(i));
        }
    }

    void _postorder(TreeNode<T> *node)
    {
        if (node == NULL)
            return;

        for (int i = 0; i < node->getChildCount(); ++i)
        {
            _postorder(node->getChild(i));
        }

        std::cout << *node << " ";
    }
};

template <class T> class BinaryTreeNode : public Node<T>
{
public:
    BinaryTreeNode() : Node<T>()
    {
        left = NULL;
        right = NULL;
    }
    BinaryTreeNode(T d) : Node<T>(d)
    {
        left = NULL;
        right = NULL;
    }
    BinaryTreeNode(BinaryTreeNode<T> *l, BinaryTreeNode<T> *r) : Node<T>()
    {
        left = l;
        right = r;
    }
    BinaryTreeNode(T d, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r) : Node<T>(d)
    {
        left = l;
        right = r;
    }
    void setLeft(BinaryTreeNode<T> *l)
    {
        left = l;
    }
    void setRight(BinaryTreeNode<T> *r)
    {
        right = r;
    }
    BinaryTreeNode<T> *&getLeft()
    {
        return left;
    }
    BinaryTreeNode<T> *&getRight()
    {
        return right;
    }
    bool operator>(BinaryTreeNode<T> n)
    {
        if (*(this->data) > *(n.data))
            return true;
        return false;
    }
    bool operator==(BinaryTreeNode<T> n)
    {
        if (*(this->data) == *(n.data))
            return true;
        return false;
    }

private:
    BinaryTreeNode<T> *left, *right;
};

template <class T> class BinaryTree
{
public:
    BinaryTree()
    {
        root = NULL;
        count = 0;
    }
    /*
      Convert a general tree to sibling tree
    */
    static BinaryTree<T> *convertFromGeneralTree(Tree<T> *tree)
    {
        BinaryTree<T> *binaryTree = new BinaryTree<T>();
        convertFromGeneralTreeHelper(tree->getRoot(), binaryTree, nullptr);
        return binaryTree;
    }
    BinaryTreeNode<T> *getRoot()
    {
        return root;
    }
    void print()
    {
        _print(root, 0);
    }

    void setRoot(BinaryTreeNode<T> *node)
    {
        if (root == nullptr)
        {
            root = node;
        }
    }

protected:
    BinaryTreeNode<T> *root;
    int count;

private:
    void _print(BinaryTreeNode<T> *r, int n)
    {
        if (r == NULL)
            return;
        int j;
        _print(r->getRight(), n + 1);
        for (j = 0; j < n; j++)
            std::cout << "    ";
        std::cout << r << std::endl;
        _print(r->getLeft(), n + 1);
    }

    static void convertFromGeneralTreeHelper(TreeNode<T> *generalNode,
            BinaryTree<T> *binaryTree,
            BinaryTreeNode<T> *binaryParent)
    {
        if (generalNode == nullptr)
            return;

        BinaryTreeNode<T> *binaryNode =
            new BinaryTreeNode<T>(generalNode->getData());

        if (binaryParent != nullptr)
        {
            if (binaryParent->getLeft() == nullptr)
                binaryParent->setLeft(binaryNode);
            else
            {
                BinaryTreeNode<T> *rightmost = binaryParent->getLeft();
                while (rightmost->getRight() != nullptr)
                    rightmost = rightmost->getRight();
                rightmost->setRight(binaryNode);
            }
        }
        else
        {
            binaryTree->setRoot(binaryNode);
        }
        LinkList<TreeNode<T> *> children = generalNode->getChild();
        ListNode<TreeNode<T> *> *childNode = children.getHead();
        while (childNode != nullptr)
        {
            convertFromGeneralTreeHelper(childNode->getData(), binaryTree,
                                         binaryNode);
            childNode = childNode->getNext();
        }
    }
};

int main()
{
    Tree<int> *tree = new Tree<int>();
    srand(0);
    int j, k;
    for (j = 0; j < 20; j++)
    {
        if (tree->count() == 0)
            tree->setRoot(rand() % 100);
        else
        {
            k = rand() % tree->count();
            (*tree)[k]->addChild(rand() % 100);
        }
    }
    tree->levelOrder();
    tree->preorder();
    tree->postorder();

    BinaryTree<int> *binaryTree = BinaryTree<int>::convertFromGeneralTree(tree);
    binaryTree->print();
}
