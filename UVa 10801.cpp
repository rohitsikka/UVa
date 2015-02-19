#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<queue>
using namespace std;
struct graph
{
    int t;
    bitset<105> f;
}g[6];
struct floorInfo
{
    int fNo;
    int cost;
    int lNo;

}t,temp;
bool operator<(floorInfo lhs,floorInfo rhs)
{
        return lhs.cost > rhs.cost;
}
int main()
{
    freopen("temp.txt","r",stdin);
    int n,k;
    char inp[1000];
    char *pch;
    int dist[6][110];
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d ",&g[i].t);
            g[i].f.reset();
        }
        for(int i=0;i<n;i++)
        {
            gets(inp);
            pch=strtok(inp," ");
            while(pch!=NULL)
            {
                g[i].f[atoi(pch)]=1;
                pch=strtok(NULL," ");
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<=100;j++)
                dist[i][j]=INT_MAX;

        priority_queue<floorInfo> pq;
        for(int i=0;i<n;i++)
        {
            if(g[i].f[0])
            {
                t.lNo=i;
                t.cost=0;
                t.fNo=0;
                pq.push(t);
                dist[i][0]=0;
            }
        }

        while(!pq.empty())
        {
            t=pq.top();
            pq.pop();
            if(t.cost==dist[t.lNo][t.fNo])
            {
                for(int i=0;i<=100;i++)
                {
                    if(g[t.lNo].f[i])
                    {
                        int tCost=t.cost+g[t.lNo].t*abs(i-t.fNo);
                        if(tCost<dist[t.lNo][i])
                        {
                            dist[t.lNo][i]=tCost;
                            temp.lNo=t.lNo;
                            temp.fNo=i;
                            temp.cost=tCost;
                            pq.push(temp);
                        }
                    }
                }
                for(int i=0;i<n;i++)
                {
                    if(g[i].f[t.fNo])
                    {
                            temp.fNo=t.fNo;
                            temp.lNo=i;
                            temp.cost=t.cost+60;
                            if(temp.cost<dist[i][t.fNo])
                            {
                                dist[i][t.fNo]=temp.cost;
                                pq.push(temp);
                            }
                    }
                }
            }
        }
        int minimum=INT_MAX;
        for(int i=0;i<n;i++)
            minimum=min(dist[i][k],minimum);
        if(minimum==INT_MAX)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",minimum);
    }
    return 0;
}
