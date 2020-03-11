#include<iostream>
// #include<stack>
// #include<string>
// #include<vector>
#include<algorithm>
using namespace std;

int search(int A[], int n, int key){
    int i = 0;
    A[n] = key;
    //while为比较循环,比起for循环的结束条件,while是关键字之间的比较,由于标记能确保while不成为死循环,因此可以省去循环结束条件
    //通常来说线性搜索的算法复杂度为O(n),但在引入标记以后效率能提升数倍,处理大规模数据会有明显的效果
    while(A[i]!=key) i++;
    return i!=n;
}

int main(){
    int n,q,A[10000+1],key,sum=0;

    cin >> n;
    for(int i =0; i<n;i++) cin >> A[i];
    cin>>q;
    for(int i =0; i<q;i++){
        cin >> key;
        if(search(A,n,key)) sum++;
    }
    cout << sum << endl;
    return 0;
}