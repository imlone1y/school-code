#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
  int level, data;
  Node *left, *right;
};

class Tree {
public:
  Tree() { root = NULL; }
  int insert(Node *n) { insert(&root, n); }
  Node *getRoot()
  {
    return root;
  }
  void inorder(Node *root) {
    if (root == nullptr) {
      return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }

  void preorder(Node *root) {
    if (root == nullptr) {
      return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }

  void postorder(Node *root) {
    if (root == nullptr) {
      return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }

  void levelorder() {
    if (root == nullptr) {
      return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      Node *current = q.front();
      cout << current->data << " ";
      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }
      q.pop();
    }
  }

private:
  Node *root;
  void insert(struct Node **r, struct Node *n) {
    if (*r == NULL)
      *r = n;
    else if (n->data > (*r)->data)
      insert(&((*r)->right), n);
    else
      insert(&((*r)->left), n);
  }
};

int main() {
  Tree *tree = new Tree();
  Node *node;
  int j;
  srand(time(NULL));
  for (j = 0; j < 10; j++) {
    node = new Node();
    node->data = rand() % 50;
    node->left = NULL;
    node->right = NULL;
    tree->insert(node);
  }
  tree->inorder(tree->getRoot());
  cout << endl;
  tree->preorder(tree->getRoot());
  cout << endl;
  tree->postorder(tree->getRoot());
  cout << endl;
  tree->levelorder();
  cout << endl;

  return 0;
}
