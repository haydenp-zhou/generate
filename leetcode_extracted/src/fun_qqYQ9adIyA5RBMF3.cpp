#include "fun_qqYQ9adIyA5RBMF3.hpp"

int fun_qqYQ9adIyA5RBMF3() {
    // LeetCode Problem: Subarrays With Xor At Least K

    // Solution class
    class Solution {

    private:
        class Trie {
        public:
            Trie(int bit_length)
             : bit_length_(bit_length)
             , nodes_() {
                 new_node();
             }

            void add(int num) {
                int curr = 0;
                for (int i = bit_length_ - 1; i >= 0; --i) {
                    const auto& x = (num >> i) & 1;
                    if (nodes_[curr][x] == -1) {
                        nodes_[curr][x] = new_node();
                    }
                    curr = nodes_[curr][x];
                    ++cnts_[curr];
                }
            }

            int query(int prefix, int k) {
                int result = 0, curr = 0;
                for (int i = bit_length_ - 1; i >= 0 && curr != -1; --i) {
                    const auto& t = (k >> i) & 1;
                    const auto& x = (prefix >> i) & 1;
                    if (t == 0) {
                        const auto& tmp = nodes_[curr][1 ^ x];
                        if (tmp != -1) {
                            result += cnts_[tmp];
                        }
                    }
                    curr = nodes_[curr][t ^ x];
                }
                if (curr != -1) {
                    result += cnts_[curr];
                }
                return result;
            }

        private:
            int new_node() {
                nodes_.push_back(array<int, 2>{-1, -1});
                cnts_.emplace_back(0);
                return size(nodes_) - 1;
            }

            const int bit_length_;
            vector<array<int, 2>> nodes_;
            vector<int> cnts_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.Trie(nums);

        // Print result to prevent optimization
        cout << "fun_qqYQ9adIyA5RBMF3: Executed Trie() from Subarrays With Xor At Least K" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_qqYQ9adIyA5RBMF3: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
