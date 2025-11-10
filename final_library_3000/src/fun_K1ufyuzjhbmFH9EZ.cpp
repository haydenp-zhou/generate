#include "fun_K1ufyuzjhbmFH9EZ.hpp"

int fun_K1ufyuzjhbmFH9EZ() {
    // LeetCode Problem: Minimum Deletions To Make String K Special

    // Solution class
    class Solution {

    public:
        int minimumDeletions(string word, int k) {
            vector<int> cnt(26);
            for (const auto& x : word) {
                ++cnt[x - 'a'];
            }
            vector<int> arr;
            for (const auto& x : cnt) {
                if (!x) {
                    continue;
                }
                arr.emplace_back(x);
            }
            arr = counting_sort(arr, [](const auto& x) { return x; }, false);
            int result = size(word);
            for (int left = 0, right = 0, prev = -1, prefix = 0, suffix = size(word); left < size(arr); ++left) {
                if (left + 1 < size(arr) && arr[left + 1] == arr[left]) {
                    continue;
                }
                while (right < size(arr) && arr[right] <= arr[left] + k) {
                    suffix -= arr[right++];
                }
                result = min(result, prefix + (suffix - (arr[left] + k) * (static_cast<int>(size(arr)) - right)));
                prefix += arr[left] * (left - prev);
                prev = left;
            }
            return result;
        }

    private:
        vector<int> counting_sort(const vector<int>& arr, const function<int(int)>& key, bool is_reverse) {
            vector<int> count(*max_element(cbegin(arr), cend(arr), [&](const auto& x, const auto& y) {
                return key(x) < key(y);
            }) + 1);
            for (const auto& x : arr) {
                ++count[key(x)];
            }
            for (int i = 1; i < size(count); ++i) {
                count[i] += count[i - 1];
            }
            vector<int> result(size(arr));
            if (!is_reverse) {
                for (int i = size(arr) - 1; i >= 0; --i) {  // stable sort
                    result[--count[key(arr[i])]] = arr[i];
                }
            } else {
                for (const auto& x : arr) {  // stable sort
                    result[--count[key(x)]] = x;
                }
                reverse(begin(result), end(result));
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minimumDeletions(nums);

        // Print result to prevent optimization
        cout << "fun_K1ufyuzjhbmFH9EZ: Executed minimumDeletions() from Minimum Deletions To Make String K Special" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_K1ufyuzjhbmFH9EZ: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
