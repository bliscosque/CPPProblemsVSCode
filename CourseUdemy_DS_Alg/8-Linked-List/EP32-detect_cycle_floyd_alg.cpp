//a.k.a.: Tortoise/Hare algorithm
//https://www.youtube.com/watch?v=PvrxZaH_eZ4

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

bool containsCycle(node *head){
    node*slow=head;
    node*fast=head;

    while (slow && fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) {
            return true;
        }
    }
    return false; 
        
}