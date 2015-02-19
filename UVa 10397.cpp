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

#define square(x) ((double)(x)*(x))
#define dist(x,y) sqrt(square((x).fi-(y).fi)+square((x).se-(y).se))
class Set
{
   private:
      vi rank,p,setSize;
      int numSets;
   public:
      Set(int n)
      {
         rank.assign(n,0);
         setSize.assign(n,1);
         p.assign(n,0);
         fora(i,0,n)
            p[i]=i;
         numSets=n;
      }
      int findSet(int i)
      {
         return (p[i]==i)?i:p[i]=findSet(p[i]);
      }
      bool sameSet(int i,int j)
      {
         return findSet(i)==findSet(j);
      }
      void unionSet(int i,int j)
      {
         if(sameSet(i,j))
            return;
         numSets--;
         int x=findSet(i);
         int y=findSet(j);
         if(rank[x]>rank[y])
         {
            p[y]=x;
            setSize[x]+=setSize[y];
         }
         else
         {

            p[x]=y;
            setSize[y]+=setSize[x];
         }
         if(rank[x]==rank[y])
            rank[y]++;
      }
};
int main()
{
   freopen("temp.txt","r",stdin);
   int n,x,y,m;
   double minCost;
   pair<double,ii> v;
   vector<pair<double,ii> > edgeList;
   vii cord;
   while(s(n)!=EOF)
   {
      cord.clear();
      fora(i,0,n)
      {
         s(x);
         s(y);
         cord.pb(mp(x,y));
      }
      edgeList.clear();
      s(m);
      fora(i,0,m)
      {
         s(x);
         s(y);
         edgeList.pb(mp(dist(cord[x-1],cord[y-1]),mp(x,y)));
      }
      Set uf(n+1);
      fora(i,0,edgeList.size())
      {
         v=edgeList[i];
         if(!uf.sameSet(v.se.fi,v.se.se))
         {
            uf.unionSet(v.se.fi,v.se.se);
         }
      }
      edgeList.clear();
      fora(i,1,n+1)
         fora(j,1,n+1)
            if(i!=j)
               edgeList.pb(mp(dist(cord[i-1],cord[j-1]),mp(i,j)));
      minCost=0;
      sort(all(edgeList));
      fora(i,0,edgeList.size()&&done<n)
      {
         v=edgeList[i];
         if(!uf.sameSet(v.se.fi,v.se.se))
         {
            uf.unionSet(v.se.fi,v.se.se);
            minCost+=v.fi;
         }

      }
      printf("%.2f\n",minCost);
   }
   return 0;
}
