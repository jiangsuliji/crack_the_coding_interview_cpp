/*
 * TASK: You are given two strings. Determine if one is a rotation of the other.
 *       As an example, given a string "abcde", its possible rotations are
 *       "abcde" (no rotation), "bcdea", "cdeab", "deabc" and "eabcd". You are
 *       allowed to determine if one string is a substring of the other (e.g.
 *       using std::find) at most once.
 */

#include <iostream>

using namespace std;


bool isRotation(string &s1, string &s2){
	if(s1.length()!=s2.length()){return false;}
	string s1double = s1+s1;
	return s1double.find(s2) != string::npos;
}

int main(){
    string s1 = "apple";
    string s2 = "pleap";
    cout<<isRotation(s1, s2)<<endl;
    //cout<<string::npos<<endl;
    return 0;
}
