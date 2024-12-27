#include <iostream>
#include <string>
using namespace std;

const int BASE = 257; 
const int MOD = 1000000007;  

long long computeHash(const string& s, int start, int length) {
    long long hashValue = 0;
    for (int i = start; i < start + length; ++i) {
        hashValue = (hashValue * BASE + s[i]) % MOD;
    }
    return hashValue;
}

long long computeReverseHash(const string& s, int start, int length) {
    long long reverseHash = 0;
    for (int i = start + length - 1; i >= start; --i) {
        reverseHash = (reverseHash * BASE + s[i]) % MOD;
    }
    return reverseHash;
}

void findPalindromes(const string& s) {
    int n = s.length();

    for (int len = 2; len <= n; ++len) {  
        for (int i = 0; i <= n - len; ++i) {
            int end = i + len - 1;

            long long forwardHash = computeHash(s, i, len);
            long long reverseHash = computeReverseHash(s, i, len);

            if (forwardHash == reverseHash) { 
                bool isPalindrome = true;
                int left = i, right = end;
                while (left < right) {
                    if (s[left] != s[right]) {
                        isPalindrome = false;
                        break;
                    }
                    left++;
                    right--;
                }
                if (isPalindrome) {
                    cout << "Palindrome: " << s.substr(i, len) << endl;
                }
            }
        }
    }
}

int main() {
    string text = "ABCBAB";
    findPalindromes(text);
    return 0;
}

