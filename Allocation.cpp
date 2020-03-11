#include <iostream>
// #include<stack>
// #include<string>
// #include<vector>
#include <algorithm>
using namespace std;
#define MAX 100000
typedef long long llong;

int n,k;
llong T[MAX];

//k辆最大运载量为P的卡车能装多少货物
int check(llong P){
    int i=0;
    for(int j=0; j<k;j++ ){
        llong s=0;
        while( s+T[i] <= P){
            s+=T[i];
            i++;
            if( i==n) return n;
        }
    }
    return i;
}

int solve(){
    llong left = 0;
    llong right = 100000 * 100000; //货物数 x1件货物的最大重量
    llong mid;
    while( right -left >1){
        mid = (left + right) /2;
        int v = check(mid);
        if(v >= n) right = mid;//mid == 检查 mid == P 时能装多少货物
        else left = mid;
    }
    return right;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i< n; i++) cin >> T[i];
    llong ans = solve();
    cout << ans << endl;
    
    return 0;
}