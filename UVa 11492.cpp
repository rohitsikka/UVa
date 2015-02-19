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

#define INF 1e8
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct node
{
   int i,d,le;
   node(ii a,int c)
   {
      i=a.fi;
      d=a.se;
      le=c;
   }
   bool operator<(const node& rhs) const
   {
      return this->d > rhs.d;
   }
};
int main()
{
   freopen("temp.txt","r",stdin);
   //std::ios_base::sync_with_stdio(false);
   int n;
   string a,b,c,stra,strb;
   vector<vii> adjList;
   vector<vi> letter;
   int dist[4500][26];
   int count=0;
   while(cin>>n&&n)
   {
      adjList.assign(2*n+2,vii());
      letter.assign(2*n+2,vi());
      map<string,int> m;
      count=0;
      cin>>stra>>strb;
      if(stra==strb)
      {
         printf("0\n");
         fora(i,0,n)
            cin>>a>>b>>c;
         continue;
      }
      fora(i,0,n)
      {
         cin>>a>>b>>c;

         if(m.find(a)==m.end())
            m[a]=count++;
         if(m.find(b)==m.end())
            m[b]=count++;
         adjList[m[a]].pb(mp(m[b],c.length()));
         adjList[m[b]].pb(mp(m[a],c.length()));
         letter[m[a]].pb(c[0]-'a');
         letter[m[b]].pb(c[0]-'a');
      }
      if(m.find(stra)==m.end()||m.find(strb)==m.end())
      {
         printf("impossivel\n");
         continue;
      }
      node u(mp(m[stra],0),-1);
      ii v;
      priority_queue<node> pq;
      pq.push(u);
      fora(i,0,count)
        fora(j,0,26)
         dist[i][j]=INF;
      fora(i,0,26)
         dist[m[stra]][i]=0;
      while(!pq.empty())
      {
         u=pq.top();
         pq.pop();
         fora(i,0,adjList[u.i].size())
         {
            v=adjList[u.i][i];
            int head=letter[u.i][i];
            if( u.le!=head&&u.d+v.se<dist[v.fi][head])
            {
               dist[v.fi][head]=u.d+v.se;
               pq.push(node(mp(v.fi,dist[v.fi][head]),head));
            }
         }
      }
      int ans=INF;
      fora(i,0,26)
         ans=min(ans,dist[m[strb]][i]);
      if(ans>=INF)
         printf("impossivel\n");
      else
         printf("%d\n",ans);
   }
   return 0;
}
