#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k[14];
bool stan[1000100];
void solve()
{
    for(int i=0;i<=n;i++)
        stan[i]=false;
    for(int i=0;i<m;i++)
        stan[k[i]]=true;
    for(int i=1;i<=n;i++)
    {
        if(!stan[i])
            for(int j=0;j<m;j++)
            {
                if(i-k[j]>=0)
                    if(stan[i-k[j]]==false)
                        stan[i]=true;
            }
    }
    if(stan[n])
        cout<<"Stan wins\n";
    else
        cout<<"Ollie wins\n";
}
int main()
{
    freopen("temp.txt","r",stdin);
    while(cin>>n)
    {
        cin>>m;
        for(int i=0;i<m;i++)
            cin>>k[i];
        solve();
    }
    return 0;
}
