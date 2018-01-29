/*
 * TASK: You are given a matrix A such that for any given row and column, the
 *       elements on that row/column are sorted in ascending order, i.e., for
 *       a given pair of indices (i,j), A(i',j) <= A(i,j) for all i' < i and
 *       A(i,j') <= A(i,j) for all j' < j. For a given value x, find it in the
 *       matrix.
 */

#include <iostream>
using namespace std;
int d[20][20];
int search(int m, int n, int tar){
	
	int i=0, j=n-1;
	while(i<m && j>=0){
		if(d[i][j]==tar){
			return (i*m+j);
		}
		if(d[i][j]<tar){
			i++;
		}else{
			j--;
		}
	}
	return -1;
}


int main(){
    freopen("9.6.in", "r", stdin);
    int m, n;
    cin>>m>>n;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            cin>>d[i][j];

    int k = search(m, n, 13);
    if(k == -1) cout<<"not found"<<endl;
    else cout<<"position: "<<k/n<<" "<<k%n<<endl;
    fclose(stdin);
    return 0;
}
