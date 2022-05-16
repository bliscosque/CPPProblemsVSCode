//DFS
//recursive algorythm
//start with a node, mark as visible, make recursive call to neighbors
//O(vertices+edges)


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
    void bfs(int source, int dst=-1) {
        queue<int> q;
        int *dist = new int[V]{0};
        int *parent = new int[V]{-1};
        bool *visited=new bool[V];

        q.push(source);
        visited[source]=true;
        parent[source]=source;
        dist[source]=0;  

        while (!q.empty()) {
            int f=q.front();
            cout << f << endl;
            q.pop();
            //push the neighbors not already visited
            for (auto nbr: l[f]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    //update parent and dist
                    parent[nbr]=f;
                    dist[nbr]=dist[f]+1;
                    visited[nbr]=true;
                }
            }
        }

        //print the shortest distance
        for (int i=0;i<V;i++) {
            cout << "Shortest dist to " << i << " is " << dist[i] << endl;
        }
        if (dst!=-1) {
            int temp=dst;
            while (temp!=source) {
                cout << temp << " --- ";
                temp=parent[temp];
            }
            cout << source << endl;
        }
    }

    void dfsHelper(int node, bool *visited) {
        visited[node]=true;
        cout << "Visited: " << node << endl;
        //call all unvisited nodes
        for (int nbr:l[node]) {
            if (!visited[nbr]) {
                dfsHelper(nbr,visited);
            }
        } 
    }

    void dfs(int source) {
        bool *visited = new bool[V]{0};
        dfsHelper(source,visited);
        
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
    g.dfs(1);


    return 0;
}