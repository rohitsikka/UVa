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

#define square(x) ((x)*(x))
#define dist(x,y) sqrt(square(y.fi-x.fi)+square(y.se-x.se))
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

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
   int t,e,v,x,y;
   vii cord;
   vector<pair<float,ii> > edgeList;
   pair<float,ii> u;
   float maxD;
   s(t);
   while(t--)
   {
      s(e);
      s(v);
      cord.clear();
      fora(i,0,v)
      {
         s(x);
         s(y);
         cord.pb(mp(x,y));
      }
      edgeList.clear();
      fora(i,0,cord.size())
         fora(j,0,cord.size())
            if(i!=j)
               edgeList.pb(mp(dist(cord[i],cord[j]),mp(i,j)));

      sort(all(edgeList));
      Set uf(v);
      maxD=0;
      int counter=0;
      fora(i,0,edgeList.size()&&counter<v-e)
      {
         u=edgeList[i];
         if(!uf.sameSet(u.se.fi,u.se.se))
         {
            maxD=u.fi;
            uf.unionSet(u.se.fi,u.se.se);
            counter++;
         }
      }
      printf("%.2f\n",maxD);

   }
   return 0;
}
