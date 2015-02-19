#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
static int b,s,nice[20010];
void solve(int rNo)
{
    int maxSum,currentSum;
    int maxLeft,maxRight,currentLeft,currentRight;
    maxSum=INT_MIN;
    currentSum=0;
    maxLeft=maxRight=currentRight=currentLeft=1;
    for(int i=1;i<s;i++)
    {
        if(currentSum<0)
        {
            currentSum=0;
            currentLeft=i;
            currentRight=i;
        }
        currentRight++;
        currentSum+=nice[i];
        if(currentSum==maxSum)
        {
            if(maxRight-maxLeft<currentRight-currentLeft)
            {
                maxSum=currentSum;
                maxRight=currentRight;
                maxLeft=currentLeft;
            }
        }
        if(currentSum>maxSum)
        {
            maxSum=currentSum;
            maxRight=currentRight;
            maxLeft=currentLeft;
        }
    }
    if(maxSum>=0)
        cout<<"The nicest part of route "<<rNo<<" is between stops "<<maxLeft<<" and "<<maxRight;
    else
        cout<<"Route "<<rNo<<" has no nice parts";
}
int main()
{
    int rNo=1;
    freopen("temp.txt","r",stdin);
    cin>>b;
    while(b--)
    {
        cin>>s;
        for(int i=1;i<s;i++)
            scanf("%d",&nice[i]);  //niceness bw stops i to (i+1)
        solve(rNo);
        cout<<"\n";
        rNo++;
    }
    return 0;
}
