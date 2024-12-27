#include<iostream>

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
        return key % TABLE_SIZE;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        while (keys[index] != -1 && keys[index] != key) {
            index = (index + 1) % TABLE_SIZE;
        }
        if (keys[index] == -1) {
            keys[index] = key;
        }
        values[index] += value;
    }

    int getValue(int key) {
        int index = hashFunction(key);
        while (keys[index] != -1) {
            if (keys[index] == key) {
                return values[index];
            }
            index = (index + 1) % TABLE_SIZE;
        }
        return 0;
    }
};

int countPairsWithSum(int array[], int size, int targetSum) {
    HashMap hashMap;
    int pairCount = 0;

    for (int i = 0; i < size; i++) {
        int complement = targetSum - array[i];
        pairCount += hashMap.getValue(complement);
        hashMap.insert(array[i], 1);
    }

    return pairCount;
}

int main() {
    int size, targetSum;
    cout << "Enter the size of the array: ";
    cin >> size;

    int array[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    cout << "Number of pairs with sum " << targetSum << ": " << countPairsWithSum(array, size, targetSum) << endl;

    return 0;
}

