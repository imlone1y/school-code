#include <cstdlib>
#include <ctime>
#include <iostream>

#define SIZE 10

using namespace std;

class Node
{
public:
    Node()
    {
        Node(0, 0);
    }
    Node(int r, int c)
    {
        row = r;
        col = c;
    }
    int getRow()
    {
        return row;
    }
    int getCol()
    {
        return col;
    }
    void setRow(int r)
    {
        if (r >= 0 && r < SIZE)
            row = r;
    }
    void setCol(int c)
    {
        if (c >= 0 && c < SIZE)
            col = c;
    }

private:
    int col, row;
};

class List
{
public:
    List()
    {
        top = 0;
    }
    /*
    function addElement
    Insert an element from list
    */
    void addElement(int r, int c)
    {
        if (top < SIZE*SIZE)
        {
            data[top]=Node(r,c);
            top++;
        }
    }
    /*
    function removeElement
    remove an element from list and return a pointer point to the element.
    If list is empty, return NULL.
    */
    Node *removeElement()
    {
        if (!top)
            return NULL;
        else
        {
            Node *i = &data[top - 1];
            top--;
            return i;
        }
    }
    void printList()
    {
        int j;
        for (j = 0; j < top; j++)
        {
            cout << "(" << data[j].getRow() << ", " << data[j].getCol() << ")"
                 << endl;
        }
    }

private:
    Node data[SIZE * SIZE];
    int top;
};

class Maze
{
public:
    Maze()
    {
        initMaze(SIZE);
    }
    /*
    function initMaze
    Alocate a 2-D array with s * s sizes as the map of maze.
    Inside the maze where 0 represent empty space and 1 represent wall.
    [0][0] is start point and [s - 1][s - 1] is finish point.
    Randomly generate 20% wall in the maze.
    Make sure [0][0] and [s - 1][s - 1] are 0

    動態配置一個二維的陣列，大小是 s * s ，用這個陣列表示迷宮的地圖
    陣列中 0 的值表示可以移動的空間， 1 表示牆壁
    [0][0] 的位置表示起點 [s - 1][s - 1] 的位置表示終點
    請在迷宮中加入 20% 的牆壁
    然後確定起點跟終點都是可以移動的位置
    */
    void initMaze(int s)
    {
        srand(time(NULL));
        int wallCount = 0;
        for (int a = 0; a < s; a++)
        {
            for (int b = 0; b < s; b++)
            {
                if((a==b && a==0) || (a==b && b==s-1))
                    continue;
                int input = (rand() % 2);
                if (wallCount > (s * s * 0.2))
                    maze[a][b] = 0;
                else if (input)
                {
                    wallCount++;
                    maze[a][b] = input;
                }
                else
                    maze[a][b] = input;
            }
        }
        maze[0][0] = 0;
        maze[s - 1][s - 1] = 0;
        /*for (int a = 0; a < s; a++)
        {
            for (int b = 0; b < s; b++)
            {
                cout << maze[a][b] << " ";
            }
            cout << endl;
        }*/
    }
    /*
    function getPath
    This function will find a path between start point and finish point.
    Return a list content the path information inside.
    If there is no path between two point then the list will be empty.

    這個函數會找到起點到終點間的一條路徑
    回傳一個 list 包含著路徑的資訊
    如果找不到路徑的話 list 就會是空的
    */
    List *getPath()
    {
        List *path = new List;
        int flag=1;
        maze[0][0]=2;
        while(flag)
        {
            flag=0;
            for(int a=0; a<SIZE; a++)
            {
                for(int b=0; b<SIZE; b++)
                {
                    if(maze[a][b]==0)
                    {
                        if((maze[a+1][b]==2 && a+1<SIZE) || (maze[a-1][b]==2 && a-1>=0) || (maze[a][b+1]==2 && b+1<SIZE) || (maze[a][b-1]==2 && b-1>=0))
                        {
                            maze[a][b]=2;
                            flag=1;
                        }
                    }

                }
            }
        }
        for (int a = 0; a < SIZE; a++)
        {
            for (int b = 0; b < SIZE; b++)
            {
                cout << maze[a][b] << " ";
            }
            cout << endl;
        }
        return path;
    }
    void printMaze()
    {
        int j, k;
        for (j = 0; j < SIZE; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                if (maze[j][k] == 0)
                    cout << " ";
                else if (maze[j][k] == 1)
                    cout << "*";
            }
            cout << "\n";
        }
    }

private:
    int maze[SIZE][SIZE];
};

int main()
{
    Maze *maze = new Maze();
    maze->printMaze();
    maze->getPath()->printList();
}
