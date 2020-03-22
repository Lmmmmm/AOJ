#include<iostream>
using namespace std;
 
bool is_palindrome(string s){//通过判断s翻转之后是否和翻转之前一致来判断回文
    string t(s.rbegin(),s.rend());
    return s == t;
}
 
int main(){
    string s;
    cin>>s;
    int n=s.size();
    if(is_palindrome(s) && is_palindrome(s.substr(0,(n-1)/2)) && is_palindrome(s.substr((n+1)/2))){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}