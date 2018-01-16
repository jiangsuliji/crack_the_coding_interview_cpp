/*
 * TASK: Given a string, replace all occurrences of the space character ' '
 *       on this string with the string "%20".
 */

#include <iostream>

using namespace std;

char* replace1(char *c){
	if(c==nullptr){return nullptr;}
	int len = strlen(c);
	int cnt = 0;
	for(int i=0;i<len;i++){
		if(c[i]==' '){
			cnt++;
		}
	}
	char *cc = new char[len+cnt*2+1];
	int j = 0;
	for(int i=0;i<len;i++){
		if(c[i]==' '){
			cc[j] = '%';
			cc[j+1] = '2';
			cc[j+2] = '0';
			j += 3;
		}else{
			cc[j++] = c[i];
		}
	}
	cc[j] = '\0';
	return cc;
}



int main(){
    char c[] = "  a b   c; ";
    cout<<replace1(c)<<endl;
    //replace2(c);
    //cout<<c<<endl;
    return 0;
}
