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

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
    freopen("temp.txt","r",stdin);
    int t,n,m;
    int x,y,z;
    vector<vii> adjList;
    int dist[1010];
    s(t);
    while(t--)
    {
       s(n);
       s(m);
       adjList.assign(n,vii());
       fora(i,0,m)
       {
          s(x);
          s(y);
          s(z);
          adjList[x].pb(mp(y,z));
       }

       fora(i,0,n)
         dist[i]=INT_MAX;
      dist[0]=0;
      ii v;
      fora(i,0,n-1)
         fora(j,0,n)
            fora(k,0,(int)adjList[j].size())
            {
               v=adjList[j][k];
               dist[v.fi]=min(dist[v.fi],v.se+dist[j]);
            }
      bool hasNegCycle=false;
         fora(j,0,n&&!hasNegCycle)
            fora(k,0,(int)adjList[j].size()&&!hasNegCycle)
            {
               v=adjList[j][k];
               if(dist[v.fi]>v.se+dist[j])
               {
                  hasNegCycle=true;
               }
            }
      if(hasNegCycle)
         printf("possible\n");
      else
         printf("not possible\n");

    }
    return 0;
}
