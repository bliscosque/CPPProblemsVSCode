//cada no -> vertice
//aresta

//grafos com ou sem peso (aresta tem valor)
//undirected graph (todos sao bidirecionais) | directed graph (pode ir apenas em uma direcao)

//storing a graph
//1) adjacency Matrix
  //Vantagem: checar se ha um vizinho, em apenas O(1)
//2) adjacency List
  //cada lista da lista tem uma lista dos seus vizinhos
  //Vantagem: sabe quais sao os vizinhos com facilidade
  // usa menos memória


//imp adjacency list
#include <iostream>
#include <list>
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
};

int main() {
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);

    g.printAdjList();
    
    return 0;
}