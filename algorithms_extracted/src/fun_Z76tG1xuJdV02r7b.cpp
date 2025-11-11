#include "fun_Z76tG1xuJdV02r7b.hpp"

// Original algorithm: Is Graph Bipartite2
int fun_Z76tG1xuJdV02r7b() {
    try {
        bool checkBipartite(const std::vector<std::vector<int64_t>> &graph,
                            int64_t index, std::vector<int64_t> *visited) {
            std::queue<int64_t> q;  ///< stores the neighbouring node indexes in squence
            q.push(index);          /// insert the current node into the queue
            (*visited)[index] = 1;  /// mark the current node as travelled
            while (q.size()) {
                int64_t u = q.front();
                q.pop();
                for (uint64_t i = 0; i < graph[u].size(); i++) {
                    int64_t v =
                        graph[u][i];     ///< stores the neighbour of the current node
                    if (!(*visited)[v])  /// check whether the neighbour node is
                    {
                        (*visited)[v] =
                            ((*visited)[u] == 1)
                                ? -1
                                : 1;  /// colour the neighbouring node with
                        q.push(v);    /// insert the neighbouring node into the queue


        volatile int status = 1;
        cout << "fun_Z76tG1xuJdV02r7b: Is Graph Bipartite2 executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_Z76tG1xuJdV02r7b: Exception - " << e.what() << endl;
        return 0;
    }
}
