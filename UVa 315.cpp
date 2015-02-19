#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef vector<int> vi;
vector<vi> adjList;
int n,v,a,dfsCount,dfsTime[120],dfsLow[120],parent[120];
bitset<120> color;
bitset<120> aV;
char inp[500];
void articulatedPoints(int u)
{
    dfsTime[u]=dfsLow[u]=dfsCount++;
    color[u]=1;
    int children=0;
    for(int i=0;i<adjList[u].size();i++)
    {
        int v=adjList[u][i];
        if(!color[v])
        {
            children++;
            parent[v]=u;
            articulatedPoints(v);
            dfsLow[u]=min(dfsLow[v],dfsLow[u]);
            if(parent[u]==0&&children>1)
                aV[u]=1;
            if(parent[u]!=0&&dfsLow[v]>=dfsTime[u])
               aV[u]=1;
        }
        else if(parent[u]!=v)
            dfsLow[u]=min(dfsLow[u],dfsTime[v]);
    }
}
void format(char *s,int v)
{
    char *pch=strtok(s," ");
    while(pch!=NULL)
    {
        a=atoi(pch);
        adjList[a].push_back(v);
        adjList[v].push_back(a);
        pch=strtok(NULL," ");
    }
}
int main()
{
    freopen("temp.txt","r",stdin);
    while(scanf("%d",&n)&&n)
    {
        getchar();
        adjList.assign(n+5,vi());
        while(scanf("%d ",&v)&&v)
        {
            gets(inp);
            format(inp,v);

        }
        color.reset();
        aV.reset();
        memset(parent,0,sizeof(parent));
        dfsCount=0;
        for(int i=1;i<=n;i++)
            if(!color[i])
                articulatedPoints(i);
        cout<<aV.count()<<"\n";
    }
    return 0;
}
