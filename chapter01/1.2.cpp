/*
 * TASK: Reverse an input C-string. A C-string is a an array of characters whose
 *       last element is the null character '\0'. As an example, the elements of
 *       the C-string literal "word" are {'w','o','r','d','\0'}.
 */

#include <iostream>

using namespace std;

// swap function
void swap(char *a, char *b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

// using pointers
void reverse1(char *s){
	if (!*s) {return;}
	char *p = s;
	while(*p){
		p++;
	}
	p --;
	while(s < p){
		swap(s++,p--);
	}
}

int main(){
	char testeven[]="1234567890";
	char testodd[]="123456789";
	reverse1(testeven);
	reverse1(testodd);
	cout << testeven << endl;
	cout << testodd <<endl;
}





