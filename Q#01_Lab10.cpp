#include <iostream>
using namespace std;
class Heap {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void minHeapify(int arr[], int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest]) {
            smallest = left;
        }

        if (right < n && arr[right] < arr[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(arr, n, smallest);
        }
    }

    void buildMinHeap(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            minHeapify(arr, n, i);
        }
    }

    void maxHeapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

    void buildMaxHeap(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(arr, n, i);
        }
    }

    void printHeap(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int tree[] = {7, 1, 6, 2, 5, 9, 10, 2};
    int n = sizeof(tree) / sizeof(tree[0]);

    Heap heap1; 

    int minHeap[n];
    for (int i = 0; i < n; i++) {
        minHeap[i] = tree[i];
    }
    heap1.buildMinHeap(minHeap, n);
    cout << "Min Heap: ";
    heap1.printHeap(minHeap, n);

    int maxHeap[n];
    for (int i = 0; i < n; i++) {
        maxHeap[i] = tree[i];
    }
    heap1.buildMaxHeap(maxHeap, n);
    cout << "Max Heap: ";
    heap1.printHeap(maxHeap, n);

    return 0;
}

