# Description

Please read and understand class Node, ListNode and LinkList, then finish class TreeNode and Tree.

請讀懂類別 Node, ListNode 以及 LinkList，然後完成類別 TreeNode  以及 Tree

```cpp
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
protected:
    ListNode<T> *head, *tail;
};

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
    void addChild(TreeNode *n)
    {
        child->addFromTail(n);
    }
    void addChild(T d)
    {
        TreeNode<T> *childNode = new TreeNode<T>(d);
        child->addFromTail(childNode);
        //cout << "addChild->" << childNode << endl;
    }
    TreeNode<T> *operator[](int n)
    {
        return (*child)[n];
    }

    TreeNode<T> *getChild(int index)
    {
        if (index < 0 || index >= child->count())
        {
            //cout << "childcount=" <<  child->count() << " ";
            throw std::invalid_argument("Invalid child index.");
        }
        ListNode<TreeNode<T> *> *currentChild = child->getHead();
        for (int i = 0; i < index; i++)
        {
            currentChild = currentChild->getNext();
        }
        return currentChild->getData();
    }
    LinkList<TreeNode<T> *> *getChild()
    {
        return child;
    }

private:
    LinkList<TreeNode<T> *> *child;
};

template <class T> class Tree
{
public:
    int countRecursive(TreeNode<T> *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int count = 1;

        LinkList<TreeNode<T> *> *children = node->getChild();
        ListNode<TreeNode<T> *> *currentChild = children->getHead();

        while (currentChild != nullptr)
        {
            count += countRecursive(currentChild->getData());
            currentChild = currentChild->getNext();
        }

        return count;
    }
    Tree()
    {
        root = NULL;
    }

    TreeNode<T> *operator[](int n)
    {
        if (n < 0 || n >= count())
        {
            throw std::invalid_argument("Invalid index.");
        }

        LinkList<TreeNode<T> *> treequeue;
        treequeue.addFromTail(root);
        try
        {
            while (1)
            {
                TreeNode<T> *current = treequeue.removeFromHead()->getData();
                if (n == 0)
                {
                    return current;
                }
                for (int i = 0;; i++)
                {
                    try
                    {
                        treequeue.addFromTail(current->getChild(i));
                    }
                    catch (std::invalid_argument e)
                    {
                        break;
                    }
                }
                n--;
            }
        }
        catch (std::invalid_argument e)
        {
            return nullptr;
        }
    }
    int count()
    {
        return countRecursive(root);
    }

    void levelOrder()
    {
        if (root == nullptr)
        {
            return;
        }

        queue<TreeNode<T> *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            TreeNode<T> *current = queue.front();
            queue.pop();

            cout << current->getData() << " ";

            LinkList<TreeNode<T> *> *children = current->getChild();
            ListNode<TreeNode<T> *> *currentChild = children->getHead();

            while (currentChild != nullptr)
            {
                queue.push(currentChild->getData());
                currentChild = currentChild->getNext();
            }
        }
    }
    void preorder()
    {
        preorderTraversal(root);
    }
    void postorder()
    {
        postorderTraversal(root);
    }
    void setRoot(T d)
    {
        if (root == nullptr)
        {
            root = new TreeNode<T>(d);
        }
    }

private:
    TreeNode<T> *root;

    void preorderTraversal(TreeNode<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }

        cout << node->getData() << " ";

        LinkList<TreeNode<T> *> *children = node->getChild();
        ListNode<TreeNode<T> *> *currentChild = children->getHead();

        while (currentChild != nullptr)
        {
            preorderTraversal(currentChild->getData());
            currentChild = currentChild->getNext();
        }
    }
    void postorderTraversal(TreeNode<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }

        LinkList<TreeNode<T> *> *children = node->getChild();
        ListNode<TreeNode<T> *> *currentChild = children->getHead();

        while (currentChild != nullptr)
        {
            postorderTraversal(currentChild->getData());
            currentChild = currentChild->getNext();
        }

        cout << node->getData() << " ";
    }
};

int main()
{
    Tree<int> *tree = new Tree<int>();
    srand(0);
    int j, k;
    for(j = 0; j < 20; j++)
    {
        if(tree->count() == 0)
            tree->setRoot(rand() % 100);
        else
        {
            k = rand() % tree->count();
            (*tree)[k]->addChild(rand() % 100);
        }
    }
    tree->levelOrder();
    cout << endl;
    tree->preorder();
    cout << endl;
    tree->postorder();
}
```
