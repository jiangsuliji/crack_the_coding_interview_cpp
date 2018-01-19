/**
 * @brief An implementation of three stacks stored as a single array of length
 *        3n, with each stack being allowed to store at most n elements.
 */

#include <iostream>

using namespace std;

class stack3_1 {
public:	
	stack3_1 (int sz = 300){
		buf = new int[sz*3];
		ptop[0]=0;
		ptop[1]=sz;
		ptop[2]=2*sz;
		this->sz = sz;
	}
	~stack3_1(){
		delete[]buf;
	}
	int top(int stackNum){
		if(ptop[stackNum]!=stackNum*sz){
			return buf[ptop[stackNum]-1];
		}
		return -1;
	}
	void push(int stackNum, int val){
		if(ptop[stackNum] == sz*(stackNum+1)) return;
		buf[ptop[stackNum]] = val;
		ptop[stackNum] ++;
	}
	int pop(int stackNum){
		if(ptop[stackNum] == sz*stackNum) return -1;
		return buf[ptop[stackNum]--];
	}

private:
	int *buf;
	int ptop[3];
	int sz;
};


int main(){
	stack3_1 mystack;//stack3 mystack;
	for(int i=0; i<10; ++i)
		mystack.push(0, i);
	for(int i=10; i<20; ++i)
		mystack.push(1, i);
	for(int i=100; i<110; ++i)
		mystack.push(2, i);
	for(int i=0; i<3; ++i)
		cout<<mystack.top(i)<<" ";

	cout<<endl;
	for(int i=0; i<3; ++i){
		mystack.pop(i);
		cout<<mystack.top(i)<<" ";
	}
	mystack.push(0, 111);
	mystack.push(1, 222);
	mystack.push(2, 333);
	for(int i=0; i<3; ++i)
		cout<<mystack.top(i)<<" ";
	return 0;
}
