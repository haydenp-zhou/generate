#include "fun_MzIYfdi1lQcaxoIE.hpp"

int fun_MzIYfdi1lQcaxoIE() {
    // LeetCode Problem: Subarrays Distinct Element Sum Of Squares I

    // Solution class
    class Solution {

    public:
        int sumCounts(vector<int>& nums) {
            static const int MOD = 1e9 + 7;

            using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
            ordered_set os;
            unordered_map<int, vector<int>> idxs;
            for (int i = size(nums) - 1; i >= 0; --i) {
                idxs[nums[i]].emplace_back(i);
            }
            for (const auto& [_, v] : idxs) {
                os.insert(v.back());
            }
            int result = 0;
            int accu = ((static_cast<int64_t>(size(nums)) * size(os)) % MOD) * size(os) % MOD;
            for (int i = 0; i < size(os); ++i) {
                accu = ((accu - (static_cast<int64_t>(2 * i + 1) * *os.find_by_order(i) % MOD)) % MOD + MOD) % MOD;
            }
            BIT bit(size(nums));
            for (const auto& x : os) {
                bit.add(x, x);
            }

            const auto& update = [&](int x, int accu, int d) {
                const int i = os.order_of_key(idxs[x].back());
                accu = ((accu + d * (static_cast<int64_t>(size(nums)) * (2 * static_cast<int>(size(os)) - 1)
                                     - static_cast<int64_t>(2 * i + 1) * idxs[x].back()
                                     - 2ll * (bit.query(size(nums) - 1) - bit.query(idxs[x].back())))) % MOD + MOD) % MOD;
                bit.add(idxs[x].back(), d * idxs[x].back());
                return accu;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.sumCounts(nums);

        // Print result to prevent optimization
        cout << "fun_MzIYfdi1lQcaxoIE: Executed sumCounts() from Subarrays Distinct Element Sum Of Squares I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_MzIYfdi1lQcaxoIE: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
