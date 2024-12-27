#include <iostream>
using namespace std;

void mergeindescending(int *arr, int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    int k = s;
    int i = 0, j = 0;

    for (int i = 0; i < len1; i++) {
        arr1[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        arr2[i] = arr[k++];
    }
    
    i = 0, j = 0, k = s;
    while (i < len1 && j < len2) {
        if (arr1[i] > arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }
    while (i < len1) {
        arr[k++] = arr1[i++];
    }
    while (j < len2) {
        arr[k++] = arr2[j++];
    }
    delete[] arr1;
    delete[] arr2;
}

void mergeinascending(int *arr, int s, int e) {
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    int k = s;
    int i = 0, j = 0;

    for (int i = 0; i < len1; i++) {
        arr1[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        arr2[i] = arr[k++];
    }
    
    i = 0, j = 0, k = s;
    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }
    while (i < len1) {
        arr[k++] = arr1[i++];
    }
    while (j < len2) {
        arr[k++] = arr2[j++];
    }
    delete[] arr1;
    delete[] arr2;
}

void merge_sortinascending(int *arr, int s, int e) {
    if (s >= e) {
        return;
    }
    int mid = (s + e) / 2;
    merge_sortinascending(arr, s, mid);
    merge_sortinascending(arr, mid + 1, e);
    mergeinascending(arr, s, e);
}

void merge_sortindescending(int *arr, int s, int e) {
    if (s >= e) {
        return;
    }
    int mid = (s + e) / 2;
    merge_sortindescending(arr, s, mid);
    merge_sortindescending(arr, mid + 1, e);
    mergeindescending(arr, s, e);
}

int* getsortedarray(int* arr, int n) {
    int* sortedarray = new int[n];
    for (int i = 0; i < n; i++) {
        sortedarray[i] = arr[i]; 
    }
    merge_sortinascending(sortedarray, 0, n - 1); 
    return sortedarray;
}
int* getsortedindesceding(int* arr, int n) {
    int* sortedarray = new int[n];
    for (int i = 0; i < n; i++) {
        sortedarray[i] = arr[i]; 
    }
    merge_sortindescending(sortedarray, 0, n - 1); 
    return sortedarray;
}

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter Size :";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original: ";
    display(arr, n);
    int* sortedinascending = getsortedarray(arr, n);
    cout << "Sorted in Ascending Order: ";
    display(sortedinascending, n);
    merge_sortindescending(arr, 0, n - 1);
    cout << "Sorted in Descending Order: ";
    int *sortedindescending=getsortedindesceding(arr,n);
    display(sortedindescending, n);
    delete[] arr;
    delete[] sortedinascending;
    delete[] sortedindescending;
}

