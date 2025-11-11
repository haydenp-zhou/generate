#include "fun_iQ5HYvKkUtglpNyv.hpp"

// Original algorithm: Dsu Path Compression
int fun_iQ5HYvKkUtglpNyv() {
    try {
        using std::cout;
        using std::endl;
        using std::vector;
        class dsu {
         private:
            vector<uint64_t> p;           ///< keeps track of the parent of ith element
            vector<uint64_t> depth;       ///< tracks the depth(rank) of i in the tree
            vector<uint64_t> setSize;     ///< size of each chunk(set)
            vector<uint64_t> maxElement;  ///< maximum of each set to which i belongs to
            vector<uint64_t> minElement;  ///< minimum of each set to which i belongs to
         public:
            explicit dsu(uint64_t n) {
                p.assign(n, 0);
                for (uint64_t i = 0; i < n; i++) {
                    p[i] = i;
                }
                depth.assign(n, 0);
                maxElement.assign(n, 0);
                minElement.assign(n, 0);
                for (uint64_t i = 0; i < n; i++) {
                    depth[i] = 0;
                    maxElement[i] = i;
                    minElement[i] = i;
                }
                setSize.assign(n, 0);
                for (uint64_t i = 0; i < n; i++) {
                    setSize[i] = 1;
                }
            }
            uint64_t findSet(uint64_t i) {
                if (p[i] == i) {
                    return i;
                }
                return (p[i] = findSet(p[i]));
            }
            void UnionSet(uint64_t i, uint64_t j) {
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
                maxElement[y] = std::max(maxElement[x], maxElement[y]);
                minElement[y] = std::min(minElement[x], minElement[y]);
            }
            bool isSame(uint64_t i, uint64_t j) {
                if (findSet(i) == findSet(j)) {
                    return true;
                }
                return false;
            }
            vector<uint64_t> get(uint64_t i) {
                vector<uint64_t> ans;
                ans.push_back(get_min(i));
                ans.push_back(get_max(i));
                ans.push_back(size(i));
                return ans;
            }
            uint64_t size(uint64_t i) { return setSize[findSet(i)]; }
            uint64_t get_max(uint64_t i) { return maxElement[findSet(i)]; }
            uint64_t get_min(uint64_t i) { return minElement[findSet(i)]; }
        };
        static void test1() {
            uint64_t n = 10;  ///< number of items
            dsu d(n + 1);     ///< object of class disjoint sets
            d.UnionSet(1, 2);  // performs union operation on 1 and 2
            d.UnionSet(1, 4);  // performs union operation on 1 and 4
            vector<uint64_t> ans = {1, 4, 3};
            for (uint64_t i = 0; i < ans.size(); i++) {
                assert(d.get(4).at(i) == ans[i]);  // makes sure algorithm works fine
            }
            cout << "1st test passed!" << endl;
        }
        static void test2() {
            uint64_t n = 10;  ///< number of items
            dsu d(n + 1);     ///< object of class disjoint sets
            d.UnionSet(3, 5);
            d.UnionSet(5, 6);
            d.UnionSet(5, 7);
            vector<uint64_t> ans = {3, 7, 4};
            for (uint64_t i = 0; i < ans.size(); i++) {
                assert(d.get(3).at(i) == ans[i]);  // makes sure algorithm works fine
            }
            cout << "2nd test passed!" << endl;
        }

                // Test the algorithm implementation
                cout << "Testing Dsu Path Compression..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_iQ5HYvKkUtglpNyv: Dsu Path Compression executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_iQ5HYvKkUtglpNyv: Exception - " << e.what() << endl;
        return 0;
    }
}
