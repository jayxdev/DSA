#include <iostream>
using namespace std;

class Heap {
private:
    int heap[50];

    int getParentIndex(int index) {
        return (index - 1) / 2;
    }

    int getLeftChildIndex(int index) {
        return (2 * index) + 1;
    }

    int getRightChildIndex(int index) {
        return (2 * index) + 2;
    }

    void heapifyUp(int index) {
        if (index == 0) {
            return;
        }

        int parentIndex = getParentIndex(index);
        if (heap[parentIndex] < heap[index]) {
            swap(heap[parentIndex], heap[index]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);

        if (leftChildIndex < 50 && heap[leftChildIndex] > heap[largest]) {
            largest = leftChildIndex;
        }

        if (rightChildIndex < 50 && heap[rightChildIndex] > heap[largest]) {
            largest = rightChildIndex;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
 static int index;
    void insert(int value) {
        heap[++index]=value;
        heapifyUp(index - 1);
    }

    int remove() {
        if (index==-1) {
            throw out_of_range("Heap is empty");
        }

        int root = heap[0];
        for (int i = 0; i < index; i++) {
            heap[i] = heap[i + 1];
        }
        index--;
        heapifyDown(0);

        return root;
    }

    void print() {
        for (int i = 0; i <= index; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int Heap::index = -1;
int main() {
    Heap heap;

    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(20);
    heap.insert(8);

    heap.print();

    cout << "Removed element: " << heap.remove() << endl;

    heap.print();

    return 0;
}