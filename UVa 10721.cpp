#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    freopen("temp.txt","r",stdin);
    int n,m,k;
    long long int DP[55][55];
    while(scanf("%d %d %d",&n,&k,&m)!=EOF)
    {
        memset(DP,0,sizeof(DP));
        DP[0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
                for(int k=1;k<=m;k++)
                    if(i-k>=0)
                        DP[i][j]+=DP[i-k][j-1];
        printf("%lld\n",DP[n][k]);
    }
    return 0;
}
