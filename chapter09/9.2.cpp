/*
 * TASK: Given an array of strings, sort them in a way which groups anagrams
 *       together. As an example, given { "abc", "def", "bca", "fed", "ace" },
 *       the result will be { "abc", "bca", "ace", "def", "fed" }.
 */

#include <iostream>
using namespace std;

bool cmp(string a, string b){
	sort(a.begin(),a.end());
	sort(b.begin(), b.end());
	return a < b;
}

int main(){
	string s[]={"axyz", "abc", "yzax", "bac", "zyxa", "fg", "gf"};
	sort(s, s+sizeof(s)/sizeof(string),cmp);
	for(int i=0;i<sizeof(s)/sizeof(string);++i){
		cout<<s[i]<<endl;
	}

}



