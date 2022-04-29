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


void insertAtHead(node * &head, int data) { //head precisa ser passado por referencia

    if (head==NULL) { //empty list
        head = new node(data);
        return;
    }
    node * n = new node(data);
    n->next=head;
    head=n;

}

void printLL(node *head) {
    while (head!=NULL) {
        cout << head->data << "-->" ;
        head=head->next;
    }
    cout << endl;
}

int main() {
    node *head=NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    printLL(head);
    return 0;
}