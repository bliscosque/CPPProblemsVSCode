//given a linked list, write a funcion to reverse every k nodes
//1->2->3->4->5->6->7->8->NULL and k=3
//3->2->1->6->5->4->8->7->NULL

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

node* recReverse(node *head) {
    //base case
    if (head==NULL || head-> next==NULL) {
        return head;
    }
    node* sHead=recReverse(head->next);
    head->next->next=head; //reverse next node
    head->next=NULL;//set to null the current node
    return sHead; //return new head
}

void reverse(node *&head) {
    node* prev=NULL;
    node* current=head;
    node* temp;

    while (current!=NULL) {
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    head=prev;
}

node* kReverse(node *head, int k) {
    if (head==NULL){
        return NULL;
    }
    //reverse the first k nodes
    node* prev=NULL;
    node* current=head;
    node* temp;
    int cnt=1;

    while (current!=NULL && cnt<=k) {
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
        cnt++;
    }
    if (temp!=NULL) {
        head->next = kReverse(temp,k);
    }
    return prev;
}

int main() {
    node *head=NULL;
    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);
    
    head=kReverse(head,3);

    printLL(head);
    return 0;
}