#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int DP[1024][124][124],n,ds,t,m,a[1024];
int solve()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=t;k++)
                DP[i][j][k]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<=t;k++)
            {
                if(k==0)
                    DP[i][j][k]=DP[i][j-1][t];
                else if(k>=a[i])
                    DP[i][j][k]=max(DP[i-1][j][k-a[i]]+1,DP[i-1][j][k]);
                else if(k<a[i])
                    DP[i][j][k]=max(DP[i][j-1][t],DP[i-1][j][k]);
            }
    return DP[n][m][t];
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>ds;
    while(ds--)
    {
        cin.ignore();
        cin>>n>>t>>m;
        scanf("%d",&a[1]);
        for(int i=2;i<=n;i++)
            scanf(", %d",&a[i]);
        cout<<solve()<<"\n";
        if(ds)
            cout<<"\n";
    }
    return 0;
}
