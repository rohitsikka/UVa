#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#define INF 2147483646

using namespace std;
int n,m,s;
pair<int ,int>c[45];

void solve()
{
    static int DP[310][310];
    for(int i=0;i<=s;i++)
        for(int j=0;j<=s;j++)
            DP[i][j]=INF;
    DP[0][0]=0;
    for(int k=0;k<m;k++)
        for(int i=c[k].first;i<=s;i++)
            for(int j=c[k].second;j<=s;j++)
                DP[i][j]=min(DP[i][j],1+DP[i-c[k].first][j-c[k].second]);
    int ans=INF;
    for(int i=0;i<=s;i++)
        for(int j=0;j<=s;j++)
            if((i*i+j*j)==s*s)
                ans=min(ans,DP[i][j]);
    if(ans!=INF)
        cout<<ans;
    else
        cout<<"not possible";
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>n;
    while(n--)
    {
        cin>>m>>s;
        for(int i=0;i<m;i++)
        {
            cin>>c[i].first;
            cin>>c[i].second;
        }
        solve();
        cout<<"\n";
    }
    return 0;
}
