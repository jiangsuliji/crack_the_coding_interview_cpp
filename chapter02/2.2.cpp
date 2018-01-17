/*
 * TASK: Given a singly-linked list, determine its n-th to last element.
 */

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

node* init(int a[], int n){
    node *head, *p;
    for(int i=0; i<n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}
// fill this function
node* findNthToLast(node *head, int n){
	if(head == nullptr || n==0){return head;}
	node *fast=head;
	for(int i=0;i<n;i++){
		if(fast == nullptr){
			return nullptr;
		}
		fast = fast->next;
	}
	while(fast){
		fast=fast->next;
		head = head->next;
	}
	return head;
}



int main(){
    int n = 10;
    int a[] = {
        9, 2, 1, 3, 5, 6, 2, 6, 3, 1 
    };
    node *head = init(a, n);
    node *p = findNthToLast(head, 6);
    if(p) cout<<p->data<<endl;
    else cout<<"the length of link is not long enough"<<endl;
    return 0;
}
