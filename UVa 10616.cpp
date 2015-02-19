#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,q,d,m,num[210];
int DP[210][12][22];
int solve()
{
    for(int k=0;k<=d;k++)
        DP[0][0][k]=0;
    for(int i=0;i<=n;i++)
        DP[i][0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<d;k++)
                DP[i][j][k]=DP[i-1][j][k]+DP[i-1][j-1][ ((k-num[i]%d)+d)%d];
    return DP[n][m][0];
}
int main()
{
    freopen("temp.txt","r",stdin);
    int i=1;
    while(true)
    {
        scanf("%d",&n);
        scanf("%d",&q);
        if(n==0&&q==0)
            break;
        for(int j=1;j<=n;j++)
            scanf("%d",&num[j]);
        printf("SET %d:\n",i);
        for(int j=1;j<=q;j++)
        {
            scanf("%d %d",&d,&m);
            printf("QUERY %d: %d\n",j,solve());
        }
        i++;
    }
    return 0;
}
