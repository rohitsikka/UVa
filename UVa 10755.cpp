#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;
long long int kadane(long long int arr[],int n)
{
    long long int curMax=0;
    long long int maximum=LONG_LONG_MIN;
    for(int i=0;i<n;i++)
    {
        curMax=max(curMax,0LL);
        curMax+=arr[i];
        maximum=max(maximum,curMax);
    }
    return maximum;
}
int main()
{
    int t,a,b,c;
    freopen("temp.txt","r",stdin);
    scanf("%d",&t);
    long long int g[25][25][25];
    long long int DP1[25][25];
    long long int DP2[25];
    long long int maxSum,sum;
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                for(int k=0;k<c;k++)
                    scanf("%lld",&g[i][j][k]);
        maxSum=LONG_LONG_MIN;
        for(int i=0;i<a;i++)
        {
            memset(DP1,0,sizeof(DP1));
            for(int j=i;j<a;j++)
            {
                for(int k=0;k<b;k++)
                    for(int l=0;l<c;l++)
                        DP1[k][l]+=g[j][k][l];

                for(int k=0;k<b;k++)
                {
                    memset(DP2,0,sizeof(DP2));
                    for(int l=k;l<b;l++)
                    {
                        for(int m=0;m<c;m++)
                            DP2[m]+=DP1[l][m];
                        sum=kadane(DP2,c);
                        maxSum=max(sum,maxSum);
                    }
                }
            }
        }
        printf("%lld\n",maxSum);
        if(t)
            printf("\n");
    }
    return 0;
}
