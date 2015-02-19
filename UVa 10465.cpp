#include<iostream>
#include<cstdio>
using namespace std;
int n,m,t;
short int C[10100],T[10100];
void solve()
{
    int Min=min(m,n);
    int Max=max(m,n);
    for(int i=0;i<Min;i++)
    {
        C[i]=0;
        T[i]=0;
    }
    C[Min]=1;
    T[Min]=Min;
    for(int i=Min+1;i<=Max;i++)
    {
        C[i]=C[i-Min]+1;
        T[i]=T[i-Min]+Min;
    }
    if(T[Max]!=Max)
    {
        C[Max]=1;
        T[Max]=Max;
    }

    for(int i=Max+1;i<=t;i++)
    {
        if(T[i-n]+n==T[i-m]+m)
        {
            C[i]=max(C[i-m],C[i-n])+1;
            T[i]=T[i-m]+m;
        }
        else if(T[i-n]+n<T[i-m]+m)
        {
            C[i]=C[i-m]+1;
            T[i]=T[i-m]+m;
        }
        else
        {
            C[i]=C[i-n]+1;
            T[i]=T[i-n]+n;
        }
    }
    cout<<C[t];
    if(T[t]!=t)
        cout<<" "<<t-T[t];
    cout<<"\n";
}
int main()
{
    freopen("temp.txt","r",stdin);
    while(cin>>m)
    {
        cin>>n;
        cin>>t;
        solve();
    }
    return 0;
}
