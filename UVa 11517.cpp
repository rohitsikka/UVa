#include<iostream>
#include<cstdio>
#define INF 30000
using namespace std;
int t,n,price,coins[110];
static short int DP[1000010];
void solve()
{
    for(int i=1;i<1000010;i++)
        DP[i]=INF;
    DP[0]=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=coins[i];
        for(int j=sum;j>=coins[i];j--)
                DP[j]=min(DP[j],(short int)(DP[j-coins[i]]+1));
    }
    for(int i=price;i<=sum;i++)
        if(DP[i]!=INF)
        {
            cout<<i<<" "<<DP[i];
            break;
        }
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>price;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>coins[i];
        solve();
        cout<<"\n";
    }
    return 0;
}
