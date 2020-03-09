#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
 
 
//  5
//  0 1 2 3 4
int main(){
    string s;
    cin >> s;
    int flag=0;
    for(int i = 0; i< s.length()-1;i++){
        if(s[i]-'h'==0 && s[i+1]-'i'==0){
            if(i-1==0 && i+2!=s.length()&& s[i+2]-'i'!=0) {flag=1;break;}
            if(i-1!=0 && i+2==s.length()&& s[i-1]-'h'!=0) {flag=1;break;}
            if(i-1!=0 && i+2!=s.length()&& s[i-1]-'h'!=0&&s[i+2]-'i'!=0) {flag=1;break;}
        }
    }
    if(flag == 1) cout << "Yes"<<endl;
    else cout << "No"<<endl;
    return 0;
}