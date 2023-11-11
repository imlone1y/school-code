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
        at->setNext(node);//偷偷在這邊註解
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
            return NULL;;;//突然發現多幾個分號不影響程式運行
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

template <class T> class TreeNode : public Node<T>//樹節點類別
{
public:
    TreeNode() : Node<T>()//建構子
    {
        child = new LinkList<TreeNode<T> *>();//配置一個linklist型態的空間
    }
    TreeNode(T d) : Node<T>(d)//建構子
    {
        child = new LinkList<TreeNode<T> *>();//配置一個linklist型態的空間
    }
    void addChild(TreeNode *n)//新增子節點
    {
        child->addFromTail(n);//加入節點的方式為插入linklist尾端
    }
    void addChild(T d)//新增子節點
    {
        TreeNode<T> *childNode = new TreeNode<T>(d);//配置一個新的樹節點，裡面的資料為T型態的d，將childNode指向它
        child->addFromTail(childNode);//將childNode加入至linklist尾端
        //cout << "addChild->" << childNode << endl; 檢查插入節點數值
    }
    TreeNode<T> *operator[](int n)//overload
    {
        return (*child)[n];//調用上方linklist的overload
    }

    TreeNode<T> *getChild(int index)//提取索引值所對應之數值
    {
        if (index < 0 || index >= child->count())//如果索引值小於0或大於等於總結點數
        {
            throw std::invalid_argument("Invalid child index.");//throw例外訊息，invalid_argument表示無效的索引值
        }
        ListNode<TreeNode<T> *> *currentChild = child->getHead();//新建currentChild指標指向linklist的head
        for (int i = 0; i < index; i++)//將指標往後i個
        {
            currentChild = currentChild->getNext();
        }
        return currentChild->getData();//回傳currenChild指向的數值
    }
    LinkList<TreeNode<T> *> *getChild()//提取private成員child
    {
        return child;
    }

private:
    LinkList<TreeNode<T> *> *child;
};

template <class T> class Tree//樹類別
{
public:
    int countRecursive(TreeNode<T> *node)//使用遞迴計算此節點底下有多少子節點，使用的是dfs
    {
        if (node == nullptr)//判斷指向之座標為null，表示遞迴至底部
        {
            return 0;//停止遞迴
        }

        int count = 1;//當前走訪的節點也要算

        LinkList<TreeNode<T> *> *children = node->getChild();//先取得當前節點所在的linklist
        ListNode<TreeNode<T> *> *currentChild = children->getHead();//再取得linklist的head

        while (currentChild != nullptr)
        {
            count += countRecursive(currentChild->getData());//count加上，將當前節點下去遞迴，所擁有的子節點數目
            currentChild = currentChild->getNext();//將當前節點往後
        }

        return count;//回傳節點數
    }
    int count()
    {
        return countRecursive(root);//呼叫遞迴函式，從根節點開始計算
    }

    Tree()//建構子
    {
        root = NULL;//將根節點歸零
    }

    TreeNode<T> *operator[](int n)//overload樹索引值，應題目需求，回傳的是使用層序走訪的順序
    {
        if (n < 0 || n >= count())//索引值小於或是大於等於總節點數
        {
            throw invalid_argument("Invalid index.");//throw例外訊息，invalid_argument表示無效的索引值
        }

        LinkList<TreeNode<T> *> treequeue;//新建一個linklist用於層序走訪，linklist作用類似於queue

        treequeue.addFromTail(root);//先加入根節點進linklist，其語法等於queue.push(root);

        try//try...catch...為例外處理函數
        {
            while (1)//永久循環
            {
                TreeNode<T> *current = treequeue.removeFromHead()->getData();//將linklist的head移除並提取其數值，其語法等於*current=queue.top(); queue.pop();
                if (n == 0)//假如走訪至索引值
                {
                    return current;//回傳current數值
                }
                for (int i = 0;; i++)
                {
                    try
                    {
                        treequeue.addFromTail(current->getChild(i));//將節點所在level的所有節點加入linklist中
                        /*其語法等於
                        while(current->getChild(i)!=NULL)
                        {
                            queue.push(current->getChild(i)->getData());
                            current = current->getNext();
                        }*/
                    }
                    catch (invalid_argument e)//當調用的數值無效時(等同於current->getChild(i)==NULL)
                    {
                        break;//跳出迴圈
                    }
                }
                n--;//每進行迴圈一次，索引值都要減1
            }
        }
        catch (invalid_argument e)//如果在取節點的過程中出現例外，表示樹已經層序走訪完畢
        {
            return nullptr;
        }
    }

    void levelOrder()//樹的層序走訪
    {
        if (root == nullptr)//假如樹為空
        {
            return;
        }

        queue<TreeNode<T> *> queue;//新建一個叫queue的佇列，用來存取TreeNode型態的變數
        queue.push(root);//加入根節點

        while (!queue.empty())//當queue尚有元素
        {
            TreeNode<T> *current = queue.front();//儲存queue最前面元素

            queue.pop();//將最前面元素刪除

            cout << current->getData() << " ";//印出queue最前面的元素

            //將此節點的子節點全數加入queue中，此方法與上方count函數所使用的方法一致
            LinkList<TreeNode<T> *> *children = current->getChild();//將此節點的子節點全數加入
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
        preorderTraversal(root);//調用前序走訪遞迴函式
    }
    void postorder()
    {
        postorderTraversal(root);//調用後序走訪遞迴函式
    }
    void setRoot(T d)//設定根節點
    {
        if (root == nullptr)//假如尚未設置根節點
        {
            root = new TreeNode<T>(d);//將根節點配置至新記憶體
        }
    }

private:
    TreeNode<T> *root;

    void preorderTraversal(TreeNode<T> *node)//前序走訪遞迴函式
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
    void postorderTraversal(TreeNode<T> *node)//後序走訪遞迴函式
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
