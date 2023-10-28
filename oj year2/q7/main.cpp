#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <utility>

#define SIZE 10

using namespace std;

class Node {
public:
  Node() { Node(0, 0); } //��l��
  Node(int r, int c) {   //�]�w��C
    row = r;
    col = c;
  }
  int getRow() { return row; } //������
  int getCol() { return col; } //�����C
  void setRow(int r) {         //�]�w��
    if (r >= 0 && r < SIZE)
      row = r;
  }
  void setCol(int c) { //�]�w�C
    if (c >= 0 && c < SIZE)
      col = c;
  }

private:
  int col, row;
};

class List {
public:
  List() { top = 0; }
  void addElement(int r, int c) { //�K�[������data�}�C��
    if (top < SIZE * SIZE) { //�b�}�C�̪����������p��g�c�j�p�`��
      data[top].setCol(c);   //�]�w�C
      data[top].setRow(r);   //�]�w��
      top++;                 //�N���ޭ�+1
    }
  }
  Node *removeElement() { //�N�}�C�̳̤W������������
    if (!top)             //���ޭȬ�0�ɡA�}�C���L����
      return NULL;
    else {
      Node *i = &data[top]; //�����Y�N�Q������������m
      top--;                //�N���ޭ�-1�A�Y�N��������
      return i;             //�^�ǭ��Ҭ���������������m
    }
  }
  void printList() { //�L�X�Ҧ����������|
    int j;
    for (j = 0; j < top; j++) {
      cout << "(" << data[j].getRow() << ", " << data[j].getCol() << ")"
           << endl;
    }
  }

private:
  Node data[SIZE * SIZE]; //�������ʦ�m�ΰ}�C�A�ʽ�����stack(FILO)
  int top;                //���ޭ�
};

void allocArray(int ***p, int m, int n) { //�Ĥ@�D�ʺA�t�t�m�G���}�C
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
  Maze() { initMaze(SIZE); }       //��l�ưg�c
  void initMaze(int s) {           //�ͦ��g�c
    srand(time(NULL));             //���üƨϥήɶ����
    allocArray(&maze, SIZE, SIZE); //�ʺA�t�m�G���}�C
    //�°g�c�ͦ���k
    /*int wallCount = 0;//�������(1)�ƥ�
    for (int a = 0; a < s; a++) {//�ϥΰj��@�@���üƥͦ��g�c
      for (int b = 0; b < s; b++) {
        if ((a == b && a == 0) || (a == b && b == s -
    1))//�T�O�_�I�P���I���|�O����A�j����׶}�_�I�P���I continue; int input =
    (rand() % 2);//���üơA��2���l�ơץu�|�ͦ� 0 & 1 if (wallCount > (s * s *
    0.2))//�p�G�ͦ�������w�g�W�L�g�c�j�p��20% maze[a][b] =
    0;//�����N�����ܦ��i�q�L���| else if (input) {//�p�G���쪺�üƬ����(1)
          wallCount++;//�N����`��+1
          maze[a][b] = input;//�N����]�w�����
        } else
          maze[a][b] = input;//�N����]�w�����|
      }
    }
    maze[0][0] = 0;//��ʱN�_�I�]�����|
    maze[s - 1][s - 1] = 0;//��ʱN���I�]�����|*/

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
    for (int a = 0; a < s; a++) { //�L�X�ͦ��g�c�A�ˬd��
      for (int b = 0; b < s; b++) {
        cout << maze[a][b] << " ";
      }
      cout << endl;
    }
  }
  typedef pair<int, int>
      p; //�w�q�H�U�|�Ψ줧�y�k�]�Y�g�^�Apair���N�⪫��X�֬��@�����
  int n = SIZE, m = SIZE,
      found = 0; // n�Pm�����I����m�Afound���ˬd�O�_������I�ܼ�
  deque<p> path;           //�ŧi���V��C
  int visited[SIZE][SIZE]; //�ŧi�t�@�ӤG���}�C�������L�����|
  void dfs(int x, int y, List &line) { //�`���u���j�����j�禡
    if (found == 1)                    //�p�G�w�g������I
      return;                          //�����禡
    visited[x][y] = 1;                 //�N����������w���L
    path.push_back(make_pair(x, y));   //�N�����m��i���V��C��
    line.addElement(x, y); //�N�����m��i�����ΰ}�C(�W����data)
    if (x == n - 1 && y == m - 1) { //�p�G���欰���I
      found = 1;                    //�N�ˬd�O�_����I���ܼƧאּ�u
      cout << "Path: ";             //�H�U���L�X���V��C���Ҧ�����
      while (!path.empty()) {
        cout << "(" << path.front().first << "," << path.front().second << ")";
        path.pop_front();
        cout << ((path.empty()) ? "\n" : "��");
      }
      cout << endl;
      return;
    }

    if (x + 1 < n && visited[x + 1][y] == 0 &&
        maze[x + 1][y] ==
            0) //���p�V�k���S���W�X��ɡ��k��S�����X�L���k�䤣�O���
      dfs(x + 1, y, line); //�V�k���û��j
    if (y + 1 < m && visited[x][y + 1] == 0 &&
        maze[x][y + 1] ==
            0) //���p�V�W���S���W�X��ɡ��W���S�����X�L���W�����O���
      dfs(x, y + 1, line); //�V�W���û��j
    if (x - 1 >= 0 && visited[x - 1][y] == 0 &&
        maze[x - 1][y] ==
            0) //���p�V�����S���W�X��ɡ�����S�����X�L�����䤣�O���
      dfs(x - 1, y, line); //�V�����û��j
    if (y - 1 >= 0 && visited[x][y - 1] == 0 &&
        maze[x][y - 1] ==
            0) //���p�V�U���S���W�X��ɡ��U���S�����X�L���U�����O���
      dfs(x, y - 1, line); //�V�U���û��j

    if (!found) {           //�p�G�S��������I
      path.pop_back();      //�����w�[�J��m
      line.removeElement(); //�����w�[�J��m
    }
  }
  List *getPath() {        //���X���
    List *line = new List; //�s�ؤ@�Ӭ�����m��list
    dfs(0, 0, *line);      //�i��`���u�����X
    if (!found)            //�p�G��������I
      line->removeElement(); //�������h�[�J���_�I��m�A�_�h�|�L�X(0, 0)
    return line;             //�^�Ǭ�����m��list
  }
  void printMaze() { //�L�X�g�c
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
