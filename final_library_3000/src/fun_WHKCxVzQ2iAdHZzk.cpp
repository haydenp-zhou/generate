#include "fun_WHKCxVzQ2iAdHZzk.hpp"

int fun_WHKCxVzQ2iAdHZzk() {
    // LeetCode Problem: Day Of The Year

    // Solution class
    class Solution {

    public:
        Solution() : lookup_(12) {
            for (int M = 1; M < lookup_.size(); ++M) {
                lookup_[M] = lookup_[M - 1] + dayOfMonth(M);
            }
        }

        int dayOfYear(string date) {   
            const auto& result = split(date, '-');
            const auto& Y = stoi(result[0]), &M = stoi(result[1]), &D = stoi(result[2]);
            const auto& leap = (M > 2 && (((Y % 4 == 0) && (Y % 100 != 0)) || (Y % 400 == 0))) ? 1 : 0;
            return lookup_[M - 1] + D + leap;
        }

    private:
        int dayOfMonth(int M) {
            return (M == 2) ? 28 : 31 - (M - 1) % 7 % 2;
        }

        vector<string> split(const string& s, const char delim) {
            vector<string> result;
            auto end = string::npos;
            do {
                const auto& start = end + 1;
                end = s.find(delim, start);
                result.emplace_back(s.substr(start, end - start));
            } while (end != string::npos); 
            return result;
        }

        vector<int> lookup_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.Solution(nums);

        // Print result to prevent optimization
        cout << "fun_WHKCxVzQ2iAdHZzk: Executed Solution() from Day Of The Year" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_WHKCxVzQ2iAdHZzk: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
