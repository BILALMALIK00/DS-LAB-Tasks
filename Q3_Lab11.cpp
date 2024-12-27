#include <iostream>

using namespace std;

class HashMap {
    static const int TABLE_SIZE = 1000;
    int keys[TABLE_SIZE];
    int values[TABLE_SIZE];

public:
    HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            keys[i] = -1;
            values[i] = 0;
        }
    }

    int hashFunction(int key) {
        return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE; 
    }

    void insert(int key) {
        int index = hashFunction(key);
        while (keys[index] != -1 && keys[index] != key) {
            index = (index + 1) % TABLE_SIZE;
        }
        if (keys[index] == -1) {
            keys[index] = key;
        }
        values[index]++;
    }

    bool exists(int key) {
        int index = hashFunction(key);
        while (keys[index] != -1) {
            if (keys[index] == key) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        return false;
    }
};

int findTripletWithZeroSum(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        HashMap hashMap;
        for (int j = i + 1; j < size; j++) {
            int target = -(arr[i] + arr[j]);
            if (hashMap.exists(target)) {
                return 1;
            }
            hashMap.insert(arr[j]);
        }
    }
    return 0;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size < 3) {
        cout << "An array must have at least three elements to check for a triplet." << endl;
        return 0;
    }

    int arr[size];
    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    if (findTripletWithZeroSum(arr, size)) {
        cout << "The array contains a triplet with a sum of zero." << endl;
    } else {
        cout << "No triplet with a sum of zero was found in the array." << endl;
    }

    return 0;
}

