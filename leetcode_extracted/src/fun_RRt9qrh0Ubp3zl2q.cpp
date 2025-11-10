#include "fun_RRt9qrh0Ubp3zl2q.hpp"

int fun_RRt9qrh0Ubp3zl2q() {
    // LeetCode Problem: Reorganize String

    // Solution class
    class Solution {

    public:
        string reorganizeString(string S) {
            unordered_map<char, int> counts;
            for (const auto& c : S) {
                ++counts[c];
            }
            if (any_of(counts.cbegin(), counts.cend(),
                      [&](const pair<char, int>& kvp) { 
                          return kvp.second > (S.length() + 1) / 2;
                      })) {
                return "";
            }

            string result;
            priority_queue<pair<int, char>> max_heap;
            for (const auto& kvp : counts) {
                max_heap.emplace(kvp.second, kvp.first);
            }
            while (max_heap.size() > 1) {
                char c1, c2;
                int count1, count2;
                tie(count1, c1) = max_heap.top(); max_heap.pop();
                tie(count2, c2) = max_heap.top(); max_heap.pop();
                if (result.empty() || c1 != result.back()) {
                    result.push_back(c1);
                    result.push_back(c2);
                    if (count1 - 1 > 0) {
                        max_heap.emplace(count1 - 1, c1);
                    }
                    if (count2 - 1 > 0) {
                        max_heap.emplace(count2 - 1, c2);
                    }
                }
            }
            return max_heap.empty() ? result : result + max_heap.top().second;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.reorganizeString(s);

        // Print result to prevent optimization
        cout << "fun_RRt9qrh0Ubp3zl2q: Executed reorganizeString() from Reorganize String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_RRt9qrh0Ubp3zl2q: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
