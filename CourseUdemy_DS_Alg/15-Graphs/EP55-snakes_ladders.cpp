
//directed graph / unweight (sempre o custo é 1 jogo)
//no exemplo do desenho, 1 é conectado com 15 (atraves da escada do 2), 3, 4, 7(atraves da escada do 5) e 6
//minimizar o custo total
//usar BFS shortest path to compute minimun number of edges

//para criar grafo
//a partir de x, pode ir x+1 até x+6. Se tiver escada, alterar o valor para a posicao destino. Se tiver cobra, descontar os valores


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
        l=new list<int>[V+1];
    }
    void addEdge(int i, int j) {
        l[i].push_back(j);

    }
    int minCostBFS(int src, int dest) {
        queue<int> q;
        vector<bool> visited(V,false);
        vector<int> dist(V,0);

        q.push(src);
        visited[src]=true;
        dist[src]=0;

        while (!q.empty()) {
            int f=q.front();
            q.pop();

            for (int nbr:l[f]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr]=true;
                    dist[nbr]=dist[f]+1;
                }
            }
        }
        return dist[dest];
    }
};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    vector<int> board(n+1,0);

    //board to graph conversion
    for (auto sp: snakes) {
        int s=sp.first;
        int e=sp.second;
        board[s]=e-s;
    }
    for (auto lp:ladders) {
        int s=lp.first;
        int e=lp.second;
        board[s]=e-s;
    }

    //graph
    Graph g(n+1);
    for (int u=1;u<n;u++) {
        for (int dice=1;dice<=6;dice++) {
            int v=u+dice;
            v+=board[v];
            if (v<=n) {
                g.addEdge(u,v);
            }
        }
    }

    return g.minCostBFS(1,n);
    
}
