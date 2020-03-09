#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int a1 = (a/0.08)-1;//25
    // if((double)a % 0.08 !=(double)0) a1++;
    // int a2 = (a/0.07)+1;//28
    int flag = 0;
    if(a1<=100){
        // for(int i = a1; i<=(a2 < 100 ? a2 :100); i++){
        for(int i = a1; i<=100; i++){
            if(int(i *0.1) == b && int(i*0.08 == a)) {
                cout << i << endl;
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0) cout<< "-1"<<endl;
    return 0;
}