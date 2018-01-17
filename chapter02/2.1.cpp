/*
 * TASK: Remove all duplicate elements from an unsorted linked list. Try solving
 *       this problem without using any additional data structures (i.e.,
 *       without generating a copy of the linked list).
 */
#include <iostream>
#include <set>

using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

node* init(int a[], int n){
    node *head, *p;
    for(int i=0; i < n; ++i){
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

// fill this funciton:
void removedulicate1(node *head){
	if(head == nullptr || head->next == nullptr){return;}
	node *cur = head->next;
	set<int> seen;
	seen.insert(head->data);
	while(cur){
		if(seen.find(cur->data)!=seen.end()){
			head->next = cur->next;
			cur = cur->next;
		}else{
			seen.insert(cur->data);
			head->next = cur;
			head = cur;
			cur = cur->next;
		}
	}

}

void print(node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    int n = 10;
    int a[] = {
        3, 2, 1, 3, 5, 6, 2, 6, 3, 1 
    };
    //memset(hash, false, sizeof(hash));
    node *head = init(a, n);
	//removedulicate(head);
    removedulicate1(head);
    print(head);
    return 0;
}
