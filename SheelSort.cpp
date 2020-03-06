#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int cnt;
vector<int> G;

//指定了间隔g的插入排序
void insertionSort(int a[], int n, int g){
    int v,j;
    for(int i = g; i < n; i++){
        v= a[i];
        j = i-g;
        while( j>=0 && a[j] > v){
            a[j+g] = a[j];
            j -=g;
            cnt++;
        }
        a[j+g] = v;
    }
}

void sheelSort(int a[], int n){
    // 生成数列G={1,4,13,40,131,364,1093,....}仙人验证gn+1=3gn+1是算法复杂度比较好
    for(int h = 1; ;){
        if(h>n) break;
        G.push_back(h);
        h= 3*h+1;
    }
    for(int i= G.size()-1; i>=0;i--){//按逆序指定G[i]=g
        insertionSort(a,n,G[i]);
    }
}

int main(){
    int n;
    cnt = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i< n; i++) cin>> a[i];
    
    sheelSort(a,n);
    
    cout << G.size() << endl;
    for( int i = G.size()-1; i>=0; i--){
        cout<<G[i];
        if(i) cout << " ";
    }
    cout << endl;
    cout << cnt<< endl;

    for(int i=0; i<n; i++) cout << a[i] <<endl;

    return 0;
}