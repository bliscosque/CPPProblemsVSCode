//apply running technique - one pointer 2x/item, other pointer 1x/item
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

int getMid(node *head){ 
    node *runner=head->next;
    while(runner && runner->next) {
        runner = runner->next->next;
        head=head->next;
    }
    return head->data;  
    
}


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

void insertInMiddle(node* &head, int data, int pos) {
    if (pos==0) {
        insertAtHead(head,data);
    }
    else {
        node* temp=head;
        for (int jump=1;jump<pos;jump++) {
            temp=temp->next;
        }
        node * n = new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}

node* merge(node* a, node *b) {
    if (a==NULL) {
        return b;
    }
    if (b==NULL) {
        return a;
    }
    node *c;
    if (a->data < b->data) {
        c=a;
        c->next=merge(a->next,b);
    }
    else {
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}

int main() {
    node *a=NULL, *b=NULL;
    insertAtHead(a,8);
    insertAtHead(a,7);
    insertAtHead(a,6);
    insertAtHead(a,5);
    insertAtHead(a,4);
    insertAtHead(a,3);
    insertAtHead(a,2);
    insertAtHead(a,1);

    printLL(a);

    cout << endl;
    cout << getMid(a) << endl;
    

    return 0;
}