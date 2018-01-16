/*
 * TASK: Given an input string, remove its duplicate characters without using
 *       an additional buffer (i.e., modify the string in place; do not make
 *       a copy of it). As an example: "abcadbce" is changed into "abcde".
 */

#include <iostream>

using namespace std;

void removeDuplicate1(string &s){
	int len = s.length();
	if (len < 2) {return;}
	bool a[256];
	memset(a, 0, sizeof(a));
	int j = 0;
	for(int i=0; i<len; ++i){
		int v = (int)s[i];
		if(a[v]){
			continue;
		}
		a[v] = true;
		s[j++] = s[i];
	}
	s.resize(j);
}

// with additional mem to record explored data
void removeDuplicate2(char s[]){
	int len = strlen(s);
	if (len < 2) {return;}
	bool a[256];
	memset(a, 0, sizeof(a));
	int j = 0;
	for(int i=0; i<len; ++i){
		int v = (int)s[i];
		if(a[v]){
			continue;
		}
		a[v] = true;
		s[j++] = s[i];
	}
	s[j] = '\0';
}

int main(){
	string s1 = "abcde";
    string s2 = "aaabbb";
    string s3 = "";
    string s4 = "abababc";
    string s5 = "ccccc";
	removeDuplicate1(s1);
	removeDuplicate1(s2);
	removeDuplicate1(s3);
	removeDuplicate1(s4);
	removeDuplicate1(s5);
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;
    char ss1[] = "abcde";
    char ss2[] = "aaabbb";
    char ss3[] = "";
    char ss4[] = "abababc";
    char ss5[] = "ccccc";
    removeDuplicate2(ss1);
    removeDuplicate2(ss2);
    removeDuplicate2(ss3);
    removeDuplicate2(ss4);
    removeDuplicate2(ss5);
    cout<<ss1<<" "<<ss2<<" "<<ss3<<" "<<ss4<<" "<<ss5<<endl;

}



