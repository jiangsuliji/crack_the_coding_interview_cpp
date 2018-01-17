/*
 * TASK: You are given two numbers stored as linked lists. Each node of these
 *       lists stores a single digit of its associated number, and the digits
 *       are stored in reverse order, i.e., the least significant digit is the
 *       first element in the list and the most significant digit is the last
 *       element in the list. Compute the sum of the two given numbers and
 *       return the sum using the same (list) representation. As an example,
 *       215 + 58 = 273 is represented as {5,1,2} + {8,5} = {3,7,2}.
 */

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

node* init(int a[], int n){
    node *head=NULL, *p;
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

void print(node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// fill it here
node* addlink(node *p, node *q){
	node *head = new node();
	node *rtn = head;
	int c = 0;
	while(p && q){
		int sum = c+p->data+q->data;
		head->data = sum%10;
		c = sum/10;
		p = p->next;
		q = q->next;
		if(p || q || c){
			node *nexthead = new node();
			head->next = nexthead;
			head = nexthead;
		}else{
			return rtn;
		}
	}
	while(p){
		int sum = c+p->data;
		head->data = sum%10;
		c = sum/10;
		p = p->next;
		if (p || c){
			node *nexthead = new node();
			head->next = nexthead;
			head = nexthead;
		}else{
			return rtn;
		}
	}

	while(q){
		int sum = c+q->data;
		head->data = sum%10;
		c = sum/10;
		q = q->next;
		if (q || c){
			node *nexthead = new node();
			head->next = nexthead;
			head = nexthead;
		}else{
			return rtn;
		}
	}
	if(c==0){return rtn;}
	head->data = c%10;
	c = c/10;
	if(c>0){
		node *nexthead = new node();
		head->next = nexthead;
		nexthead->data = c;
	}
	return rtn;
}

int main(){
    int n = 5;
    int a[] = {
        1, 2, 9, 9, 3
    };
    int m = 3;
    int b[] = {
        9, 9, 2
    };

    node *p = init(a, n);
    node *q = init(b, m);
    node *res = addlink(p, q);
    if(p) print(p);
    if(q) print(q);
    if(res) print(res);
    return 0;
}



