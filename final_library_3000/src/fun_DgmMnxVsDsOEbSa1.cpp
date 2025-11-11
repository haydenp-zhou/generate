#include "fun_DgmMnxVsDsOEbSa1.hpp"

// Original algorithm: Bellman Ford
int fun_DgmMnxVsDsOEbSa1() {
    try {
        using namespace std;
        class Edge {
         public:
            int src, dst, weight;
        };
        class Graph {
         public:
            int vertexNum, edgeNum;
            std::vector<Edge> edges;
            Graph(int V, int E) {
                this->vertexNum = V;
                this->edgeNum = E;
                this->edges.reserve(E);
            }
            void addEdge(int src, int dst, int weight) {
                static int edgeInd = 0;
                if (edgeInd < this->edgeNum) {
                    Edge newEdge;
                    newEdge.src = src;
                    newEdge.dst = dst;
                    newEdge.weight = weight;
                    this->edges[edgeInd++] = newEdge;
                }
            }
        };
        void print(const std::vector<int>& dist, int V) {
            cout << "\nVertex  Distance" << endl;
            for (int i = 0; i < V; i++) {
                if (dist[i] != INT_MAX)
                    cout << i << "\t" << dist[i] << endl;
                else
                    cout << i << "\tINF" << endl;
            }
        }
        void BellmanFord(Graph graph, int src) {
            int V = graph.vertexNum;
            int E = graph.edgeNum;
            std::vector<int> dist;
            dist.reserve(E);
            for (int i = 0; i < V; i++) dist[i] = INT_MAX;
            dist[src] = 0;
            for (int i = 0; i <= V - 1; i++)
                for (int j = 0; j < E; j++) {
                    int u = graph.edges[j].src;
                    int v = graph.edges[j].dst;
                    int w = graph.edges[j].weight;
                    if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                        dist[v] = dist[u] + w;
                }
            for (int j = 0; j < E; j++) {
                int u = graph.edges[j].src;
                int v = graph.edges[j].dst;
                int w = graph.edges[j].weight;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    cout << "Graph contains negative weight cycle. Hence, shortest "
                            "distance not guaranteed."
                         << endl;
                    return;
                }
            }
            print(dist, V);
            return;
        }
            cout << "\nEnter source: ";
            cin >> gsrc;
            BellmanFord(G, gsrc);
            return 0;
        }


        volatile int status = 1;
        cout << "fun_DgmMnxVsDsOEbSa1: Bellman Ford executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_DgmMnxVsDsOEbSa1: Exception - " << e.what() << endl;
        return 0;
    }
}
