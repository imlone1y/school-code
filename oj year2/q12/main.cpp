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
        at->setNext(node);//�����b�o�����
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
            return NULL;;;//��M�o�{�h�X�Ӥ������v�T�{���B��
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

template <class T> class TreeNode : public Node<T>//��`�I���O
{
public:
    TreeNode() : Node<T>()//�غc�l
    {
        child = new LinkList<TreeNode<T> *>();//�t�m�@��linklist���A���Ŷ�
    }
    TreeNode(T d) : Node<T>(d)//�غc�l
    {
        child = new LinkList<TreeNode<T> *>();//�t�m�@��linklist���A���Ŷ�
    }
    void addChild(TreeNode *n)//�s�W�l�`�I
    {
        child->addFromTail(n);//�[�J�`�I���覡�����Jlinklist����
    }
    void addChild(T d)//�s�W�l�`�I
    {
        TreeNode<T> *childNode = new TreeNode<T>(d);//�t�m�@�ӷs����`�I�A�̭�����Ƭ�T���A��d�A�NchildNode���V��
        child->addFromTail(childNode);//�NchildNode�[�J��linklist����
        //cout << "addChild->" << childNode << endl; �ˬd���J�`�I�ƭ�
    }
    TreeNode<T> *operator[](int n)//overload
    {
        return (*child)[n];//�եΤW��linklist��overload
    }

    TreeNode<T> *getChild(int index)//�������ޭȩҹ������ƭ�
    {
        if (index < 0 || index >= child->count())//�p�G���ޭȤp��0�Τj�󵥩��`���I��
        {
            throw std::invalid_argument("Invalid child index.");//throw�ҥ~�T���Ainvalid_argument��ܵL�Ī����ޭ�
        }
        ListNode<TreeNode<T> *> *currentChild = child->getHead();//�s��currentChild���Ы��Vlinklist��head
        for (int i = 0; i < index; i++)//�N���Щ���i��
        {
            currentChild = currentChild->getNext();
        }
        return currentChild->getData();//�^��currenChild���V���ƭ�
    }
    LinkList<TreeNode<T> *> *getChild()//����private����child
    {
        return child;
    }

private:
    LinkList<TreeNode<T> *> *child;
};

template <class T> class Tree//�����O
{
public:
    int countRecursive(TreeNode<T> *node)//�ϥλ��j�p�⦹�`�I���U���h�֤l�`�I�A�ϥΪ��Odfs
    {
        if (node == nullptr)//�P�_���V���y�Ь�null�A��ܻ��j�ܩ���
        {
            return 0;//����j
        }

        int count = 1;//��e���X���`�I�]�n��

        LinkList<TreeNode<T> *> *children = node->getChild();//�����o��e�`�I�Ҧb��linklist
        ListNode<TreeNode<T> *> *currentChild = children->getHead();//�A���olinklist��head

        while (currentChild != nullptr)
        {
            count += countRecursive(currentChild->getData());//count�[�W�A�N��e�`�I�U�h���j�A�Ҿ֦����l�`�I�ƥ�
            currentChild = currentChild->getNext();//�N��e�`�I����
        }

        return count;//�^�Ǹ`�I��
    }
    int count()
    {
        return countRecursive(root);//�I�s���j�禡�A�q�ڸ`�I�}�l�p��
    }

    Tree()//�غc�l
    {
        root = NULL;//�N�ڸ`�I�k�s
    }

    TreeNode<T> *operator[](int n)//overload����ޭȡA���D�ػݨD�A�^�Ǫ��O�ϥμh�Ǩ��X������
    {
        if (n < 0 || n >= count())//���ޭȤp��άO�j�󵥩��`�`�I��
        {
            throw invalid_argument("Invalid index.");//throw�ҥ~�T���Ainvalid_argument��ܵL�Ī����ޭ�
        }

        LinkList<TreeNode<T> *> treequeue;//�s�ؤ@��linklist�Ω�h�Ǩ��X�Alinklist�@��������queue

        treequeue.addFromTail(root);//���[�J�ڸ`�I�ilinklist�A��y�k����queue.push(root);

        try//try...catch...���ҥ~�B�z���
        {
            while (1)//�ä[�`��
            {
                TreeNode<T> *current = treequeue.removeFromHead()->getData();//�Nlinklist��head�����ô�����ƭȡA��y�k����*current=queue.top(); queue.pop();
                if (n == 0)//���p���X�ܯ��ޭ�
                {
                    return current;//�^��current�ƭ�
                }
                for (int i = 0;; i++)
                {
                    try
                    {
                        treequeue.addFromTail(current->getChild(i));//�N�`�I�Ҧblevel���Ҧ��`�I�[�Jlinklist��
                        /*��y�k����
                        while(current->getChild(i)!=NULL)
                        {
                            queue.push(current->getChild(i)->getData());
                            current = current->getNext();
                        }*/
                    }
                    catch (invalid_argument e)//��եΪ��ƭȵL�Į�(���P��current->getChild(i)==NULL)
                    {
                        break;//���X�j��
                    }
                }
                n--;//�C�i��j��@���A���ޭȳ��n��1
            }
        }
        catch (invalid_argument e)//�p�G�b���`�I���L�{���X�{�ҥ~�A��ܾ�w�g�h�Ǩ��X����
        {
            return nullptr;
        }
    }

    void levelOrder()//�𪺼h�Ǩ��X
    {
        if (root == nullptr)//���p�𬰪�
        {
            return;
        }

        queue<TreeNode<T> *> queue;//�s�ؤ@�ӥsqueue����C�A�ΨӦs��TreeNode���A���ܼ�
        queue.push(root);//�[�J�ڸ`�I

        while (!queue.empty())//��queue�|������
        {
            TreeNode<T> *current = queue.front();//�x�squeue�̫e������

            queue.pop();//�N�̫e�������R��

            cout << current->getData() << " ";//�L�Xqueue�̫e��������

            //�N���`�I���l�`�I���ƥ[�Jqueue���A����k�P�W��count��ƩҨϥΪ���k�@�P
            LinkList<TreeNode<T> *> *children = current->getChild();//�N���`�I���l�`�I���ƥ[�J
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
        preorderTraversal(root);//�եΫe�Ǩ��X���j�禡
    }
    void postorder()
    {
        postorderTraversal(root);//�եΫ�Ǩ��X���j�禡
    }
    void setRoot(T d)//�]�w�ڸ`�I
    {
        if (root == nullptr)//���p�|���]�m�ڸ`�I
        {
            root = new TreeNode<T>(d);//�N�ڸ`�I�t�m�ܷs�O����
        }
    }

private:
    TreeNode<T> *root;

    void preorderTraversal(TreeNode<T> *node)//�e�Ǩ��X���j�禡
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
    void postorderTraversal(TreeNode<T> *node)//��Ǩ��X���j�禡
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
