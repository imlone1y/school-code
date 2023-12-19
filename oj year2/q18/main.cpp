#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <algorithm>

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
    void setHeight(int h)
    {
        height = h;
    }

    int getHeight() const
    {
        return height;
    }

private:
    BinaryTreeNode<T> *left, *right;
    int height;
};

template <class T> class AVLTree
{
private:
    int height;
    BinaryTreeNode<T> *root;

    void inorder(BinaryTreeNode<T> *cur, int n)
    {
        if (cur == NULL)
            return;
        inorder(cur->getRight(), n + 1);
        int j;
        for (j = 0; j < n; j++)
            cout << "  ";
        cout << cur << endl;
        inorder(cur->getLeft(), n + 1);
    }

public:
    AVLTree() : height(0), root(nullptr) {}

    int getHeight(BinaryTreeNode<T> *node)
    {
        if (node == nullptr)
            return 0;
        else
            return node->getHeight();
    }

    void updateHeight(BinaryTreeNode<T> *node)
    {
        if (node == nullptr)
            return;
        if (getHeight(node->getLeft()) > getHeight(node->getRight()))
            node->setHeight(getHeight(node->getLeft()) + 1);
        else
            node->setHeight(getHeight(node->getRight()) + 1);
    }

    BinaryTreeNode<T> *LL(BinaryTreeNode<T> *node)
    {
        BinaryTreeNode<T> *left = node->getLeft();
        BinaryTreeNode<T> *left_right = left->getRight();
        left->setRight(node);
        node->setLeft(left_right);
        updateHeight(node);
        updateHeight(left);
        return left;
    }

    BinaryTreeNode<T> *RR(BinaryTreeNode<T> *node)
    {
        BinaryTreeNode<T> *right = node->getRight();
        BinaryTreeNode<T> *right_left = right->getLeft();
        right->setLeft(node);
        node->setRight(right_left);
        updateHeight(node);
        updateHeight(right);
        return right;
    }

    BinaryTreeNode<T> *LR(BinaryTreeNode<T> *node)
    {
        BinaryTreeNode<T> *left = node->getLeft();
        BinaryTreeNode<T> *left_right = left->getRight();
        BinaryTreeNode<T> *left_right_left = left_right->getLeft();
        BinaryTreeNode<T> *left_right_right = left_right->getRight();
        left_right->setLeft(left);
        left_right->setRight(node);
        left->setRight(left_right_left);
        node->setLeft(left_right_right);
        updateHeight(left_right_left);
        updateHeight(left_right_right);
        updateHeight(left_right);
        return left_right;
    }

    BinaryTreeNode<T> *RL(BinaryTreeNode<T> *node)
    {
        BinaryTreeNode<T> *right = node->getRight();
        BinaryTreeNode<T> *right_left = right->getLeft();
        BinaryTreeNode<T> *right_left_left = right_left->getLeft();
        BinaryTreeNode<T> *right_left_right = right_left->getRight();
        right_left->setLeft(node);
        right_left->setRight(right);
        node->setRight(right_left_left);
        right->setLeft(right_left_right);
        updateHeight(right_left_left);
        updateHeight(right_left_right);
        updateHeight(right_left);
        return right_left;
    }

    BinaryTreeNode<T> *leftBalance(BinaryTreeNode<T> *node, T d)
    {
        if (d < node->getLeft()->getData())
            return LL(node);
        else
            return LR(node);
    }

    BinaryTreeNode<T> *rightBalance(BinaryTreeNode<T> *node, T d)
    {
        if (d < node->getRight()->getData())
            return RL(node);
        else
            return RR(node);
    }

    BinaryTreeNode<T> *insert(BinaryTreeNode<T> *node, T d)
    {
        if (node != nullptr)
        {
            if (d < node->getData())
            {
                node->setLeft(insert(node->getLeft(), d));
                if (abs(getHeight(node->getLeft()) - getHeight(node->getRight())) == 2)
                    return leftBalance(node, d);
            }
            else
            {
                node->setRight(insert(node->getRight(), d));
                if (abs(getHeight(node->getLeft()) - getHeight(node->getRight())) == 2)
                    return rightBalance(node, d);
            }
        }
        else
            return new BinaryTreeNode<T>(d);
        updateHeight(node);
        return node;
    }

    void insert(T d)
    {
        root = insert(root, d);
    }

    void inorder()
    {
        inorderHelper(root);
    }

    void inorderHelper(BinaryTreeNode<T> *node)
    {
        if (node != nullptr)
        {
            inorderHelper(node->getLeft());
            cout << node->getData() << " ";
            inorderHelper(node->getRight());
        }
    }
};

int main()
{
    AVLTree<int> *tree = new AVLTree<int>();
    srand(0);
    int j, k, i;
    for (j = 0; j < 20; j++)
    {
        tree->insert(rand() % 100);
        tree->inorder();
        cout << endl;
    }

    return 0;
}
