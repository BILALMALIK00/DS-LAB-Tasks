#include <iostream>
using namespace std;

class HeapOperations {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void minHeapify(int arr[], int size, int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            minHeapify(arr, size, smallest);
        }
    }

    void createMinHeap(int arr[], int size) {
        for (int i = size / 2 - 1; i >= 0; i--)
            minHeapify(arr, size, i);
    }

    void maxHeapify(int arr[], int size, int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            maxHeapify(arr, size, largest);
        }
    }

    void createMaxHeap(int arr[], int size) {
        for (int i = size / 2 - 1; i >= 0; i--)
            maxHeapify(arr, size, i);
    }

    void deleteRoot(int arr[], int &size) {
       if (size <= 0) {
            cout << "Heap is empty Cannot delete root" << endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        minHeapify(arr, size, 0);
    }

    void sortHeap(int arr[], int size) {
        createMaxHeap(arr, size);
        for (int i = size - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            maxHeapify(arr, i, 0);
        }
    }

    void display(int arr[], int size) {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int tree[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int size = sizeof(tree) / sizeof(tree[0]);

    HeapOperations heapOps;
    heapOps.createMinHeap(tree, size);
    cout << "Min Heap: ";
    heapOps.display(tree, size);
    heapOps.deleteRoot(tree, size);
    cout << "After deleting root: ";
    heapOps.display(tree, size);

    heapOps.createMaxHeap(tree, size);
    cout << "Max Heap: ";
    heapOps.display(tree, size);

    heapOps.sortHeap(tree, size);
    cout << "Sorted Output: ";
    heapOps.display(tree, size);
    return 0;
}

