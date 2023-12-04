#include <vector>
#include <iostream>

using namespace std;

template<class T>
class MaxHeap {
public:
  MaxHeap() {}
  void insert(T value) {
    heap.push_back(value);
    heapifyUp();
  }

  T extract(){
    if (heap.empty()) {
      return T();
    }

    T root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown();
    return root;
  }

  int count() const {
    return heap.size();
  }

private:
  vector<T> heap;

  void heapifyUp() {
    int currentIndex = heap.size() - 1;

    while (currentIndex > 0) {
      int parentIndex = (currentIndex - 1) / 2;

      if (heap[currentIndex] > heap[parentIndex]) {
        swap(heap[currentIndex], heap[parentIndex]);
        currentIndex = parentIndex;
      } else {
        break;
      }
    }
  }

  void heapifyDown() {
    int currentIndex = 0;
    int size = heap.size();

    while (true) {
      int leftChildIndex = 2 * currentIndex + 1;
      int rightChildIndex = 2 * currentIndex + 2;
      int maxIndex = currentIndex;

      if (leftChildIndex < size && heap[leftChildIndex] > heap[maxIndex]) {
        maxIndex = leftChildIndex;
      }

      if (rightChildIndex < size && heap[rightChildIndex] > heap[maxIndex]) {
        maxIndex = rightChildIndex;
      }

      if (currentIndex != maxIndex) {
        swap(heap[currentIndex], heap[maxIndex]);
        currentIndex = maxIndex;
      } else {
        break;
      }
    }
  }
};

int main() {
    MaxHeap<int> maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(5);
    maxHeap.insert(20);
    maxHeap.insert(8);
    maxHeap.insert(15);

    cout << "Number of elements in the heap: " << maxHeap.count() << endl;

    cout << "Extracted elements in descending order:" << endl;
    while (maxHeap.count() > 0) {
        int extracted = maxHeap.extract();
        cout << extracted << " ";
    }
    cout << endl;

    return 0;
}
