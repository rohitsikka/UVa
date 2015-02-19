#include<iostream>
#include<cstdio>
#define INF 0x3f3f3f3f
using namespace std;
int t,x,DP[10][1010],winds[10][1010];
int solve()
{
    DP[0][0]=0;
    DP[1][1]=60-winds[0][0];
    for(int d=2;d<x;d++)
    {
        for(int h=1;h<10;h++)
        {
            DP[h][d]=DP[h][d-1]+30-winds[h][d-1];
            if(h-1>0)
                DP[h][d]=min(DP[h][d],DP[h-1][d-1]+60-winds[h-1][d-1]);
            if(h+1<=9)
                DP[h][d]=min(DP[h][d],DP[h+1][d-1]+20-winds[h+1][d-1]);
        }
    }
    return DP[1][x-1]+20-winds[1][x-1];
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin.ignore();
        cin>>x;
        if(x==0)
        {
            cout<<0<<"\n";
            continue;
        }
        x=x/100;
        for(int i=9;i>=0;i--)
            for(int j=0;j<x;j++)
            {
                scanf("%d",&winds[i][j]);
                DP[i][j]=INF;
            }
        cout<<solve()<<"\n\n";
    }
    return 0;
}
