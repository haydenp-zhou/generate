#include "fun_GYvpkVVQtpyLXCQF.hpp"

// Original algorithm: Dsu Union Rank
int fun_GYvpkVVQtpyLXCQF() {
    try {
        using std::cout;
        using std::endl;
        using std::vector;
        class dsu {
         private:
            vector<uint64_t> p;        ///< keeps track of the parent of ith element
            vector<uint64_t> depth;    ///< tracks the depth(rank) of i in the tree
            vector<uint64_t> setSize;  ///< size of each chunk(set)
         public:
            explicit dsu(uint64_t n) {
                p.assign(n, 0);
                depth.assign(n, 0);
                setSize.assign(n, 0);
                for (uint64_t i = 0; i < n; i++) {
                    p[i] = i;
                    depth[i] = 0;
                    setSize[i] = 1;
                }
            }
            uint64_t findSet(uint64_t i) {
                while (i != p[i]) {
                    i = p[i];
                }
                return i;
            }
            void unionSet(uint64_t i, uint64_t j) {
                if (isSame(i, j)) {
                    return;
                }
                uint64_t x = findSet(i);
                uint64_t y = findSet(j);
                if (depth[x] > depth[y]) {
                    std::swap(x, y);
                }
                p[x] = y;
                if (depth[x] == depth[y]) {
                    depth[y]++;
                }
                setSize[y] += setSize[x];
            }
            bool isSame(uint64_t i, uint64_t j) {
                if (findSet(i) == findSet(j)) {
                    return true;
                }
                return false;
            }
            vector<uint64_t> getParents(uint64_t i) {
                vector<uint64_t> ans;
                while (p[i] != i) {
                    ans.push_back(i);
                    i = p[i];
                }
                ans.push_back(i);
                return ans;
            }
        };
        static void test1() {
            /* checks the parents in the resultant structures */
            uint64_t n = 10;   ///< number of elements
            dsu d(n + 1);      ///< object of class disjoint sets
            d.unionSet(2, 1);  ///< performs union operation on 1 and 2
            d.unionSet(1, 4);
            d.unionSet(8, 1);
            d.unionSet(3, 5);
            d.unionSet(5, 6);
            d.unionSet(5, 7);
            d.unionSet(9, 10);
            d.unionSet(2, 10);
            vector<uint64_t> ans = {7, 5};
            for (uint64_t i = 0; i < ans.size(); i++) {
                assert(d.getParents(7).at(i) ==
                       ans[i]);  // makes sure algorithm works fine
            }
            cout << "1st test passed!" << endl;
        }
        static void test2() {
            uint64_t n = 10;   ///< number of elements
            dsu d(n + 1);      ///< object of class disjoint sets
            d.unionSet(2, 1);  /// performs union operation on 1 and 2
            d.unionSet(1, 4);
            d.unionSet(8, 1);
            d.unionSet(3, 5);
            d.unionSet(5, 6);
            d.unionSet(5, 7);
            d.unionSet(9, 10);
            d.unionSet(2, 10);
            vector<uint64_t> ans = {2, 1, 10};
            for (uint64_t i = 0; i < ans.size(); i++) {
                assert(d.getParents(2).at(i) ==
                       ans[i]);  /// makes sure algorithm works fine
            }
            cout << "2nd test passed!" << endl;
        }

                // Test the algorithm implementation
                cout << "Testing Dsu Union Rank..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_GYvpkVVQtpyLXCQF: Dsu Union Rank executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_GYvpkVVQtpyLXCQF: Exception - " << e.what() << endl;
        return 0;
    }
}
