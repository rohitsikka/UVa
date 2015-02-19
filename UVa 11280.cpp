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

int main()
{
    freopen("temp.txt","r",stdin);
    int n,t,o,q,cost;
    ii v;
    string str1,str2;
    bool hasNegCycle;
    map<string,int> m;
    vector<vii> adjList;
    vi dist,stops;
    s(t);
    t++;
    fora(i,1,t)
    {
      printf("Scenario #%d\n",i);
      getchar();
      m.clear();
      s(n);
      fora(j,0,n)
      {
         cin>>str1;
         m[str1]=j;
      }
      adjList.assign(n,vii());
      s(o);
      fora(j,0,o)
      {
         cin>>str1;
         cin>>str2;
         s(cost);
         adjList[m[str1]].pb(mp(m[str2],cost));
      }
      s(o);
      fora(j,0,o)
      {
         s(q);
         dist.assign(n,INF);
         dist[0]=0;
         fora(k,0,q+1)
            for(int u=n-1;u>=0;u--)
               fora(l,0,(int)adjList[u].size())
               {
                  v=adjList[u][l];
                  if(dist[v.fi]>v.se+dist[u])
                  {
                     dist[v.fi]=v.se+dist[u];
                  }
               }
         if(dist[n-1]==INF)
            printf("No satisfactory flights\n");
         else
            printf("Total cost of flight(s) is $%d\n",dist[n-1]);
      }
      if(i!=t-1)
         printf("\n");
    }
    return 0;
}
