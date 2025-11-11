#include "fun_GtFJsCNPdVvE3WOA.hpp"

// Original algorithm: Tree Height
int fun_GtFJsCNPdVvE3WOA() {
    try {
        /*
         * Given a rooted tree with node 1.
         * Task is to find the height of the tree.
         * Example: -
         * 4
         * 1 2
         * 1 3
         * 2 4
         * which can be represented as
         *   1
         *  / \
         * 2   3
         * |
         * 4
         *
         * Height of the tree : - 2
         */
        const int MAX = 1e5;
        std::vector<int> adj[MAX];
        std::vector<bool> visited;
        std::vector<int> dp;
        void depth_first_search(int u) {
            visited[u] = true;
            int child_height = 1;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    depth_first_search(v);
                    child_height = std::max(child_height, dp[v] + 1);
                }
            }
            dp[u] = child_height;
        }
            visited.assign(number_of_nodes + 1, false);
            dp.assign(number_of_nodes + 1, 0);
            depth_first_search(1);
            std::cout << "Height of the Tree : " << dp[1] << std::endl;
        }


        volatile int status = 1;
        cout << "fun_GtFJsCNPdVvE3WOA: Tree Height executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_GtFJsCNPdVvE3WOA: Exception - " << e.what() << endl;
        return 0;
    }
}
