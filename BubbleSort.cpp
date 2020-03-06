#include <iostream>
#include <algorithm>
using namespace std;

//使用flag的冒泡排序法
int bubblesort(int A[], int N){
    bool flag = 1;
    int cnt = 0;
    //如果有一趟没有发生交换,也就是flag一直等于0的话,说明排序已经完成
    for(int i=0; flag; i++){
        flag = 0;
        for(int j = N-1; j>=i+1;--j){
            if(A[j]< A[j-1]){
                swap(A[j],A[j-1]);
                flag =1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int N ,cnt;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++) cin >> A[i];
    cnt = bubblesort(A, N);
    for(int i = 0;i<N;i++){
        if(i) cout<< " ";//i!=0
        cout<<A[i];
    }
    cout << endl;
    cout << cnt << endl;
}