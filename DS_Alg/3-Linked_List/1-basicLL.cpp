#include <bits/stdc++.h>
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

int nodeCount(node* head) {
    int cnt=0;
    while (head!=NULL) {
        cnt++;
        head=head->next;
    }
    return cnt;
}

void insertLinkedList(node* &head, int data, int pos) {
    node *newnode=new node(data);
    if (pos==0) { //insere inicio
        newnode->next = head;
        head=newnode;
    }
    else { //nao eh a primeira posicao
        node *p=head;
        node *q; //aponta ao no anterior
        int k=0;
        while (p!=NULL && k<pos) {
            k++;
            q=p;
            p=p->next;
        }
        q->next=newnode; //proximo do anterior aponta ao novo
        newnode->next=p; //proximo do novo eh o "atual"
    }
}

int main() {
    node* head=new node(10);
    head->next=new node(20);
    insertLinkedList(head,0,0);
    insertLinkedList(head,40,3);

    cout << nodeCount(head) << endl;
    node* p=head;
    while (p!=NULL) {
        cout << p->data << "-->";
        p=p->next;
    }
    cout << endl;

    return 0;
}