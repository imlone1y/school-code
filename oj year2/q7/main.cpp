#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <utility>

#define SIZE 10

using namespace std;

class Node {
public:
  Node() { Node(0, 0); } //初始化
  Node(int r, int c) {   //設定行列
    row = r;
    col = c;
  }
  int getRow() { return row; } //提取行
  int getCol() { return col; } //提取列
  void setRow(int r) {         //設定行
    if (r >= 0 && r < SIZE)
      row = r;
  }
  void setCol(int c) { //設定列
    if (c >= 0 && c < SIZE)
      col = c;
  }

private:
  int col, row;
};

class List {
public:
  List() { top = 0; }
  void addElement(int r, int c) { //添加元素至data陣列中
    if (top < SIZE * SIZE) { //在陣列裡的元素必須小於迷宮大小總數
      data[top].setCol(c);   //設定列
      data[top].setRow(r);   //設定行
      top++;                 //將索引值+1
    }
  }
  Node *removeElement() { //將陣列裡最上面的元素移除
    if (!top)             //索引值為0時，陣列中無元素
      return NULL;
    else {
      Node *i = &data[top]; //紀錄即將被移除的元素位置
      top--;                //將索引值-1，即將元素移除
      return i;             //回傳剛剛所紀錄移除元素之位置
    }
  }
  void printList() { //印出所有紀錄之路徑
    int j;
    for (j = 0; j < top; j++) {
      cout << "(" << data[j].getRow() << ", " << data[j].getCol() << ")"
           << endl;
    }
  }

private:
  Node data[SIZE * SIZE]; //紀錄移動位置用陣列，性質類似stack(FILO)
  int top;                //索引值
};

void allocArray(int ***p, int m, int n) { //第一題動態配配置二維陣列
  int *arr = (int *)malloc(m * n * sizeof(int));
  int **arr2 = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    arr2[i] = arr;
    arr += n;
  }
  *p = arr2;
}

class Maze {
public:
  Maze() { initMaze(SIZE); }       //初始化迷宮
  void initMaze(int s) {           //生成迷宮
    srand(time(NULL));             //取亂數使用時間函數
    allocArray(&maze, SIZE, SIZE); //動態配置二維陣列
    //舊迷宮生成方法
    /*int wallCount = 0;//紀錄牆壁(1)數目
    for (int a = 0; a < s; a++) {//使用迴圈一一取亂數生成迷宮
      for (int b = 0; b < s; b++) {
        if ((a == b && a == 0) || (a == b && b == s -
    1))//確保起點與終點不會是牆壁，迴圈需避開起點與終點 continue; int input =
    (rand() % 2);//取亂數，除2的餘數＝只會生成 0 & 1 if (wallCount > (s * s *
    0.2))//如果生成的牆壁已經超過迷宮大小的20% maze[a][b] =
    0;//直接將此格變成可通過路徑 else if (input) {//如果取到的亂數為牆壁(1)
          wallCount++;//將牆壁總數+1
          maze[a][b] = input;//將此格設定為牆壁
        } else
          maze[a][b] = input;//將此格設定為路徑
      }
    }
    maze[0][0] = 0;//手動將起點設為路徑
    maze[s - 1][s - 1] = 0;//手動將終點設為路徑*/

    for (int a = 0; a < s; a++) {
      for (int b = 0; b < s; b++) {
        maze[a][b] = 0;
      }
    }
    for (int a = 0; a < s * s * 0.2; a++) {
      int inx = rand() % s;
      int iny = rand() % s;
      if (!(inx == 0 && iny == 0) && !(inx == s - 1 && iny == s - 1) &&
          !maze[inx][iny])
        maze[inx][iny] = 1;
      else
        a--;
    }
    for (int a = 0; a < s; a++) { //印出生成迷宮，檢查用
      for (int b = 0; b < s; b++) {
        cout << maze[a][b] << " ";
      }
      cout << endl;
    }
  }
  typedef pair<int, int>
      p; //定義以下會用到之語法（縮寫），pair為將兩物件合併為一的函數
  int n = SIZE, m = SIZE,
      found = 0; // n與m為終點之位置，found為檢查是否走到終點變數
  deque<p> path;           //宣告雙向佇列
  int visited[SIZE][SIZE]; //宣告另一個二維陣列紀錄走過之路徑
  void dfs(int x, int y, List &line) { //深度優先搜索遞迴函式
    if (found == 1)                    //如果已經走到終點
      return;                          //結束函式
    visited[x][y] = 1;                 //將此格紀錄為已走過
    path.push_back(make_pair(x, y));   //將此格位置放進雙向佇列中
    line.addElement(x, y); //將此格位置放進紀錄用陣列(上面的data)
    if (x == n - 1 && y == m - 1) { //如果此格為終點
      found = 1;                    //將檢查是否到終點之變數改為真
      cout << "Path: ";             //以下為印出雙向佇列中所有元素
      while (!path.empty()) {
        cout << "(" << path.front().first << "," << path.front().second << ")";
        path.pop_front();
        cout << ((path.empty()) ? "\n" : "→");
      }
      cout << endl;
      return;
    }

    if (x + 1 < n && visited[x + 1][y] == 0 &&
        maze[x + 1][y] ==
            0) //假如向右走沒有超出邊界＆右邊沒有走訪過＆右邊不是牆壁
      dfs(x + 1, y, line); //向右走並遞迴
    if (y + 1 < m && visited[x][y + 1] == 0 &&
        maze[x][y + 1] ==
            0) //假如向上走沒有超出邊界＆上面沒有走訪過＆上面不是牆壁
      dfs(x, y + 1, line); //向上走並遞迴
    if (x - 1 >= 0 && visited[x - 1][y] == 0 &&
        maze[x - 1][y] ==
            0) //假如向左走沒有超出邊界＆左邊沒有走訪過＆左邊不是牆壁
      dfs(x - 1, y, line); //向左走並遞迴
    if (y - 1 >= 0 && visited[x][y - 1] == 0 &&
        maze[x][y - 1] ==
            0) //假如向下走沒有超出邊界＆下面沒有走訪過＆下面不是牆壁
      dfs(x, y - 1, line); //向下走並遞迴

    if (!found) {           //如果沒有走到終點
      path.pop_back();      //移除已加入位置
      line.removeElement(); //移除已加入位置
    }
  }
  List *getPath() {        //走訪函數
    List *line = new List; //新建一個紀錄位置用list
    dfs(0, 0, *line);      //進行深度優先走訪
    if (!found)            //如果走不到終點
      line->removeElement(); //須移除多加入之起點位置，否則會印出(0, 0)
    return line;             //回傳紀錄位置用list
  }
  void printMaze() { //印出迷宮
    int j, k;
    for (j = 0; j < SIZE; j++) {
      for (k = 0; k < SIZE; k++) {
        if (maze[j][k] == 0)
          cout << " ";
        else if (maze[j][k] == 1)
          cout << "*";
      }
      cout << "\n";
    }
  }

private:
  int **maze;
};

int main() {
  Maze *maze = new Maze();
  maze->printMaze();
  maze->getPath()->printList();
}
