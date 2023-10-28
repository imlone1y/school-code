#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>

using namespace std;

class Tree {
public:
  Tree() {
    int j, k;
    for (j = 0; j < 20; j++)
      for (k = 0; k < 4; k++)
        root[j][k] = -1;
  }
  int insert(int node) {
    int f = 0, index = 0;
    while (root[index][0] != -1)
      index++;
    if (index >= 20)
      return -1;
    if (index == 0) {
      root[0][0] = 1;
      root[0][1] = node;
      return 1;
    } else {
      root[index][0] = 1;
      root[index][1] = node;
      while (1) {
        if (root[f][1] < node) {
          if (root[f][3] == -1) {
            root[f][3] = index;
            return 1;
          } else {
            f = root[f][3];
          }
        } else {
          if (root[f][2] == -1) {
            root[f][2] = index;
            return 1;
          } else {
            f = root[f][2];
          }
        }
      }
    }
  }
  void inorder(int index) {
    if (index >= 0) {
      inorder(root[index][2]);
      cout << root[index][1] << " ";
      inorder(root[index][3]);
    }
  }

  void preorder(int index) {
    if (index >= 0) {
      cout << root[index][1] << " ";
      preorder(root[index][2]);
      preorder(root[index][3]);
    }
  }

  void postorder(int index) {
    if (index >= 0) {
      postorder(root[index][2]);
      postorder(root[index][3]);
      cout << root[index][1] << " ";
    }
  }

  void levelorder() {
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
      int index = q.front();
      q.pop();

      if (index >= 0) {
        cout << root[index][1] << " ";

        if (root[index][2] != -1) {
          q.push(root[index][2]);
        }
        if (root[index][3] != -1) {
          q.push(root[index][3]);
        }
      }
    }
  }

private:
  int root[20][4];
};

int main() {
  Tree *tree = new Tree();
  int j, node;
  srand(time(NULL));
  for (j = 0; j < 10; j++) {
    node = rand()%100;
    tree->insert(node);
  }
  tree->inorder(0);
  printf("\n");
  tree->preorder(0);
  printf("\n");
  tree->postorder(0);
  printf("\n");
  tree->levelorder();
  printf("\n");
}
