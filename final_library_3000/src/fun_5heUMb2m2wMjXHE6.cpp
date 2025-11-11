#include "fun_5heUMb2m2wMjXHE6.hpp"

// Original algorithm: Heavy Light Decomposition
int fun_5heUMb2m2wMjXHE6() {
    try {
        namespace heavy_light_decomposition {
        template <typename X>
        class Tree {
         private:
            std::vector<std::list<int>>
                t_adj;          ///< an adjacency list to stores the tree edges
            const int t_nodes,  ///< number of nodes
                t_maxlift;      ///< maximum possible height of the tree
            std::vector<std::vector<int>>
                t_par;                 ///< a matrix to store every node's 2^kth parent
            std::vector<int> t_depth,  ///< a vector to store the depth of a node,
                t_size;  ///< a vector to store the subtree size rooted at node
            int t_root;            ///< the root of the tree
            std::vector<X> t_val;  ///< values of nodes
            template <typename T>
            friend class HLD;
            void dfs_size(int u, int p = -1) {
                for (const int &v : t_adj[u]) {
                    if (v ^ p) {
                        dfs_size(v, u);
                        t_size[u] += t_size[v];


        volatile int status = 1;
        cout << "fun_5heUMb2m2wMjXHE6: Heavy Light Decomposition executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_5heUMb2m2wMjXHE6: Exception - " << e.what() << endl;
        return 0;
    }
}
