#include "fun_tN9JH9HSUoiX7QDU.hpp"

int fun_tN9JH9HSUoiX7QDU() {
    // LeetCode Problem: Fruits Into Baskets Ii

    // Solution class
    class Solution {

    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int result = 0;
            SegmentTree st(baskets);
            for (const auto& x : fruits) {
                const int i = st.binary_search(x);
                if (i == -1) {
                    ++result;
                } else {
                    st.update(i, 0);
                }
            }
            return result;
        }

    private:
        class SegmentTree {
         public:
            explicit SegmentTree(const vector<int>& nums)
              : tree(size(nums) > 1 ? 1 << (__lg(size(nums) - 1) + 2) : 2),
                base(size(nums) > 1 ? 1 << (__lg(size(nums) - 1) + 1) : 1) {
                for (int i = base; i < size(tree); ++i) {
                    tree[i] = nums[i - base];
                }
                for (int i = base - 1; i >= 1; --i) {
                    tree[i] = max(tree[2 * i], tree[2 * i + 1]);
                }
            }

            void update(int i, int h) {
                int x = base + i;
                tree[x] = h;
                while (x > 1) {
                    x /= 2;
                    tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
                }
            }

            int binary_search(int x) {
                if (tree[1] < x) {
                    return -1;
                }
                int i = 1;
                while (!(i >= base)) {
                    if (tree[2 * i] >= x) {
                        i = 2 * i;
                    } else {
                        i = 2 * i + 1;
                    }
                }
                return i - base;
            }

            vector<int> tree;
            int base;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numOfUnplacedFruits(nums);

        // Print result to prevent optimization
        cout << "fun_tN9JH9HSUoiX7QDU: Executed numOfUnplacedFruits() from Fruits Into Baskets Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_tN9JH9HSUoiX7QDU: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
