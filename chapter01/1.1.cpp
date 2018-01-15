/*
 * TASK: Given a string, determine if each of its characters is unique, i.e.,
 *       whether the string has duplicate characters or not. Try solving this
 *       problem without using any additional data structures (such as a
 *       buffer).
 */
#include <string>
//#include <stdio>
#include <iostream>

using namespace std;

bool isUnique(string s){
	if (s.length()>256){
		return false;
	}
	bool a[256];
	memset(a, 0, sizeof(a));
	for (int i=0; i < s.length(); ++i){
		int v = (int) s[i];
		if (a[v]){
			return false;
		}
		a[v] = true;
	}
	return true;
}

int main(){
    string s1 = "i am hawstein.";
    string s2 = "abcdefghijklmnopqrstuvwxyzABCD1234567890";
	cout << isUnique(s1) <<"," << isUnique(s2)<<endl;
}






