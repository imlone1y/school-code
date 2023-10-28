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
      inorder(index * 2 + 1);     // 走訪左子樹
      cout << root[index] << " "; // 輸出當前節點值
      inorder(index * 2 + 2);     // 走訪右子樹
    }
  }

  // 前序走訪
  void preorder(int index) {
    if (index >= 0 && root[index] != -1) {
      cout << root[index] << " "; // 輸出當前節點值
      preorder(index * 2 + 1);    // 走訪左子樹
      preorder(index * 2 + 2);    // 走訪右子樹
    }
  }

  // 後序走訪
  void postorder(int index) {
    if (index >= 0 && root[index] != -1) {
      postorder(index * 2 + 1);   // 走訪左子樹
      postorder(index * 2 + 2);   // 走訪右子樹
      cout << root[index] << " "; // 輸出當前節點值
    }
  }

  // 層序走訪
  void levelorder() {
    queue<int> q;
    q.push(0); // 將根節點索引加入佇列

    while (!q.empty()) {
      int index = q.front();
      q.pop();

      if (index >= 0 && root[index] != -1) {
        cout << root[index] << " "; // 輸出當前節點值

        if (index * 2 + 1 < 2000) {
          q.push(index * 2 + 1); // 左子樹索引入佇列
        }
        if (index * 2 + 2 < 2000) {
          q.push(index * 2 + 2); // 右子樹索引入佇列
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
