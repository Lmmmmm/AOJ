#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int top, S[1000];

void push(int x){
    // top+1之后将元素插入top所指的位置
    S[++top] = x;
}

int pop(){
    top--;
    // 返回top所指的元素
    return S[top+1];
}

int main(){
    int a,b;
    top = 0;
    char c[5];
    while(cin >> c){
        if(c[0] == '+'){
            a=pop();
            b=pop();
            push(a+b);
        }
        else if(c[0]== '-'){
            a=pop();
            b=pop();
            push(b-a);            
        }
        else if(c[0] == '*'){
            a=pop();
            b=pop();
            push(a*b);          
        }
        //atoi是将字符串形式的数字转换为整数值
        else push(atoi(c));  
    }
    cout << pop() << endl;
    return 0;
}