/*
 * TASK: You are given an m×n matrix. For each element M(i,j) which is zero,
 *       make all elements in the i-th row and the j-th column equal to zero.
 */
#include <iostream>

using namespace std;

void zero(int **a, int m, int n){
	bool row[m], col[n];
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==0){
				row[i] = true;
				col[j] = true;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(row[i] or col[j]){
				a[i][j] = 0;
			}
		}
	}
}

int main()
{
    freopen("1.7.in", "r", stdin);

    int m, n;
    cin>>m>>n;
    int **a;
    a = new int*[m];
    for(int i=0; i<m; ++i)
        a[i] = new int[n];
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            cin>>a[i][j];
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    zero(a, m, n);
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    fclose(stdin);
    return 0;
}
