/*
 * TASK: You are given an image whose pixels (4 bytes each) are stored as an
 *       N×N matrix. Rotate the image by 90 degrees counterclockwise. Try to
 *       solve this problem in place (i.e., without generating a copy of the
 *       matrix).
 */

#include <iostream>

using namespace std;

/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/

void transpose(int a[][4], int N){
	for(int i=0;i<N/2;i++){
		for(int j=0;j<N;j++){
			int tmp = a[i][j];
			a[i][j] = a[N-1-i][j];
			a[N-1-i][j] = tmp;
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			int tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
		}
	}
}




int main(){
    int a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    transpose(a, 4);
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
