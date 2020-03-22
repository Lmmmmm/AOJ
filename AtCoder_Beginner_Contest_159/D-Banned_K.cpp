#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
 
 
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &x:A)cin>>x;
    
    map<int, lint> cnt;
    for (auto x : A) cnt[x]++;
    lint ret = 0;
    //求出从N个球中找到整数相等的不同的两个球(在code里意思是index一样的value有多大)
    for (auto p : cnt) ret += (p.second - 1) * p.second / 2; //n*n-1/2
     
    for(int i=0;i<N;i++) {
        lint n = cnt[A[i]];
        lint tmp = ret - (n-1);//由于题目是要求去掉第k个球之后找相同整数,所以最后答案减去n-1
        cout << tmp << "\n";
    }
}