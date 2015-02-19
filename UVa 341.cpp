#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#define INF 10000000
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int s;
int parent[15],dist[15];
vector<vii> adjList;
void printPath(int u)
{
    if(u==s)
    {
        printf(" %d",u);
        return;
    }
    printPath(parent[u]);
    printf(" %d",u);
}
int main()
{
    freopen("temp.txt","r",stdin);
    int n,m,a,b,e,u,d;
    ii t,v;
    int caseNo=0;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        caseNo++;
        adjList.assign(n+1,vii());
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d %d",&a,&b);
                adjList[i].push_back(ii(a,b));
            }
        }
        scanf("%d %d",&s,&e);



        priority_queue<ii,vii,greater<ii> > pq;
        pq.push(ii(0,s));
        parent[s]=0;
        for(int i=0;i<15;i++)
            dist[i]=INF;
        dist[s]=0;
        while(!pq.empty())
        {
            t=pq.top();
            pq.pop();
            u=t.second;
            d=t.first;
            if(u==e)
                break;
            if(dist[u]==d)
            {
                for(int i=0;i<adjList[u].size();i++)
                {
                    v=adjList[u][i];
                    if(dist[u]+v.second<dist[v.first])
                    {
                        dist[v.first]=dist[u]+v.second;
                        parent[v.first]=u;
                        pq.push(ii(dist[v.first],v.first));
                    }
                }
            }

        }
        printf("Case %d: Path =",caseNo);
        printPath(e);
        printf("; %d second delay\n",dist[e]);
    }
    return 0;
}
