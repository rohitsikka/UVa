#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<bitset>
#include<stack>
#include<algorithm>
#include<typeinfo>

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define setBit(n,i) (n|=(1<<i))
#define clearBit(n,i) (n&=(~(1<<i)))
#define checkBit(n,i) (n&(1<<i))

#define s(n) scanf("%d",&n)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fore(i,b) for(typeof((b).begin()) i=(b).begin();i!=(b).end();i++)
#define all(a) (a).begin(),(a).end()
#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int dest;
bitset<120> color;
vector<vii> adjList;

bool dfs(int u)
{
   if(color[u])
      return false;
   if(u==dest)
      return true;
   color[u]=1;
   fora(i,0,(int)adjList[u].size())
      if(dfs(adjList[u][i].fi))
         return true;
   return false;
}
int main()
{
    freopen("temp.txt","r",stdin);
    int n,e,m,d,source;
    ii v;
    vi dist;
    while(s(n)&&n!=-1)
    {
       adjList.assign(n+1,vii());
      source=1;
      dest=n;
      fora(i,1,n+1)
      {
         s(e);
         s(m);
         e=e*-1;
         fora(j,0,m)
         {
            s(d);
            adjList[i].pb(mp(d,e));
         }
      }
      dist.assign(n+1,INF);
      dist[source]=-100;
      fora(i,1,n)
         fora(u,1,n+1)
            fora(j,0,(int)adjList[u].size())
            {
               v=adjList[u][j];
               if(dist[u]<0&&dist[v.fi]>dist[u]+v.se)
                  dist[v.fi]=dist[u]+v.se;
            }
      color.reset();
      bool hasPosCycle=false;
         fora(u,1,n+1&&!hasPosCycle)
            fora(j,0,(int)adjList[u].size())
            {
               v=adjList[u][j];
               if(dist[u]<0&&dist[v.fi]>dist[u]+v.se)
                  if(dfs(u))
                     hasPosCycle=true;
            }
      if(hasPosCycle||dist[dest]<0)
         printf("winnable\n");
      else
         printf("hopeless\n");
    }

    return 0;
}
