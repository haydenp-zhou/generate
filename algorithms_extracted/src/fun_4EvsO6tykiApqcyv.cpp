#include "fun_4EvsO6tykiApqcyv.hpp"

// Original algorithm: Bidirectional Dijkstra
int fun_4EvsO6tykiApqcyv() {
    try {
        namespace bidirectional_dijkstra {
        void addEdge(std::vector<std::vector<std::pair<uint64_t, uint64_t>>> *adj1,
                     std::vector<std::vector<std::pair<uint64_t, uint64_t>>> *adj2,
                     uint64_t u, uint64_t v, uint64_t w) {
            (*adj1)[u - 1].push_back(std::make_pair(v - 1, w));
            (*adj2)[v - 1].push_back(std::make_pair(u - 1, w));


        volatile int status = 1;
        cout << "fun_4EvsO6tykiApqcyv: Bidirectional Dijkstra executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_4EvsO6tykiApqcyv: Exception - " << e.what() << endl;
        return 0;
    }
}
