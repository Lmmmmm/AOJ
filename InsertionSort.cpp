#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

void trace(int a[], int n){
    for(int i = 0; i< n; i++){
        if(i > 0) cout<<' ';
        cout<< a[i];
    }
    cout << endl;
}
void insertionSort(int a[], int n){//插入排序最差情况的时间复杂度为O(n^2)
    int tmp,j;
    for(int i = 1; i< n; i++){
        tmp = a[i];
        j = i-1;
        while(j >=0 && a[j]> tmp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
        trace(a,n);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0; i< n;i++) cin >> a[i];
    trace(a,n);
    insertionSort(a,n);
    return 0;
}