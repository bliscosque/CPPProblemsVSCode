//heap (or priority queue) is a binary tree where every node is greater than its children (max heap) 
//all the levels are complete field, except last level. This is to be completed from left to right

//push O(logN) 
    //insere no novo nó e compara valor com cada um pai. Se for maior, troca a posicao. Continua até o root
//popMin/popMax  O(LogN)
//gerMin/getMax  O(1)

//BY default, MAX HEAP

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Compare {
public:
    bool operator()(int a, int b) {
        return a>b;
    }
};

int main() {
    vector<int> vi={10,15,20,13,6,90};
    int n=vi.size();

    priority_queue<int> heap;
    //priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int, vector<int>, Compare> minheap; //another option


    for (int x:vi) {
        heap.push(x);
        minheap.push(x);
    }

    while (!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }
    cout << endl << "using min heap!!\n";
    while (!minheap.empty()) {
        cout << minheap.top() << endl;
        minheap.pop();
    }

    return 0;
}