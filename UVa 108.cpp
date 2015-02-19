#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
using namespace std;
int n,rec[110][110];
int kadane(int arr[],int n)
{
    int currentSum=0,maxSum;
    maxSum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(currentSum<0)
            currentSum=0;
        currentSum+=arr[i];
        if(currentSum>maxSum)
            maxSum=currentSum;
    }
    return maxSum;
}
int solve()
{
    int temp[110],maxSum,sum;
    maxSum=INT_MIN;
    for(int left=0;left<n;left++)
    {
        memset(temp,0,sizeof(int)*n);
        for(int right=left;right<n;right++)
        {
            for(int i=0;i<n;i++)
                temp[i]+=rec[i][right];
            sum=kadane(temp,n);
            if(sum>maxSum)
                maxSum=sum;
        }
    }
    return maxSum;
}
int main()
{
    freopen("temp.txt","r",stdin);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&rec[i][j]);
        cout<<solve()<<"\n";
    }
    return 0;
}
