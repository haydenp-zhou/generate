#include "fun_OOYOU3SxfXnyYQXY.hpp"

int fun_OOYOU3SxfXnyYQXY() {
    // AI-Generated: Palindrome Check

    // Palindrome checking
    vector<string> testStrings = {
        "racecar", "hello", "madam", "world", "noon",
        "python", "level", "algorithm", "radar", "programming"
    };

    auto isPalindrome = [](const string& s) -> bool {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    };

    int palindromeCount = 0;
    vector<string> palindromes;

    for (const string& s : testStrings) {
        if (isPalindrome(s)) {
            palindromeCount++;
            palindromes.push_back(s);
        }
    }

    volatile int count = palindromeCount;
    cout << func_name << ": Found " << count << " palindromes" << endl;
    cout << "Palindromes: ";
    for (const string& p : palindromes) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
