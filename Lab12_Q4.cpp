#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void toLowerCase(string& str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
}

void computeLPSArray(const string& pattern, int* lps) {
    int m = pattern.length();
    int length = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string& text, const string& pattern) {
    string textLower = text;
    string patternLower = pattern;

    toLowerCase(textLower);
    toLowerCase(patternLower);

    int n = textLower.length();
    int m = patternLower.length();
    
    int lps[m];
    computeLPSArray(patternLower, lps);

    int i = 0;  
    int j = 0;  
    while (i < n) {
        if (patternLower[j] == textLower[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && patternLower[j] != textLower[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "Data Structures";
    string pattern = "data";

    KMPSearch(text, pattern);

    return 0;
}

