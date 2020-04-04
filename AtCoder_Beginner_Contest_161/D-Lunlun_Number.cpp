#include<string>
#include<algorithm>
#include<iostream>
#include <queue>
#include<iomanip>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int MOD=1000000007;
 
int main(){
  ll K,x=0;
  cin >> K;
  queue<ll> que;
  for(ll i=1; i<=9; i++) que.push(i);
  for(ll i=1; i<K; i++){
    x=que.front();
    if(x%10!=0) que.push(10*x+x%10-1);
    que.push(10*x+x%10);
    if(x%10!=9) que.push(10*x+x%10+1);
    que.pop();
  }
  cout << que.front() << endl;
}