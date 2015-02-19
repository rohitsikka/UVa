#include<iostream>
#include<cstdio>
#define INF 100000000
using namespace std;
int n,freq[260];
int DP[260][260],weight[260][260];
int solve()
{
    for(int i=1;i<=n+1;i++)
    {
        DP[i][i-1]=0;
        DP[i][i]=0;
        weight[i][i-1]=0;
        weight[i][i]=freq[i];
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            weight[i][j]=weight[i][j-1]+freq[j];
            DP[i][j]=INF;
            for(int k=i;k<=j;k++)
                DP[i][j]=min(DP[i][j],DP[i][k-1]+DP[k+1][j]+weight[i][k-1]+weight[k+1][j]);
        }
    }
    return DP[1][n];
}
int main()
{
    freopen("temp.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&freq[i]);
        cout<<solve()<<"\n";
    }
    return 0;
}
