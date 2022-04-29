#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

bool isPresent(node * head, int key){
    while (head != NULL) {
        if (head->data==key) return true;
        head=head->next;
    }    
    return false;
}

int main() {
    node *head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=new node(5);
    cout << isPresent(head,2) << endl;
    cout << isPresent(head,10) << endl; 
    return 0;
}