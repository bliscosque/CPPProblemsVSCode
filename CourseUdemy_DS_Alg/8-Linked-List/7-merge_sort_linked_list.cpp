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

int kthLastElement(node *head, int k){
    node *slow=head;
    node *fast=head;

    int cnt=0;
    while (cnt<k) {
        fast=fast->next; //advance fast n iterarions... so that when slow arrives, we're already there
        cnt++;
    }

    while (fast!=NULL) {
        slow=slow->next;
        fast=fast->next;
    }

    return slow->data;

}



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

node* midPoint(node* head) {
    node *slow=head;
    node *fast=head->next;

    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* mergeSort(node * head) {
    //base case
    if (head == NULL || head->next==NULL) { //0 or 1 elem
        return head;
    }

    node *mid=midPoint(head);
    node *a=head;
    node *b=mid->next;
    mid->next=NULL; //break in the middle

    a=mergeSort(a);
    b=mergeSort(b);
    return merge(a,b);

}

int main() {
    node *a=NULL, *b=NULL;
    insertAtHead(a,10);
    insertAtHead(a,7);
    insertAtHead(a,5);
    insertAtHead(a,1);
    insertAtHead(a,17);
    insertAtHead(a,2);
    insertAtHead(a,14);

    printLL(a);
    cout << endl;
    a=mergeSort(a);
    printLL(a);
    

    return 0;
}