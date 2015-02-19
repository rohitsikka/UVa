#include<iostream>
#include<cstdio>
using namespace std;
int N,t,track[25],C[25][10000];
bool T[25][10000];
void print(int i,int j)
{
    if(i<=0||j<=0)
        return ;
    if(T[i][j]==true)
    {
        print(i-1,j-track[i]);
        cout<<track[i]<<" ";
    }
    else
        print(i-1,j);
}
void solve()
{
    for(int i=0;i<=t;i++)
        C[i][0]=0;
    for(int i=0;i<=N;i++)
        C[0][i]=0;

    for(int i=1;i<=t;i++)
    {
        for(int s=1;s<=N;s++)
        {
            if(track[i]<=s)
            {
                if(C[i-1][s] > C[i-1][s-track[i]]+track[i])
                 {
                     C[i][s]=C[i-1][s];
                     T[i][s]=false;
                 }
                 else
                 {
                     C[i][s]=C[i-1][s-track[i]]+track[i];
                     T[i][s]=true;
                 }
            }
            else
            {
                C[i][s]=C[i-1][s];
                T[i][s]=false;
            }
        }
    }
    print(t,N);
    cout<<"sum:"<<C[t][N];
}
int main()
{
    freopen("temp.txt","r",stdin);
    while(cin>>N)
    {
        cin>>t;
        for(int i=1;i<=t;i++)
            cin>>track[i];
        solve();
        cout<<"\n";
    }
    return 0;
}
