#include "fun_gdPLLSKo0E8xRGn2.hpp"

int fun_gdPLLSKo0E8xRGn2() {
    // LeetCode Problem: Maximum Font To Fit A Sentence In A Screen

    // Solution class
    class Solution {

    public:
        int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
            vector<int> count(26);
            for (const auto& c : text) {
                ++count[c - 'a'];
            }
            int left = 0, right = size(fonts) - 1;
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (!check(count, w, h, fonts, fontInfo, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right >= 0 ? fonts[right] : -1;
        }

    private:
        bool check(const vector<int>& count, int w, int h, const vector<int>& fonts, FontInfo& fontInfo, int x) {
            if (fontInfo.getHeight(fonts[x]) > h) {
                return false;
            }
            int width = 0;
            for (int c = 0; c < size(count); ++c) {
                width += count[c] * fontInfo.getWidth(fonts[x], 'a' + c);
                if (width > w) {
                    return false;
                }
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.maxFont(nums);

        // Print result to prevent optimization
        cout << "fun_gdPLLSKo0E8xRGn2: Executed maxFont() from Maximum Font To Fit A Sentence In A Screen" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_gdPLLSKo0E8xRGn2: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
