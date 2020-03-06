#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

static const int MAX = 200000;

/*
原本需要双for来找maxv和R[j]-R[i]的最大值,这里使用maxv和minv来记录,复杂度从O(n^2)到O(n)
*/
int main() {
    int R[MAX], n;
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> R[i];

    int maxv = INT_MIN;
    int minv = R[0];

    for (int i = 1; i< n;i++ ){ //如果每次都在这一阶段直接读取R[i],那么数组可以省去
        maxv = max(maxv, R[i] -minv); //更新最大值
        minv = min(minv, R[i]);  //暂存现阶段的最小值
    }

    cout << maxv << endl;

    return 0;
}