#include<iostream>
#include<cstdio>
using namespace std;
int n,arr[10000],DP[10000];
int solve()
{
    DP[0]=arr[0];
    for(int i=1;i<n;i++)
        DP[i]=max(DP[i-1]+arr[i],arr[i]);
    int max=DP[0];
    for(int i=1;i<n;i++)
        if(max<DP[i])
            max=DP[i];
    return max;
}
int main()
{
    freopen("temp.txt","r",stdin);
    while(cin>>n&&n!=0)
    {
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ans=solve();
        if(ans>0)
            cout<<"The maximum winning streak is "<<ans<<".\n";
        else
            cout<<"Losing streak.\n";
    }
    return 0;
}
