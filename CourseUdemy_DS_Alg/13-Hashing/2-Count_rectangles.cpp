//given N cartesian points in a 2D plane, find the number of axis parallel rectangles that can be formed.

//n=8
//{{0,0},{0,1},{1,1},{1,0},{2,1},{2,0},{3,1},{3,0}}

//6

//sol1) brute force -> selecionar cada conjunto de 4 pontos e verificar se é axix parallel rectang -> O(n^4)
//sol2) selecionar 2 pontos e verificar se os demais 2 pontos estao incluidos na lista de pontos -> O(n^2*logN)
  //obs: cuidado com double count dos retangulos

#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    int x, y;
    Point() {
    }
    Point(int x, int y) {
        this->x=x;
        this->y=y;
    }
};

//comparator for set of points
class Compare {
public:
    bool operator()( Point p1, Point p2) const{
        if (p1.x==p2.x) {
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    }
};

int count_rectangles(vector<Point> points) {
    int ans=0;
    //insert all points in the set
    set<Point, Compare> s;
    for (Point p:points) {
        s.insert(p);
    }

    // brute force for 2 points + lookup for the other two
    for (auto it=s.begin();it!=prev(s.end());it++) {
        for (auto jt=next(it);jt!=s.end();jt++) {
            Point p1 = *it;
            Point p2 = *jt;

            //nao eh possivel ter pontos na mesma coordenada x ou mesma coordenada y
            if (p1.x == p2.x || p1.y==p2.y) {
                continue;
            }

            //P3,P4
            Point p3(p1.x,p2.y);
            Point p4(p2.x,p1.y);
            //lookup
            if (s.find(p3) != s.end() && s.find(p4)!=s.end()) {
                ans++;
            }

        }
    }
    return ans/2;
}

int main() {
    vector<Point> vp;
    vp.push_back(Point(0,0));
    vp.push_back(Point(0,1));
    vp.push_back(Point(1,1));
    vp.push_back(Point(1,0));
    vp.push_back(Point(2,1));
    vp.push_back(Point(2,0));
    vp.push_back(Point(3,1));
    vp.push_back(Point(3,0));

    cout << count_rectangles(vp) << endl;

    return 0;
}