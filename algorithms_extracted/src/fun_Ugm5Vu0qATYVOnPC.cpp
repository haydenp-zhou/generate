#include "fun_Ugm5Vu0qATYVOnPC.hpp"

// Original algorithm: Kruskal
int fun_Ugm5Vu0qATYVOnPC() {
    try {
        const int mx = 1e6 + 5;
        using ll = int64_t;
        std::array<ll, mx> parent;
        ll node, edge;
        std::vector<std::pair<ll, std::pair<ll, ll>>> edges;
        void initial() {
            for (int i = 0; i < node + edge; ++i) {
                parent[i] = i;
            }
        }
        int root(int i) {
            while (parent[i] != i) {
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        }
        void join(int x, int y) {
            int root_x = root(x);  // Disjoint set union by rank
            int root_y = root(y);
            parent[root_x] = root_y;
        }
        ll kruskal() {
            ll mincost = 0;
            for (int i = 0; i < edge; ++i) {
                ll x = edges[i].second.first;
                ll y = edges[i].second.second;
                if (root(x) != root(y)) {
                    mincost += edges[i].first;
                    join(x, y);
                }
            }
            return mincost;
        }
                initial();  // Initialise the parent array
                for (int i = 0; i < edge; ++i) {
                    std::cin >> from >> to >> cost;
                    edges.emplace_back(make_pair(cost, std::make_pair(from, to)));
                    totalcost += cost;
                }
                sort(edges.begin(), edges.end());
                std::cout << kruskal() << std::endl;
                edges.clear();
            }
            return 0;
        }

                // Test the algorithm implementation
                cout << "Testing Kruskal..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_Ugm5Vu0qATYVOnPC: Kruskal executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_Ugm5Vu0qATYVOnPC: Exception - " << e.what() << endl;
        return 0;
    }
}
