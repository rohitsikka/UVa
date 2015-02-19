#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    freopen("temp.txt","r",stdin);
    long long int t,n,a,b,c,ans;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            ans+=a*c;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
