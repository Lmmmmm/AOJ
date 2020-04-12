#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> 
using namespace std;
#define ll long long
using namespace std;
const int N=4e3+5;
char s[N];
int main() {
    int n;
    scanf("%d%s",&n,s);
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='R') a++;
        if(s[i]=='G') b++;
        if(s[i]=='B') c++;
    }
    ll ans=1LL*a*b*c;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(s[i]==s[j]) continue;
            if(2*j-i<n&&s[i]!=s[2*j-i]&&s[j]!=s[2*j-i]) ans--;
        }
    }
    printf("%lld\n",ans);
    return 0;
}