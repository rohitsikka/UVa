#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;
int main()
{
    freopen("temp.txt","r",stdin);
    int n,m,plot[110][110],c,t;
    long long int DP[110],curCost,minCost;
    int curArea,maxArea;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d %d",&n,&m,&c);
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++)
                scanf("%d",&plot[j][k]);
        maxArea=0;
        minCost=0;
        for(int j=0;j<n;j++)
        {
            memset(DP,0,sizeof(DP));
            for(int k=j;k<n;k++)
            {
                for(int l=0;l<m;l++)
                    DP[l]+=plot[k][l];
                curCost=0;
                curArea=0;
                int h=0;
                for(int l=0;l<m;l++)
                {
                    curCost+=DP[l];
                    while(curCost>c)
                        curCost-=DP[h++];
                    curArea=(k-j+1)*(l-h+1);
                    if(curArea>maxArea)
                    {
                        maxArea=curArea;
                        minCost=curCost;
                    }
                    else if(curArea==maxArea)
                        minCost=min(curCost,minCost);
                }
            }
        }
        printf("Case #%d: %d %lld\n",i,maxArea,minCost);
    }
    return 0;
}
