#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

class node{
public:  
  int data;
  node * next;
  
  node(int data){
      this->data = data;
  }
};


 node * breakChain(node * head){
     //Complete this method
    node *head2=head;
    unordered_set<node *> us;
    while (head->next!=NULL) {
        cout << "in node: " << head->data << endl;
        if (us.find(head->next)==us.end()) { //not in set
            us.insert(head->next);
            head=head->next;
        }
        else {
            head->next=NULL;
            return head2;
        };
    }      
    return head2;
 }


int main() {
    node *root=new node(1);
    root->next=new node(2);
    root->next->next=new node(3);
    root->next->next->next = new node(4);
    root->next->next->next->next=new node(5);
    root->next->next->next->next->next=root->next;

    root= breakChain(root);
    while (root!=NULL) {
        cout << root->data << " " << endl;
        root=root->next;
    }

    return 0;
}