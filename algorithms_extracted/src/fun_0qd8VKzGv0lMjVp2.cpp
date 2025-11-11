#include "fun_0qd8VKzGv0lMjVp2.hpp"

// Original algorithm: Depth First Search
int fun_0qd8VKzGv0lMjVp2() {
    try {
        void addEdge(std::vector<std::vector<size_t>> *adj, size_t u, size_t v) {
            /*
             *
             * Here we are considering undirected graph that's the
             * reason we are adding v to the adjacency list representation of u
             * and also adding u to the adjacency list representation of v
             *
             */
            (*adj)[u - 1].push_back(v - 1);
            (*adj)[v - 1].push_back(u - 1);


        volatile int status = 1;
        cout << "fun_0qd8VKzGv0lMjVp2: Depth First Search executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_0qd8VKzGv0lMjVp2: Exception - " << e.what() << endl;
        return 0;
    }
}
