#include <iostream>
using namespace std;

int getmax(int *arr, int n) {
    int maxi = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    return maxi;
}

int* countSort(int *arr, int n, int exp) {
    int countarr[10] = {0};
    int *temp_arr = new int[n]; 

    for (int i = 0; i < n; i++) {
        countarr[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        countarr[i] += countarr[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        temp_arr[countarr[(arr[i] / exp) % 10] - 1] = arr[i];
        countarr[(arr[i] / exp) % 10]--;
    }
    return temp_arr; 
}

int* radix_sort_ascending(int *arr, int n) {
    int max = getmax(arr, n);
    int *sorted_arr = arr; 
    for (int exp = 1; max / exp > 0; exp *= 10) {
        sorted_arr = countSort(sorted_arr, n, exp); 
    }
    return sorted_arr; 
}

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* count_sort_descending(int *arr, int n, int exp) {
    int countarr[10] = {0};  
    int *temp_arr = new int[n]; 
    for (int i = 0; i < n; i++) {
        countarr[(arr[i] / exp) % 10]++;
    }
    for (int i = 8; i >= 0; i--) {
        countarr[i] += countarr[i + 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        temp_arr[countarr[(arr[i] / exp) % 10] - 1] = arr[i];
        countarr[(arr[i] / exp) % 10]--;
    }

    return temp_arr;
}

int* radix_sort_descending(int *arr, int n) {
    int max = getmax(arr, n);
    int *sorted_arr = arr; 
    for (int exp = 1; max / exp > 0; exp *= 10) {
        sorted_arr = count_sort_descending(sorted_arr, n, exp); 
    }
    return sorted_arr; 
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Original: ";
    display(arr, n);

    int *sorted_asc = radix_sort_ascending(arr, n); 
    cout << "Sorted in Ascending: ";
    display(sorted_asc, n);

    int *sorted_desc = radix_sort_descending(arr, n); 
    cout << "Sorted in Descending: ";
    display(sorted_desc, n);

    delete[] arr;
    delete[] sorted_asc; 
    delete[] sorted_desc; 
}

