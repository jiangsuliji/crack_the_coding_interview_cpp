/*
 * TASK: Given a singly-linked list with labeled nodes, e.g., 0 -> 1 -> 2 -> 3
 *       and a pointer to a node on the list which is not the tail node, remove
 *       that node. As an example, on the list above and a pointer to node 2,
 *       we need to  turn the list into 0 -> 1 -> 3.
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

//fill it here
bool remove(node *c){
	node *cur = c->next; 
	c->data = cur->data;
	c->next = cur->next;
	delete cur;
	return true;
}

void print(node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    int n = 10;
    int a[] = {
        9, 2, 1, 3, 5, 6, 2, 6, 3, 1 
    };
    node *head = init(a, n);
    int cc = 3;
    node *c = head;
    for(int i=1; i<cc; ++i) c = c->next;
    print(head);
    if(remove(c))
        print(head);
    else
        cout<<"failure"<<endl;
    return 0;
}





