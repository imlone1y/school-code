#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode
{
public:
    char data;
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode(char c) : data(c), isEnd(false), children(26, nullptr) {}
};

class Trie
{
private:
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode(' ');
    }

    void insert(string value)
    {
        TrieNode* current = root;
        for (char c : value)
        {
            int index = c - 'a';
            if (!current->children[index])
            {
                current->children[index] = new TrieNode(c);
            }
            current = current->children[index];
        }
        current->isEnd = true;
    }

    bool search(string key)
    {
        TrieNode* current = root;
        for (char c : key)
        {
            int index = c - 'a';
            if (!current->children[index])
            {
                return false;
            }
            current = current->children[index];
        }
        return current && current->isEnd;
    }

    void preorderUtil(TrieNode* node, int level)
    {
        if (node)
        {
            for (int i = 0; i < level * 2; ++i)
            {
                cout << " ";
            }
            cout << node->data << endl;

            for (TrieNode* child : node->children)
            {
                preorderUtil(child, level + 1);
            }
        }
    }

    void preorder()
    {
        if (root->children.empty())
        {
            cout << "[]" << endl;
        }
        else
        {
            preorderUtil(root, 0);
        }
    }
};

int main()
{
    Trie* trie = new Trie();
    string command, key, value;

    while (1)
    {
        cin >> command;
        if (command == "insert")
        {
            cin >> value;
            trie->insert(value);
        }
        else if (command == "search")
        {
            cin >> key;
            if (trie->search(key))
                cout << "exist" << endl;
            else
                cout << "not exist" << endl;
        }
        else if (command == "print")
        {
            trie->preorder();
        }
        else if (command == "exit")
        {
            break;
        }
    }

    delete trie; // Don't forget to free memory
    return 0;
}
