#include <iostream>

using namespace std;

class CustomHashMap {

    static const int SIZE = 256;
    int precedence[SIZE];

public:
    CustomHashMap() {
        for (int i = 0; i < SIZE; i++) {
            precedence[i] = -1;
        }
    }

    void setPrecedence(char key, int value) {
        precedence[key] = value;
    }

    int getPrecedence(char key) {
        return precedence[key];
    }

};

int partition(char arr[], int low, int high, char pivot, CustomHashMap &hashMap) {
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (hashMap.getPrecedence(arr[j]) < hashMap.getPrecedence(pivot)) {
            i++;
            swap(arr[i], arr[j]);
        } else if (hashMap.getPrecedence(arr[j]) == hashMap.getPrecedence(pivot)) {
            swap(arr[i + 1], arr[j]);
        }
    }

    return i + 1;
}

void matchNutsAndBolts(char nuts[], char bolts[], int low, int high, CustomHashMap &hashMap) {
    if (low < high) {
        char pivot = bolts[high];
        int partitionIndex = partition(nuts, low, high, pivot, hashMap);
        partition(bolts, low, high, nuts[partitionIndex], hashMap);
        matchNutsAndBolts(nuts, bolts, low, partitionIndex - 1, hashMap);
        matchNutsAndBolts(nuts, bolts, partitionIndex + 1, high, hashMap);
    }
}

int main() {
    int n;
    cout << "Enter the number of nuts and bolts: ";
    cin >> n;

    char nuts[n], bolts[n];

    cout << "Enter the nuts: ";
    for (int i = 0; i < n; i++) {
        cin >> nuts[i];
    }

    cout << "Enter the bolts: ";
    for (int i = 0; i < n; i++) {
        cin >> bolts[i];
    }

    CustomHashMap precedenceMap;

    precedenceMap.setPrecedence('#', 0);
    precedenceMap.setPrecedence('$', 1);
    precedenceMap.setPrecedence('%', 2);
    precedenceMap.setPrecedence('&', 3);
    precedenceMap.setPrecedence('*', 4);
    precedenceMap.setPrecedence('@', 5);
    precedenceMap.setPrecedence('^', 6);
    precedenceMap.setPrecedence('~', 7);

    matchNutsAndBolts(nuts, bolts, 0, n - 1, precedenceMap);

    cout << "Matched Nuts and Bolts: " << endl;
    for (int i = 0; i < n; i++) {
        cout << nuts[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << bolts[i] << " ";
    }
    cout << endl;

    return 0;
}

