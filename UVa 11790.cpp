#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
pair<int , int>bul[10000];
int l[10000];
int LIS()
{
    for(int i=0;i<n;i++)
    {
        l[i]=bul[i].second;
        for(int j=0;j<i;j++)
        {
            if(bul[i].first>bul[j].first)
                l[i]=max(l[i],l[j]+bul[i].second);
        }
    }
    int maximum=l[0];
    for(int i=0;i<n;i++)
        maximum=max(maximum,l[i]);
    return maximum;
}
void solve()
{
    int lis=LIS();
    for(int i=0,j=n-1;i<n/2;i++,j--)
        swap(bul[i],bul[j]);
    int lds=LIS();
    if(lis>=lds)
        cout<<"Increasing ("<<lis<<"). Decreasing ("<<lds<<").";
    else
        cout<<"Decreasing ("<<lds<<"). Increasing ("<<lis<<").";
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=0;j<n;j++)
            scanf("%d",&bul[j].first);

        for(int j=0;j<n;j++)
            scanf("%d",&bul[j].second);

        cout<<"Case "<<i<<". ";
        solve();
        cout<<"\n";
    }
    return 0;
}
