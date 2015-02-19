#include<iostream>
#include<cstdio>
#include<cstring>
#define MOD 1000000
using namespace std;
int main()
{
    int n,k,DP[110][110];
    freopen("temp.txt","r",stdin);
    while(true)
    {
        memset(DP,0,sizeof(DP));
        scanf("%d %d",&n,&k);
        if(n==0&&k==0)
            break;
        for(int i=0;i<=k;i++)
            DP[0][i]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
                for(int k=0;k<=i;k++)
                {
                    DP[i][j]+=DP[i-k][j-1];
                    DP[i][j]%=MOD;
                }
        printf("%d\n",DP[n][k]);
    }
    return 0;
}
