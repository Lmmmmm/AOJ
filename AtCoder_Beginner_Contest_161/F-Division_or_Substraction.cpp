#include<iostream>
#include<set>
typedef long long ll;
using namespace std;
 
//c++14
set<ll> enumDivisor(ll N) {
    set<ll> res;
    for (ll i = 1; i * i <= N; i++) {
        //求出所有约数
        if (N % i == 0) {
            res.insert({i, N / i});
        }
    }
    return res;
}

int main() {
    ll N, ans = 0;
    cin >> N;
    for (ll k : enumDivisor(N)) {
        //题目要求2开始
        if (k == 1) continue;
        ll n = N;
        while (n % k == 0) n /= k;
        if (n % k == 1) ans++;
    }
    cout << ans + enumDivisor(N-1).size() - 1 << endl;
}

/*
KがNを1回以上割り切ることができるかどうかで場合分けすることを考えます。
KがNを1回以上割り切るとき、そのようなKはNの約数に限られます。
したがって、Nの約数について、Nを可能な限りKで割り、その数をKで割ったあまりが1になるかを確かめればよいです。
この操作は約数1つにつきO(logN)で行うことができ、またN<=10^12の制約の下で約数は高々10^4個しか存在しないことから、十分高速に判定を行うことができます。
KがNを1回も割り切ることがないとき、条件を満たすのはN%K=1となるときです。
これを変形すると(N-1)%K=0となり、これから条件を満たすKはN-1の約数に限られることが分かります。
K=1のときKは条件を満たさないことに注意すると、Nの約数とN-1の約数をそれぞれ求め、(1を除くNの約数のうち上記の条件を満たすものの個数)+(1を除くN-1の約数の個数)が答えとなることが分かります。
*/