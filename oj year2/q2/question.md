# Description

請完成函數 allocArray

該函數會配置一個整數的二維陣列，大小是 m * n

然後用 p 指向配置好的二維陣列

Please finish the function allocArray

This function will allocate a 2-D array with size m * n, then point the array using pointer p.
```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class Memory
{
public:
  static T **allocArray(int m, int n)
  {
  }
}

int main()
{
  int **array;
  array = Memory<int>::allocArray(5, 10);
  int j, k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      array[j][k] = j * 10 + k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      cout<<array[j][k]<<" ";
}
```
如果你能成功的配置一個二維陣列，你就能得到80分

如果你能配置出連續的空間，你就可以得到100分

You will get 80 point if you can successfully allocate a 2-D array.

You will get 100 point if you can allocateconsecutive memory for this 2-D array.
