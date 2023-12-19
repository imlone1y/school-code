# Description

A binary heap is a heap data structure that takes the form of a binary tree.

A binary heap is defined as a binary tree with two additional constraints:

1. Shape property: a binary heap is a complete binary tree; that is, all levels of the tree, except possibly the last one (deepest) are fully filled, and, if the last level of the tree is not complete, the nodes of that level are filled from left to right.

2. Heap property: the key stored in each node is either greater than or equal to (≥) or less than or equal to (≤) the keys in the node's children, according to some total order.

Binary heap - Wikipedia

Please implement the MaxHeap class in the template.
```cpp
template<class T>
class MaxHeap {
public:
  //Constructing a empty heap.
  MaxHeap();
  //To add an element to the heap.
  void insert(T );
  //To remove the root element in the heap and return it.
  T extract();
  //Return the number of element int the heap.
  int count();
private:
};
```
