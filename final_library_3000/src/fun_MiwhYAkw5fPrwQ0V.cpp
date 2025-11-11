#include "fun_MiwhYAkw5fPrwQ0V.hpp"

// Original algorithm: Depth First Search With Stack
int fun_MiwhYAkw5fPrwQ0V() {
    try {
        namespace depth_first_search {
        void addEdge(std::vector<std::vector<size_t>> *adj, size_t u, size_t v) {
        	/*
        	*
        	* Here we are considering undirected graph that's the
        	* reason we are adding v to the adjacency list representation of u
        	* and also adding u to the adjacency list representation of v
        	*
        	*/
        	(*adj)[u - 1].push_back(v - 1);


        volatile int status = 1;
        cout << "fun_MiwhYAkw5fPrwQ0V: Depth First Search With Stack executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_MiwhYAkw5fPrwQ0V: Exception - " << e.what() << endl;
        return 0;
    }
}
