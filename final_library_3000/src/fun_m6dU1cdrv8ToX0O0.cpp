#include "fun_m6dU1cdrv8ToX0O0.hpp"

int fun_m6dU1cdrv8ToX0O0() {
    // LeetCode Problem: Tag Validator

    // Solution class
    class Solution {

    public:
        bool isValid(string code) {
            auto i = 0;
            return validTag(code, &i) && i == code.length();
        }

    private:
        bool validTag(const string& s, int *i) {
            auto j = *i;
            auto tag = parseTagName(s, &j);
            if (tag.empty()) {
                return false;
            }
            parseContent(s, &j);
            auto k = j + tag.size() + 2; 
            if (k >= s.size() || s.substr(j, k + 1 - j) != "</" + tag + ">") {
                return false;
            }
            *i = k + 1;
            return true;
        }

        string parseTagName(const string& s, int *i) {
            if (s[*i] != '<') {
                return "";
            }
            auto j = s.find('>', *i);
            if (j == string::npos || j - 1 - *i < 1 || 9 < j - 1 - *i) {
                return "";
            }
            auto tag = s.substr(*i + 1, j - 1 - *i);
            for (const auto& c : tag) {
                if (c < 'A' || 'Z' < c) {
                    return "";
                }
            }
            *i = j + 1;
            return tag;
        }

        void parseContent(const string& s, int *i) {
            while (*i < s.size()) {
                if (!validText(s, i) && !validCData(s, i) && !validTag(s, i)) {
                    break;
                }
            }
        }

        bool validText(const string& s, int *i) {
            auto j = *i;
            *i = s.find("<", *i);
            return *i != j;
        }

        bool validCData(const string& s, int *i) {
            if (s.find("<![CDATA[", *i) != *i) {
                return false;
            }
            auto j = s.find("]]>", *i);
            if (j == string::npos) {
                return false;
            }
            *i = j + 3;
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.isValid(s);

        // Print result to prevent optimization
        cout << "fun_m6dU1cdrv8ToX0O0: Executed isValid() from Tag Validator" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_m6dU1cdrv8ToX0O0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
