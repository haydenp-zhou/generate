#include "fun_B4Wk4olR79U152fe.hpp"

int fun_B4Wk4olR79U152fe() {
    // LeetCode Problem: Similar String Groups

    // Solution class
    class Solution {

    public:
        int numSimilarGroups(vector<string>& A) {
            UnionFind union_find(A.size());
            for (int i = 0; i < A.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    if (isSimilar(A[i], A[j])) {
                        union_find.union_set(i, j);
                    }
                }
            }
            return union_find.size();
        }

    private:
        bool isSimilar(const string& a, const string& b) {
            int diff = 0;
            for (int i = 0; i < a.length(); ++i) {
                if (a[i] != b[i]) {
                    if (++diff > 2) {
                        return false;
                    }
                }
            }
            return diff == 2;
        }

        class UnionFind {
            public:
                UnionFind(const int n) : set_(n), size_(n) {
                    iota(set_.begin(), set_.end(), 0);
                }

                int find_set(const int x) {
                   if (set_[x] != x) {
                       set_[x] = find_set(set_[x]);  // Path compression.
                   }
                   return set_[x];
                }

                bool union_set(const int x, const int y) {
                    int x_root = find_set(x), y_root = find_set(y);
                    if (x_root == y_root) {
                        return false;
                    }
                    set_[min(x_root, y_root)] = max(x_root, y_root);
                    --size_;
                    return true;
                }

                int size() const {
                    return size_;
                }

            private:
                vector<int> set_;
                int size_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numSimilarGroups(nums);

        // Print result to prevent optimization
        cout << "fun_B4Wk4olR79U152fe: Executed numSimilarGroups() from Similar String Groups" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_B4Wk4olR79U152fe: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
