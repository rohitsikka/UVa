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
      void clear(int n)
      {
         rank.assign(n,0);
         setSize.assign(n,1);
         p.assign(n,0);
         fora(i,0,n)
            p[i]=i;
         numSets=n;
      }
      int getNumSets()
      {
         return numSets;
      }
      int getSetSize(int n)
      {
         return setSize[n];
      }
};
int main()
{
   freopen("temp.txt","r",stdin);
   int t,m,n,a,b,c,minCost,curMinCost,maxSetSize;
   vector<pair<int,ii> > edgeList;
   pair<int,ii> v;
   bitset<100100> mark;
   s(t);
   while(t--)
   {
      s(n);
      s(m);
      edgeList.clear();
      fora(i,0,m)
      {
         s(a);
         s(b);
         s(c);
         edgeList.pb(mp(c,mp(a,b)));
      }
      sort(all(edgeList));
      Set uf(n+1);
      minCost=0;
      mark.reset();
      fora(i,0,edgeList.size())
      {
         v=edgeList[i];
         if(!uf.sameSet(v.se.fi,v.se.se))
         {
            minCost+=v.fi;
            uf.unionSet(v.se.fi,v.se.se);
            mark[i]=1;
         }
      }
      printf("%d",minCost);
      minCost=INT_MAX;
      fora(i,0,edgeList.size())
      {
         if(mark[i])
         {
            uf.clear(n+1);
            curMinCost=0;
            fora(j,0,edgeList.size())
            {
               if(i!=j)
               {
                  v=edgeList[j];
                  if(!uf.sameSet(v.se.fi,v.se.se))
                  {
                     curMinCost+=v.fi;
                     uf.unionSet(v.se.fi,v.se.se);
                  }
               }

            }
            if(uf.getNumSets()==2)
               minCost=min(minCost,curMinCost);
         }
      }
      printf(" %d\n",minCost);
   }
   return 0;
}
