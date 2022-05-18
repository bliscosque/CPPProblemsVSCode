//nao basta verificar se o nó já foi visitado, ele tem que ter sido visitado dentro do mesmo call stack


#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V; //vertices
    list<int> *l;
public:
    Graph(int v) {
        V=v;
        l=new list<int>[V];
    }
    void addEdge(int i, int j, bool direc=true) {
        l[i].push_back(j);
        if (!direc) {
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

    bool dfs(int node, vector<bool> &visited, vector<bool> &stack) {
        //return true if backedge if found, else false
        visited[node]=true;
        stack[node]=true;

        for (int nbr:l[node]) {
            if (stack[nbr]==true) {
                return true;
            }
            else if (visited[nbr]==false) {
                bool nbrFoundCycle=dfs(nbr,visited,stack);
                if (nbrFoundCycle) return true;
            }

        }

        //going back
        stack[node]=false;
        return false;
    }

    bool contains_cycle() {
        vector<bool> visited(V,false);
        vector<bool> stack(V,false);

        //tem q iniciar o dfc de cada nó, pq o grafo completo pode nao estar conectado
        for (int i=0;i<V;i++) {
            int source=i;
            if (!visited[source]) {
                if (dfs(i,visited, stack)) {
                    return true;
                }
            }
        }
        return false;
    }
};

bool contains_cycle(int V, vector<pair<int,int>> edges) {
    Graph g(V);
    for (auto edge:edges) {
        g.addEdge(edge.first, edge.second);
    }
    return g.contains_cycle();
}

int main() {
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);

    cout << g.contains_cycle() << endl;

    return 0;
}