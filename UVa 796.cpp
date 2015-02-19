#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<algorithm>
#define MP make_pair
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
vector<vi> adjList;
vector<ii> bridge;
bitset<200> color;
int dfsTime[200],dfsLow[200],parent[200],dfsCount;
int V;
void findBridges(int u)
{
    dfsTime[u]=dfsLow[u]=dfsCount++;
    color[u]=true;
    for(int i=0;i<adjList[u].size();i++)
    {
        int v=adjList[u][i];
        if(!color[v])
        {
            parent[v]=u;
            findBridges(v);
            dfsLow[u]=min(dfsLow[u],dfsLow[v]);
            if(dfsTime[u]<dfsLow[v])
            {
                if(u<v)
                    bridge.push_back(MP(u,v));
                else
                    bridge.push_back(MP(v,u));
            }

        }
        else if(parent[u]!=v)
            dfsLow[u]=min(dfsLow[u],dfsTime[v]);
    }
}
int main()
{
    freopen("temp.txt","r",stdin);
    int a,n,b;
    while(scanf("%d",&V)!=EOF)
    {
        adjList.assign(V+5,vi());
        for(int i=0;i<V;i++)
        {
            scanf("%d (%d)",&a,&n);
            for(int j=0;j<n;j++)
            {
                scanf("%d",&b);
                adjList[a].push_back(b);
                adjList[b].push_back(a);
            }
        }
        color.reset();
        bridge.clear();
        dfsCount=0;
        memset(parent,0,sizeof(parent));
        for(int i=0;i<V;i++)
            if(!color[i])
                findBridges(i);
        sort(bridge.begin(),bridge.end());
        printf("%d critical links\n",bridge.size());
        for(int i=0;i<bridge.size();i++)
            printf("%d - %d\n",bridge[i].first,bridge[i].second);

        printf("\n");
    }
    return 0;
}
