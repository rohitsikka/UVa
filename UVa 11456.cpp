#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,cars[2010];
void lisLds(int arr[],int n,int LIS[],int LDS[])
{
    for(int i=n-1;i>=0;i--)
    {
        LIS[i]=1;
        LDS[i]=1;
       for(int j=n-1;j>i;j--)
       {
            if(arr[j]<arr[i])
               LIS[i]=max(LIS[i],LIS[j]+1);
            else if(arr[j]>arr[i])
               LDS[i]=max(LDS[i],LDS[j]+1);
       }
    }
}

int solve()
{
    int LIS[2010],LDS[2010],ans=0;
    lisLds(cars,n,LIS,LDS);
    for(int i=0;i<n;i++)
        ans=max(ans,LIS[i]+LDS[i]-1);
    return ans;
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d",&cars[i]);
        cout<<solve()<<"\n";
    }
    return 0;
}
