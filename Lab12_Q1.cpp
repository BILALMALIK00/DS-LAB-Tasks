#include <iostream>
#include <string>
using namespace std;

void searchPattern(const string& text, const string& pattern, int* matchIndices, int& matchCount) {
    int textSize = text.length();
    int patternSize = pattern.length();
    matchCount = 0;
    for (int textIndex = 0; textIndex <= textSize - patternSize; ++textIndex) {
        bool isMatch = true;
        for (int patternIndex = 0; patternIndex < patternSize; ++patternIndex) {
            if (text[textIndex + patternIndex] != pattern[patternIndex]) {
                isMatch = false;
                break;
            }
        }
        if (isMatch) {
            matchIndices[matchCount++] = textIndex;
        }
    }
}

int main() {
    string text = "ABABABA";
    string pattern = "ABA";
    const int maxMatches = 100;
    int matchIndices[maxMatches];
    int matchCount = 0;

    searchPattern(text, pattern, matchIndices, matchCount);

    if (matchCount > 0) {
        cout << "Pattern found at indices: ";
        for (int i = 0; i < matchCount; ++i) {
            cout << matchIndices[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}

