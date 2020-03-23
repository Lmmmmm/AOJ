#include <cstdio>
#include <algorithm>
#define maxn 105
using namespace std;
int dp[maxn][maxn];
char s[maxn][maxn];

int main(){
	int h,w,i,j;
	scanf("%d%d",&h,&w);
	for(i=1;i<=h;i++)scanf("%s",s[i]+1);

	for(i=1;i<=h;i++)
		for(j=1;j<=w;j++)
			dp[i][j]=210;//设置最大值
	dp[1][1]=(s[1][1]=='#');//0 or 1
	for(i=1;i<=h;i++)
		for(j=1;j<=w;j++){
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+(s[i][j]!=s[i][j+1]));//(i,j)右侧
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+(s[i][j]!=s[i+1][j]));//(i,j)下方
		}
	printf("%d\n",(dp[h][w]+1)/2);//.=>#=>.程序中变换了2次，但我们看到的是变换了1次.=>#
	return 0;
}