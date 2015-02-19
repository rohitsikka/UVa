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
};
int main()
{
   freopen("temp.txt","r",stdin);
   int n,m,a,b,c;
   vector<pair<int,ii> > edgeList;
   vi ans;
   while(s(n)&&s(m))
   {
      if(n==0&&m==0)
         break;
      edgeList.clear();
      ans.clear();
      fora(i,0,m)
      {
         s(a);
         s(b);
         s(c);
         edgeList.pb(mp(c,mp(a,b)));
      }

      sort(all(edgeList));
      Set uf(n);
      pair<int,ii> v;
      fora(i,0,edgeList.size())
      {
         v=edgeList[i];
         if(uf.sameSet(v.se.fi,v.se.se))
            ans.pb(v.fi);
         uf.unionSet(v.se.fi,v.se.se);
      }
      if(ans.size())
      {
         printf("%d",ans[0]);
         fora(i,1,ans.size())
            printf(" %d",ans[i]);
      }
      else
         printf("forest");
      printf("\n");
      }
   return 0;
}
