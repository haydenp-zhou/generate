#include "fun_hxawJ8AsAFnLBl46.hpp"

// Original algorithm: Dijkstra
int fun_hxawJ8AsAFnLBl46() {
    try {
        void addEdge(std::vector<std::vector<std::pair<int, int>>> *adj, int u, int v,
                     int w) {
            (*adj)[u - 1].push_back(std::make_pair(v - 1, w));


        volatile int status = 1;
        cout << "fun_hxawJ8AsAFnLBl46: Dijkstra executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_hxawJ8AsAFnLBl46: Exception - " << e.what() << endl;
        return 0;
    }
}
