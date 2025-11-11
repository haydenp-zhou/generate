#include "fun_8vSk3YtgdvKIr9iV.hpp"

// Original algorithm: Floyd Warshall
int fun_8vSk3YtgdvKIr9iV() {
    try {
        using std::cin;
        using std::cout;
        using std::endl;
        class Graph {
         public:
            int vertexNum;
            int **edges;
            Graph(int V) {
                this->vertexNum = V;
                this->edges = new int *[V];
                for (int i = 0; i < V; i++) {
                    this->edges[i] = new int[V];
                    for (int j = 0; j < V; j++) this->edges[i][j] = INT_MAX;
                    this->edges[i][i] = 0;
                }
            }
            ~Graph() {
                for (int i = 0; i < vertexNum; i++) {
                    delete[] edges[i];
                }
                delete[] edges;
            }
            void addEdge(int src, int dst, int weight) {
                this->edges[src][dst] = weight;
            }
        };
        void print(const std::vector<int>& dist, int V) {
            cout << "\nThe Distance matrix for Floyd - Warshall" << endl;
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i * V + j] != INT_MAX)
                        cout << dist[i * V + j] << "\t";
                    else
                        cout << "INF"
                             << "\t";
                }
                cout << endl;
            }
        }
        void FloydWarshall(Graph graph) {
            std::size_t V = graph.vertexNum;
            std::vector<std::vector<int> > dist(V, std::vector<int>(V));
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++) dist[i][j] = graph.edges[i][j];
            for (int k = 0; k < V; k++)
                for (int i = 0; i < V; i++)
                    for (int j = 0; j < V; j++)
                        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                            dist[i][k] + dist[k][j] < dist[i][j])
                            dist[i][j] = dist[i][k] + dist[k][j];
            std::vector<int> dist1d(V * V);
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++) dist1d[i * V + j] = dist[i][j];
            print(dist1d, V);
        }
            FloydWarshall(G);
            return 0;
        }


        volatile int status = 1;
        cout << "fun_8vSk3YtgdvKIr9iV: Floyd Warshall executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_8vSk3YtgdvKIr9iV: Exception - " << e.what() << endl;
        return 0;
    }
}
