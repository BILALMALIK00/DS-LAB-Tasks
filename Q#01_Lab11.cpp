#include<iostream>

using namespace std;

class Entry {
public:
    int key;
    int value;
    Entry* next;

    Entry(int key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashMap {
public:
    int capacity;
    Entry** buckets;
    int itemCount;

    HashMap(int size = 10) {
        capacity = size;
        itemCount = 0;
        buckets = new Entry*[capacity];
        for (int i = 0; i < capacity; i++) {
            buckets[i] = nullptr;
        }
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    double loadFactor() {
        return 1.0 * itemCount / capacity;
    }

    void resize(int newSize) {
        Entry** newBuckets = new Entry*[newSize];
        for (int i = 0; i < newSize; i++) {
            newBuckets[i] = nullptr;
        }

        for (int i = 0; i < capacity; i++) {
            Entry* current = buckets[i];
            while (current != nullptr) {
                int newHash = current->key % newSize;
                Entry* next = current->next;
                current->next = newBuckets[newHash];
                newBuckets[newHash] = current;
                current = next;
            }
        }

        delete[] buckets;
        buckets = newBuckets;
        capacity = newSize;
    }

    void insert(int key, int value) {
        if (loadFactor() >= 0.7) {
            resize(capacity * 2);
        }

        int index = hashFunction(key);
        Entry* newEntry = new Entry(key, value);
        newEntry->next = buckets[index];
        buckets[index] = newEntry;
        itemCount++;
    }

    Entry* search(int key) {
        int index = hashFunction(key);
        Entry* current = buckets[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Entry* current = buckets[index];
        Entry* previous = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (previous != nullptr) {
                    previous->next = current->next;
                } else {
                    buckets[index] = current->next;
                }
                delete current;
                itemCount--;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            Entry* current = buckets[i];
            if (current != nullptr) {
                cout << "Bucket " << i << ": ";
                while (current != nullptr) {
                    cout << "(" << current->key << ", " << current->value << ") ";
                    current = current->next;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HashMap hashMap(5);

    hashMap.insert(20, 100);
    hashMap.insert(34, 200);
    hashMap.insert(45, 300);
    hashMap.insert(70, 400);
    hashMap.insert(56, 500);

    hashMap.display();

    cout << "Search 34: " << (hashMap.search(34) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (hashMap.search(100) ? "Found" : "Not Found") << endl;

    hashMap.remove(34);

    cout << "Search 34 after removal: " << (hashMap.search(34) ? "Found" : "Not Found") << endl;

    hashMap.display();

    return 0;
}

