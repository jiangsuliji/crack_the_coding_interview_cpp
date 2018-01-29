/*
 * TASK: For a given group of people, determine what is the tower with the most
 *       number of people which they can form such that each person can stand
 *       on the shoulders of another one only if he/she is both lighter and
 *       smaller than the person below. As an example, a person of height 160cm
 *       and weight 65kg can stand on the shoulders of a person of height 170cm
 *       and weight 70kg but not on the shoulders of someone of weight 60kg or
 *       height 160cm.
 *      
EXAMPLE:

Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)

Output: The longest tower is length 6 and includes from top to bottom: (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)
 */

#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100; 
struct person{
  int w, h;
};
person p[maxn];

bool cmp(person p1, person p2)
{
	if(p1.h==p2.h) return p1.w < p2.w;
	return p1.h<p2.h;
}

int lis(person p[], int n)
{
	int unfit=0;
	int rtn=0;
	while(unfit <n)
	{
		bool found = false;
		int ls = unfit;
		int cur = 1;
		for(int i=unfit+1; i< n; ++i)
		{
			if(cmp(p[ls],p[i])){
				cur++;
				ls = i;
			}else if (found==false){
					found = true;
					unfit = i;
			}
		}
		if(cur > rtn){
			rtn = cur;
		}
		if(found==false){
			break;
		}
	}
	
	return rtn;//dp[n-1];
}




int main(){
    freopen("9.7.in", "r", stdin);
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>p[i].h>>p[i].w;
    sort(p, p+n, cmp);
    
	for(int i=0;i<n;i++)
	{
		cout << p[i].h<<":"<<p[i].w<<",";
	}
	cout<<lis(p, n)<<endl;
    fclose(stdin);
    return 0;
}
