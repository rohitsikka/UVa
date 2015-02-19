#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;
int t,n,arr[80][80];
int kadane(int arr[],int n)
{
    int maxSum,currentSum;
    currentSum=0;
    maxSum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(currentSum<0)
            currentSum=0;
        currentSum+=arr[i];
        maxSum=max(currentSum,maxSum);
    }
    return maxSum;
}
int wrapKadane(int arr[],int n)
{
    int currentSum=kadane(arr,n);

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        arr[i]=-arr[i];
    }
    int invSum=kadane(arr,n);
    invSum=sum+invSum;
    for(int i=0;i<n;i++)
        arr[i]=-arr[i];
    return max(currentSum,invSum);
}
int solve()
{
    int temp[80],right;
    int sum,maxSum=INT_MIN;
    for(int left=0;left<n;left++)
    {
        right=left;
        memset(temp,0,sizeof(temp));
        do
        {
            for(int i=0;i<n;i++)
                temp[i]+=arr[i][right];
            sum=wrapKadane(temp,n);

            maxSum=max(maxSum,sum);
            right=(right+1)%n;
        }while(right!=left);
    }
    return maxSum;
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&arr[i][j]);
        cout<<solve()<<"\n";
    }
    return 0;
}
