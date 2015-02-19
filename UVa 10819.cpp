#include<iostream>
#include<cstdio>
#define INF 10000000
using namespace std;
int m,n,p[110],f[110];

int DP[110][10500];
int solve()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            DP[i][j]=-INF;
    DP[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            if(j>=p[i])
                DP[i][j]=max(DP[i-1][j],DP[i-1][j-p[i]]+f[i]);
            else
                DP[i][j]=DP[i-1][j];
    int ans=0;
    for(int i=m;i>=2001;i--)
        ans=max(ans,DP[n][i]);
    for(int i=0;i<=m-200;i++)
        ans=max(ans,DP[n][i]);
    return ans;
}
int main()
{
    freopen("temp.txt","r",stdin);
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        m+=200;
        for(int i=1;i<=n;i++)
            scanf("%d %d",&p[i],&f[i]);
        printf("%d\n",solve());
    }
    return 0;
}
