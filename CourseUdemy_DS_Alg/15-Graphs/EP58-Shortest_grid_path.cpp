#include<vector>
#include<set>
#include<climits>
using namespace std;

class Node{
public:
    int x;
    int y;
    int dist;
    Node(int x, int y, int dist) {
        this->x=x;
        this->y=y;
        this->dist=dist;
    }
};

class Compare {
public:
    bool operator()(const Node &a, const Node &b) {
        return a.dist <= b.dist;
    }
};

int shortest_path(vector<vector<int> > grid){
    int m=grid.size();
    int n=grid[0].size();

    int i=0;
    int j=0;


    vector<vector<int>> dist(m+1,vector<int>(n+1,INT_MAX));
    dist[i][j]=grid[0][0];
    set<Node,Compare> s; //will contain i, j, dist
    s.insert(Node(0,0,dist[0][0]));

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    while (!s.empty()) {
        auto it=s.begin();
        int curX=it->x;
        int curY=it->y;
        int curD=it->dist;
        s.erase(it);

        //update nbrs
        for (int k=0;k<4;k++) {
            int nx=curX+dx[k];
            int ny=curY+dy[k];
            if (nx>=0 && nx < m && ny >=0 && ny < n && curD+grid[nx][ny] < dist[nx][ny]) {
                //remove old node if it exists
                Node temp(nx,ny,dist[nx][ny]);
                if (s.find(temp)!=s.end()) {
                    s.erase(s.find(temp));
                }

                int newD=grid[nx][ny]+curD;
                dist[nx][ny]=newD;
                s.insert(Node(nx,ny,newD));
            }
        }
    }
    return dist[m-1][n-1];
}

int main() {

    return 0;
}