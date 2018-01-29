/*
 * TASK: Implement the binary search algorithm for an initially sorted array
 *       which has been rotated, i.e., whose elements have been periodically
 *       shifted to the right by an unknown offset k. The complexity of your
 *       algorithm should be O(log(n)) in time, O(1) in space. As an example,
 *       given an array { 8 9 10 1 2 3 4 5 6 7 } (i.e., an array initially
 *       containing all integers in [1,9] which has been rotated three elements
 *       to the right), searching for the value 1 returns 3, searching for the
 *       value 10 returns 2 and searching for the value 5 returns 7.
 *
 * NOTE: The solution presented here assumes all array values are unique (the
 *       problem is not solved as stated if duplicate values are allowed).
 */

#include <iostream>
using namespace std;

int search(int a[], int low, int high, int tar){
	while(low <= high){

		int mid = (low + high)/2;
		if(tar == a[mid]){
			return mid;
		}
		if(a[low]<a[high]){
			if(a[mid]<tar){
				low = mid+1;
			}else{
				high = mid-1;
			}
		}else{
			if(low <=a[mid]){
				if(a[mid]<tar){
					low = mid + 1;
				}else{
					high = mid-1;
				}
			}else{
				if(a[mid]<tar){
					high = mid-1;
				}else{
					low = mid +1;
				}
					
			}
		}
	}
	return -1;

}






int main(){
    int a[12] = {
        15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14
    };
    int b[19] = {
        2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2
    };
    cout<<search(a, 0, 11, 3)<<endl;
    return 0;
}
