#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int n,cnt[N],sum[N],tmp=2,ans;
char a[N];
int main() {
	scanf("%d",&n); n--;scanf("%s",a);
	for(int i=0;i<=n;i++) {
		a[i]-='1';
		if(a[i]==1) tmp=1;//1,2,3 -> 0,1,2
	}
	for(int i=1;i<=n;i++) 
		sum[i]=sum[i-1]+(cnt[i]=(i&1?0:cnt[i>>1]+1));
	for(int i=0;i<=n;i++)
		if(sum[n]==sum[i]+sum[n-i])
			(ans+=a[i]/tmp)&=1;
	printf("%d\n",ans*tmp); return 0;
}
 