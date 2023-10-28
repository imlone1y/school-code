#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>

using namespace std;

#define SIZE 10
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Grid {
public:
  Grid() { Grid(0); }
  Grid(int s) {
    state = s;
    dir[UP] = NULL;
    dir[DOWN] = NULL;
    dir[LEFT] = NULL;
    dir[RIGHT] = NULL;
  }
  Grid *getDir(int d) { return dir[d]; }
  int getState() { return state; }
  void setDir(int d, Grid *g) { dir[d] = g; }
  void setState(int s) { state = s; }

private:
  Grid *dir[4];
  int state;
};

struct List {
public:
  List() { top = 0; }
  void addElement(Grid *g) {
    data[top] = g;
    top++;
  }
  Grid *removeElement() {
    if (!top)
      return NULL;
    else {
      top--;
      return data[top];
    }
  }
  void printPath() {
    int j;
    for (j = 1; j < top; j++) {
      if (data[j] == data[j - 1]->getDir(UP)) {
        cout << "UP\n";
      } else if (data[j] == data[j - 1]->getDir(DOWN)) {
        cout << "DOWN\n";
      } else if (data[j] == data[j - 1]->getDir(LEFT)) {
        cout << "LEFT\n";
      } else if (data[j] == data[j - 1]->getDir(RIGHT)) {
        cout << "RIGHT\n";
      }
    }
  }

private:
  Grid *data[SIZE * SIZE];
  int top;
};

class Memory {
public:
  static Grid **allocArray(int m, int n) {
    Grid *arr = new Grid[m * n];
    Grid **arr2 = new Grid *[m];

    for (int i = 0; i < m; i++) {
      arr2[i] = arr;
      arr += n;
    }
    return arr2;
  }
};

class Maze {
public:
  Maze() { initMaze(SIZE); }
  void initMaze(int s) {
    srand(time(NULL));
    int wallCount = 0;
    maze = Memory::allocArray(SIZE, SIZE);
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        maze[i][j].setState(0);
      }
    }
    maze[0][0].setState(0);
    maze[s - 1][s - 1].setState(0);

    while (wallCount < s * s * 0.2) {
      int x = rand() % s;
      int y = rand() % s;
      if ((x != 0 || y != 0) && (x != s - 1 || y != s - 1) &&
          maze[x][y].getState() == 0) {
        maze[x][y].setState(1);
        wallCount++;
      }
    }
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        if (i > 0)
          maze[i][j].setDir(UP, &maze[i - 1][j]);
        if (i < s - 1)
          maze[i][j].setDir(DOWN, &maze[i + 1][j]);
        if (j > 0)
          maze[i][j].setDir(LEFT, &maze[i][j - 1]);
        if (j < s - 1)
          maze[i][j].setDir(RIGHT, &maze[i][j + 1]);
      }
    }
  }

  typedef pair<int, int>
      p; //定義以下會用到之語法（縮寫），pair為將兩物件合併為一的函數
  int n = SIZE, m = SIZE,
      found = 0; // n與m為終點之位置，found為檢查是否走到終點變數
  deque<p> path;           //宣告雙向佇列
  int visited[SIZE][SIZE]; //宣告另一個二維陣列紀錄走過之路徑
  void dfs(int x, int y, List &line) { //深度優先搜索遞迴函式
    // cout << maze[x][y].getState() << " ";
    if (found == 1)                  //如果已經走到終點
      return;                        //結束函式
    visited[x][y] = 1;               //將此格紀錄為已走過
    path.push_back(make_pair(x, y)); //將此格位置放進雙向佇列中
    line.addElement(&maze[x][y]); //將此格位置放進紀錄用陣列(上面的data)
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

    for (int dir = 0; dir < 4; ++dir) {
      int nx = x, ny = y;
      switch (dir) {
      case UP:
        nx = x - 1;
        break;
      case DOWN:
        nx = x + 1;
        break;
      case LEFT:
        ny = y - 1;
        break;
      case RIGHT:
        ny = y + 1;
        break;
      }

      if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] &&
          maze[x][y].getDir(dir)->getState() == 0) {
        dfs(nx, ny, line);
      }
    }
    if (!found) {           //如果沒有走到終點
      path.pop_back();      //移除已加入位置
      line.removeElement(); //移除已加入位置
    }
  }
  List *getPath() {
    List *line = new List;
    dfs(0, 0, *line);
    return line;
  }
  void printMaze() {
    Grid *j = *maze, *k;
    while (j != NULL) {
      k = j;
      while (k != NULL) {
        cout << k->getState();
        k = k->getDir(RIGHT);
      }
      cout << endl;
      j = j->getDir(DOWN);
    }
  }

private:
  Grid **maze;
};

int main() {
  Maze *maze = new Maze();
  maze->printMaze();
  maze->getPath()->printPath();
}
