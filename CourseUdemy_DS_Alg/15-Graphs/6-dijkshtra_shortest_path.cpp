//shorted path on weighted graphs
//single source shortest paths (SSSP)


#include<bits/stdc++.h>
#include <climits>
using namespace std;

class Graph{
    int V; //vertices
    list<pair<int,int>> *l;
public:
    Graph(int v) {
        V=v;
        l = new list<pair<int,int> >[V];
    }
    void addEdge(int i, int j, int wt, bool undir=true) {
        l[i].push_back({wt,j});
        if (undir) {
            l[j].push_back({wt,i});
        }
    }
    int dijkstra(int src, int dest) {
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s;

        //1. init
        dist[src] = 0;
        s.insert({0,src});

        while (!s.empty()) {
            auto it=s.begin();
            int node=it->second;
            int nodeDist=it->first;

            s.erase(it);

            //iterate over nbrs
            for (auto nbrPair: l[node]) {
                int nbr=nbrPair.second;
                int currentEdge=nbrPair.first;

                if (nodeDist+currentEdge < dist[nbr]) {
                    //remove if such a nbr already exists in set
                    auto f=s.find({dist[nbr],nbr});
                    if (f!=s.end()) {
                        s.erase(f);
                    }

                    //insert updated value
                    dist[nbr]=nodeDist+currentEdge;
                    s.insert({dist[nbr],nbr});
                }
            }
        }

        for (int i=0;i<V;i++) {
            cout << "distance to node: " << i <<" is " << dist[i] << endl;
        }
        return dist[dest];
    }

};

int main() {
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);
    g.dijkstra(0,5);
    return 0;
}