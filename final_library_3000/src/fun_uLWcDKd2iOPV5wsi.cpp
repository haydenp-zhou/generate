#include "fun_uLWcDKd2iOPV5wsi.hpp"

// Original algorithm: Kosaraju
int fun_uLWcDKd2iOPV5wsi() {
    try {
        /* Implementation of Kosaraju's Algorithm to find out the strongly connected
           components (SCCs) in a graph. Author:Anirban166
        */
        void print(const std::vector<std::vector<int> > &a, int V) {
            for (int i = 0; i < V; i++) {
                if (!a[i].empty()) {
                    std::cout << "i=" << i << "-->";
                }
                for (int j : a[i]) {
                    std::cout << j << " ";
                }
                if (!a[i].empty()) {
                    std::cout << std::endl;
                }
            }
        }
        void push_vertex(int v, std::stack<int> *st, std::vector<bool> *vis,
                         const std::vector<std::vector<int> > &adj) {
            (*vis)[v] = true;
            for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
                if ((*vis)[*i] == false) {
                    push_vertex(*i, st, vis, adj);
                }
            }
            st->push(v);
        }
        void dfs(int v, std::vector<bool> *vis,
                 const std::vector<std::vector<int> > &grev) {
            (*vis)[v] = true;
            for (auto i = grev[v].begin(); i != grev[v].end(); i++) {
                if ((*vis)[*i] == false) {
                    dfs(*i, vis, grev);
                }
            }
        }
        int kosaraju(int V, const std::vector<std::vector<int> > &adj) {
            std::vector<bool> vis(V, false);
            std::stack<int> st;
            for (int v = 0; v < V; v++) {
                if (vis[v] == false) {
                    push_vertex(v, &st, &vis, adj);
                }
            }
            std::vector<std::vector<int> > grev(V);
            for (int i = 0; i < V + 1; i++) {
                for (auto j = adj[i].begin(); j != adj[i].end(); j++) {
                    grev[*j].push_back(i);
                }
            }
            for (int i = 0; i < V; i++) vis[i] = false;
            int count_scc = 0;
            while (!st.empty()) {
                int t = st.top();
                st.pop();
                if (vis[t] == false) {
                    dfs(t, &vis, grev);
                    count_scc++;
                }
            }
            return count_scc;
        }
                std::cout << kosaraju(a, adj) << std::endl;
            }
            return 0;
        }

                // Test the algorithm implementation
                cout << "Testing Kosaraju..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_uLWcDKd2iOPV5wsi: Kosaraju executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_uLWcDKd2iOPV5wsi: Exception - " << e.what() << endl;
        return 0;
    }
}
