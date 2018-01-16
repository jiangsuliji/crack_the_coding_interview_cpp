/*
 * TASK: Given two strings, determine if they are anagrams. Two strings are
 *       said to be anagrams if they contains exactly the same characters (but
 *       not necessarily in the same order).
 *
 */

#include <iostream>

using namespace std;

bool isAnagram(string a, string b){
	if(a.length()!=b.length()){return false;}
	int seen[256];
	memset(seen, 0, sizeof(seen));
	for(int i=0;i<a.length();++i){
		int v = (int)a[i];
		seen[v] ++;
		v = (int)b[i];
		seen[v] --;
	}
	for(int i=0;i<256;i++){
		if(seen[i]!=0){return false;}
	}
	return true;
}


int main()
{
    string s = "aaabbb";
    string t = "ababab";
    //cout<<isAnagram(s, t)<<endl;
    cout<<isAnagram(s, t)<<endl;
    return 0;
}
