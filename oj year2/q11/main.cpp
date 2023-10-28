#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>

using namespace std;

class Tree {
public:
  Tree() {
    int j;
    for (j = 0; j < 2000; j++)
      root[j] = -1;
  }
  int insert(int node) {
    int index = 0;
    while (index < 2000 && root[index] != -1) {
      if (root[index] < node)
        index = index * 2 + 2;
      else
        index = index * 2 + 1;
    }
    root[index] = node;
  }
  void inorder(int index) {
    if (index >= 0 && root[index] != -1) {
      inorder(index * 2 + 1);     // ���X���l��
      cout << root[index] << " "; // ��X��e�`�I��
      inorder(index * 2 + 2);     // ���X�k�l��
    }
  }

  // �e�Ǩ��X
  void preorder(int index) {
    if (index >= 0 && root[index] != -1) {
      cout << root[index] << " "; // ��X��e�`�I��
      preorder(index * 2 + 1);    // ���X���l��
      preorder(index * 2 + 2);    // ���X�k�l��
    }
  }

  // ��Ǩ��X
  void postorder(int index) {
    if (index >= 0 && root[index] != -1) {
      postorder(index * 2 + 1);   // ���X���l��
      postorder(index * 2 + 2);   // ���X�k�l��
      cout << root[index] << " "; // ��X��e�`�I��
    }
  }

  // �h�Ǩ��X
  void levelorder() {
    queue<int> q;
    q.push(0); // �N�ڸ`�I���ޥ[�J��C

    while (!q.empty()) {
      int index = q.front();
      q.pop();

      if (index >= 0 && root[index] != -1) {
        cout << root[index] << " "; // ��X��e�`�I��

        if (index * 2 + 1 < 2000) {
          q.push(index * 2 + 1); // ���l����ޤJ��C
        }
        if (index * 2 + 2 < 2000) {
          q.push(index * 2 + 2); // �k�l����ޤJ��C
        }
      }
    }
  }

private:
  int root[2000];
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
