#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdio>
using namespace std;
int R,C,t,EW,NS,DP[100][100];
bool grid[100][100];
int solve()
{
    memset(DP,0,sizeof(int)*100*100);
    DP[1][1]=1;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            if(grid[i][j])
            {
                if(i>1)
                    DP[i][j]+=DP[i-1][j];
                if(j>1)
                    DP[i][j]+=DP[i][j-1];
            }
        }
    }
    return DP[R][C];
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>t;
    cin.ignore();
    while(t--)
    {
        memset(grid,true,sizeof(bool)*100*100);
        cin>>R;
        cin>>C;
        cin.ignore();
        for(int i=0;i<R;i++)
        {
            string str;
            getline(cin,str);
            stringstream ss(str);
            ss>>EW;
            while(ss>>NS)
                grid[EW][NS]=false;
        }
        cout<<solve()<<"\n";
        if(t)
            cout<<"\n";
    }
    return 0;
}
