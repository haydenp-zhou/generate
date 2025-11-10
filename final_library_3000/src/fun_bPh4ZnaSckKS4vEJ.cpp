#include "fun_bPh4ZnaSckKS4vEJ.hpp"

int fun_bPh4ZnaSckKS4vEJ() {
    // LeetCode Problem: Minimum Number Of People To Teach

    // Solution class
    class Solution {

    public:
        int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
            vector<unordered_set<int>> language_sets;
            for (const auto& language : languages) {
                language_sets.emplace_back(cbegin(language), cend(language));
            }
            unordered_set<int> candidates;
            for (const auto& f : friendships) {
                if (empty(intersect(language_sets[f[0] - 1], language_sets[f[1] - 1]))) {
                    candidates.emplace(f[0] - 1);
                    candidates.emplace(f[1] - 1);
                }
            }
            vector<int> count(n);
            for (const auto& i : candidates) {
                for (const auto& l : language_sets[i]) {
                    ++count[l - 1];
                }
            }
            return size(candidates) - *max_element(cbegin(count), cend(count));
        }

    private:
        unordered_set<int> intersect(const unordered_set<int>& a, const unordered_set<int>& b) {
            if (size(a) > size(b)) {
                return intersect(b, a);
            }
            unordered_set<int> result;
            for (const auto& x : a) {
                if (b.count(x)) {
                    result.emplace(x);
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minimumTeachings(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_bPh4ZnaSckKS4vEJ: Executed minimumTeachings() from Minimum Number Of People To Teach" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_bPh4ZnaSckKS4vEJ: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
