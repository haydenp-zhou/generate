#include "fun_EU2F51OOGeUL6Y95.hpp"

// Original algorithm: Hamiltons Cycle
int fun_EU2F51OOGeUL6Y95() {
    try {
        bool hamilton_cycle(const std::vector<std::vector<bool>> &routes) {
            const size_t n = routes.size();
            const size_t height = 1 << n;
            std::vector<std::vector<bool>> dp(height, std::vector<bool>(n, false));
            for (size_t i = 0; i < n; ++i) {
                dp[1 << i][i] = true;
            }
            for (size_t i = 1; i < height; i++) {
                std::vector<size_t> zeros, ones;
                for (size_t pos = 0; pos < n; ++pos) {
                    if ((1 << pos) & i) {
                        ones.push_back(pos);
                    } else {
                        zeros.push_back(pos);
                    }
                }
                for (auto &o : ones) {
                    if (!dp[i][o]) {
                        continue;
                    }
                    for (auto &z : zeros) {
                        if (!routes[o][z]) {
                            continue;
                        }
                        dp[i + (1 << z)][z] = true;
                    }
                }
            }
            bool is_cycle = false;
            for (size_t i = 0; i < n; i++) {
                is_cycle |= dp[height - 1][i];
                if (is_cycle) {  // if true, all subsequent loop will be true. hence
                    break;
                }
            }
            return is_cycle;
        }
        static void test1() {
            std::vector<std::vector<bool>> arr{
                std::vector<bool>({true, true, false, false}),
                std::vector<bool>({false, true, true, false}),
                std::vector<bool>({false, false, true, true}),
                std::vector<bool>({false, false, false, true})};
            bool ans = hamilton_cycle(arr);
            std::cout << "Test 1... ";
            assert(ans);
            std::cout << "passed\n";
        }
        static void test2() {
            std::vector<std::vector<bool>> arr{
                std::vector<bool>({true, true, false, false}),
                std::vector<bool>({false, true, true, true}),
                std::vector<bool>({false, false, true, false}),
                std::vector<bool>({false, false, false, true})};
            bool ans = hamilton_cycle(arr);
            std::cout << "Test 2... ";
            assert(!ans);  // not a cycle
            std::cout << "passed\n";
        }
        static void test3() {
            std::vector<std::vector<bool>> arr{
                std::vector<bool>({true, true, true, true}),
                std::vector<bool>({true, true, true, true}),
                std::vector<bool>({true, true, true, true}),
                std::vector<bool>({true, true, true, true})};
            bool ans = hamilton_cycle(arr);
            std::cout << "Test 3... ";
            assert(ans);
            std::cout << "passed\n";
        }


        volatile int status = 1;
        cout << "fun_EU2F51OOGeUL6Y95: Hamiltons Cycle executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_EU2F51OOGeUL6Y95: Exception - " << e.what() << endl;
        return 0;
    }
}
