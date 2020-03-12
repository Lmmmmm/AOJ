#include<iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt;

//合并两个已排序数组
void merge(int A[], int n, int left, int mid, int right){
    int n1 = mid -left;
    int n2 = right - mid;
    for(int i=0;i<n1;i++)L[i] = A[left+i];
    for(int i=0;i<n2;i++)R[i] = A[mid+i];
    //为了简化merge,在两个数组L和R的末尾安插一个大于所有元素的标记
    //可以既防止两个标记相比较，又防止循环变量i,j分別超过n1,n2
    L[n1] = R[n2] = SENTINEL;
    int i = 0, j= 0;
    for(int k = left;k<right;k++){
        cnt++;
        if(L[i] <= R[j]) A[k] = L[i++];
        else A[k] = R[j++];
    }
}

//无限分治法 这里举个例子
// [9,6,7,2,5,1,8,4,2] -> [9,7,6,2][5,1,8,4,2] -> [9,6][7,2]... ->[9][6][7][2]...
//接下来用merge进行排列
void mergeSort(int A[], int n, int left, int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main(){
    int A[MAX],n,i;
    cnt=0;

    cin >> n;
    for(i =0;i <n;i++) cin >> A[i];

    mergeSort(A,n,0,n);

    for(i =0;i <n;i++){
        if(i) cout << " ";
        cout << A[i];
    }

    cout << endl;

    cout <<cnt << endl;

    return 0;

}
