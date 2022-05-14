//2 maneiras de passar pelo grafico
//BFS -> breadth first search -> level order (distance from source)
//DFS -> depth first search

//BFS -> queue -> FIFO
  //req: a visited array, to know if node was visited or no
  //adiciona no na fila e marca como visitado
  //adiciona os vizinhos (nao visitados) e marca como visitados
  //pega o primeiro elemento da fila e repete

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V; //vertices
    list<int> *l;
public:
    Graph(int v) {
        V=v;
        l=new list<int>[V];
    }
    void addEdge(int i, int j, bool undir=true) {
        l[i].push_back(j);
        if (undir) {
            l[j].push_back(i);
        }
    }
    void printAdjList() {
        for (int i=0;i<V;i++) {
            cout << i  << "-->";
            for (auto node:l[i]) {
                cout << node << ",";
            }
            cout << endl;
        }
    }
    void bfs(int source) {
        queue<int> q;
        bool *visited=new bool[V];

        q.push(source);
        visited[source]=true;
        while (!q.empty()) {
            int f=q.front();
            cout << f << endl;
            q.pop();
            //push the neighbors not already visited
            for (auto nbr: l[f]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }
};

int main() {
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.addEdge(2,3);

    g.printAdjList();
    
    cout << endl;
    g.bfs(1);

    return 0;
}