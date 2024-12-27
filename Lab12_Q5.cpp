#include <iostream>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 256;

void buildBadCharacterTable(const string& pattern, int badCharTable[]) {
    int m = pattern.length();
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        badCharTable[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        badCharTable[(int)pattern[i]] = i;
    }
}

void searchPatterns(const string& text, string patterns[], int numPatterns) {
    int textLength = text.length();
    
    for (int p = 0; p < numPatterns; ++p) {
        string pattern = patterns[p];
        int m = pattern.length();
        int badCharTable[ALPHABET_SIZE];
        buildBadCharacterTable(pattern, badCharTable);

        int i = 0;
        while (i <= textLength - m) {
            int j = m - 1;
            while (j >= 0 && pattern[j] == text[i + j]) {
                j--;
            }
            if (j < 0) {
                cout << "Pattern \"" << pattern << "\" found at index " << i << endl;
                i += (i + m < textLength) ? m - badCharTable[(int)text[i + m]] : 1;
            } else {
                i += max(1, j - badCharTable[(int)text[i + j]]);
            }
        }
    }
}

int main() {
    string text = "ABCDEFG";
    string patterns[] = {"ABC", "EFG"};
    int numPatterns = 2;
    searchPatterns(text, patterns, numPatterns);
    return 0;
}

