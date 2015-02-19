#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<bitset>
#include<cstring>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main()
{
    freopen("temp.txt","r",stdin);
    vector<vi> adjList;
    int n,l,a,b,dist[210];
    bitset<210> color;
    bool isBipartite;
    while(scanf("%d",&n)&&n)
    {
        adjList.assign(n,vi());
        scanf("%d",&l);
        for(int i=0;i<l;i++)
        {
            scanf("%d %d",&a,&b);
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        isBipartite=true;
        dist[0]=0;
        color.reset();
        color[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()&&isBipartite)
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<adjList[u].size();i++)
            {
                int v=adjList[u][i];
                if(!color[v])
                {

                    color[v]=1;
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
                else if((dist[u]%2)==(dist[v]%2))
                    isBipartite=false;
            }
        }
        if(isBipartite)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
