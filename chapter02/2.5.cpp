/*
 * TASK: You are given a circular linked list. Determine the first node at the
 *       beginning of the loop. A circular linked list is one in which a node
 *       n_k points to a node_j for j < k, with n_1 being the head node of the
 *       list. As an example, A -> B -> C -> D -> B is a circular list, and B
 *       is the first node in the loop.
 */


#include <iostream>
#include <map>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node* init(int a[], int n, int m){
	node *head, *p, *q;
	for(int i=0; i<n; ++i){
		node *nd = new node();
		nd->data = a[i];
		if(i==m) q = nd;
		if(i==0){
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	p->next = q;
	return head;
}

node* loopstart(node *head){
	if(head==nullptr || head->next == nullptr){return nullptr;}
	node *fast, *slow;
	fast = head;
	slow = head;
	while(fast->next && fast->next->next){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow){
			while (head != slow){
				head = head->next;
				slow = slow->next;
			}
			return head;
		}
	}	
	return nullptr;	
}

int main(){
	int n = 10, m = 9;// m<n
	int a[] = {
		3, 2, 1, 3, 5, 6, 2, 6, 3, 1 
	};
	node *head = init(a, n, m);
	node *p = loopstart(head);
	if(p)
		cout<<p->data<<endl;
	return 0;
}





