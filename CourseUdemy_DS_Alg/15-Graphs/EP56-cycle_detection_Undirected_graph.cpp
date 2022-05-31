//every graph that does not contain a cycle, is a tree
//if have a cycle, have a way to visit a node more than once
   //neighbor cannot be parent of node no DFS
//pode usar BFS ou DFS

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

    bool dfs(int node, vector<bool> &visited, int parent) {
        visited[node]=true;
        for (auto nbr:l[node]) {
            if (!visited[nbr]) {
                bool nbrFoundCycle=dfs(nbr,visited,node);
                if (nbrFoundCycle) return true;
            }
            else if (nbr!=parent) { //neighbor is visited and it's not the parent of current node... cycle found
                return true;
            }
        }
    }

    bool contains_cycle(int,vector<pair<int,int> > edges){
        //assuming grapth is a single component (no disconnect between parts)
        vector<bool> visited(V,false);
        return dfs(0,visited,-1);
    
    }
};


bool contains_cycle(int V,vector<pair<int,int> > edges){
    //Complete this method
    Graph g(V);
    for(auto edge : edges){
        g.addEdge(edge.first,edge.second);
    }
    return g.contains_cycle(V,edges);
}

int main() {
    int V=3;
    vector<pair<int,int>> edges={{1,2},{0,1},{2,0}};
    Graph g(V);
    for (auto a:edges) {
        g.addEdge(a.first, a.second);
    } 
    cout << g.contains_cycle(V,edges) << endl;

    return 0;
}