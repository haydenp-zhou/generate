#include "fun_ioFsYYOwQfw7c7YU.hpp"

int fun_ioFsYYOwQfw7c7YU() {
    // LeetCode Problem: Sum Of Number And Its Reverse

    // Solution class
    class Solution {

    public:
        bool sumOfNumberAndReverse(int num) {
            const function<int(int, int)> backtracking = [&](int num, int chosen) {
                if (num == 0) {
                    return true;
                }
                if (chosen == 1) {
                    return false;
                }
                if (num <= 18) {
                    return (num % 2 == 0) || (num == 11 && chosen == 0);
                }
                if (chosen == 2) {
                    return false;
                }
                for (const auto& x : {num % 10, 10 + num % 10}) {
                    if (!(1 <= x && x <= 18)) {
                        continue;
                    }
                    int base = 11;
                    if (chosen) {
                        base = chosen;
                    } else {
                        for (; x * ((base - 1) * 10 + 1) <= num; base = (base - 1) * 10 + 1);
                    }
                    if (num - x * base >= 0 && backtracking((num - x * base) / 10, base / 100 + 1)) {
                        return true;
                    }
                }
                return false;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.sumOfNumberAndReverse(n);

        // Print result to prevent optimization
        cout << "fun_ioFsYYOwQfw7c7YU: Executed sumOfNumberAndReverse() from Sum Of Number And Its Reverse" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ioFsYYOwQfw7c7YU: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
