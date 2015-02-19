#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
pair<int , int> p[35];
int T[35];
int t,w,n;
int DP[35][1010];
bool CP[35][1010];
void solve()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=t;j++)
        {
            CP[i][j]=false;
            if(i==0||j==0)
                DP[i][j]=0;
            else if(T[i-1]<=j)
            {
                if(DP[i-1][j] < DP[i-1][j-T[i-1]]+p[i-1].second)
                {
                    DP[i][j]=DP[i-1][j-T[i-1]]+p[i-1].second;
                    CP[i][j]=true;
                }
                else
                {
                    DP[i][j]=DP[i-1][j];
                    CP[i][j]=false;
                }
            }
            else
            {
                    DP[i][j]=DP[i-1][j];
                    CP[i][j]=false;
            }
        }
    }
    cout<<DP[n][t]<<"\n";
    int i=n,j=t;
    vector<int> mark;
    while(i>0&&j>0)
    {
        if(CP[i][j])
        {
            mark.push_back(i-1);
            j=j-T[i-1];
        }
        i--;
    }
    cout<<mark.size()<<"\n";
    for(i=mark.size()-1;i>=0;i--)
        cout<<p[mark[i]].first<<" "<<p[mark[i]].second<<"\n";
}
int main()
{
    freopen("temp.txt","r",stdin);
    int flag=0;
    while(cin>>t)
    {
        if(flag)
            cout<<"\n";
        flag=1;
        cin>>w;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>p[i].first;
                cin>>p[i].second;
                T[i]=3*w*p[i].first;
        }
        solve();

        cin.ignore();
    }
    return 0;
}
