/*
 * TASK: Given two sorted arrays v1 and v2, merge their values while keeping
 *       them sorted. The final result should be placed into v1 (v1 is assumed
 *       to initially have enough space to accommodate the values of v2 as
 *       well).
 */

#include <iostream>

using namespace std;

void merge(int a[], int b[], int m, int n){
	int k = m+n-1;
	int i = m-1, j = n-1;
	while(i>=0 && j>=0){
		if(a[i]>=b[j]){
			a[k--]=a[i--];
		}else{
			a[k--]=b[j--];
		}
	}
	while(j>=0){
		a[k--]=b[j--];
	}
}

int main(){
    int a[15] = {
        1, 3, 7, 8, 9
    };
    int b[] = {
        2, 4, 5, 6, 10
    };
    int n = 5, m = 5;
    merge(a, b, 5, 5);
    for(int i=0; i<m+n; ++i)
        cout<<a[i]<<" ";
    return 0;
}

