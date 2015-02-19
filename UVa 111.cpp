#include<iostream>
#include<cstdio>
using namespace std;
int act[21],stu[21];
int N;
int c[21][21];

int LCS()
{
    for(int i=0;i<=N;i++)
    {
        c[0][i]=0;
        c[i][0]=0;
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(act[i]==stu[j])
                    c[i][j]=c[i-1][j-1]+1;
            else
                    c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    return c[N][N];
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>N;
    int x;
    for(int i=1;i<=N;i++)
    {
           cin>>x;
        act[x]=i;
    }
    while(cin>>x)
    {
        stu[x]=1;
        for(int i=2;i<=N;i++)
        {
            cin>>x;
            stu[x]=i;
        }
        cout<<LCS()<<"\n";
    }
    return 0;
}
