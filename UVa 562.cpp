#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int t,n,coins[110];
int C[110][50500];


int solve(int space)
{
    int halfSpace=space/2;
    for(int i=0;i<=n;i++)
        C[i][0]=0;
    for(int i=0;i<=space;i++)
        C[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int s=1;s<=halfSpace;s++)
        {
            if(coins[i]<=s)
            {
                if( abs(halfSpace-C[i-1][s]) > abs(halfSpace-C[i-1][s-coins[i]]-coins[i]))
                    C[i][s]=C[i-1][s-coins[i]]+coins[i];
                else
                    C[i][s]=C[i-1][s];
            }
            else
                C[i][s]=C[i-1][s];
        }
    }
    return abs(space-2*C[n][halfSpace]);
}

int main()
{
    freopen("temp.txt","r",stdin);
    int total;
    cin>>t;
    while(t--)
    {
        total=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>coins[i];
            total+=coins[i];
        }
        cout<<solve(total)<<"\n";
    }
    return 0;
}
