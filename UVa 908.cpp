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
      int findSet(int n)
      {
         return ((p[n]==n)?n:p[n]=findSet(p[n]));
      }
      bool isSameSet(int i,int j)
      {
         return (findSet(i)==findSet(j));
      }
      void unionSet(int i,int j)
      {
         if(isSameSet(i,j))
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
    int n,a,b,c,k,m;
    int costn,costk;
    vector<pair<int,ii> > edgeList;
    bool flag=false;
    while(s(n)!=EOF)
    {
       if(flag)
         printf("\n");
       flag=true;
       edgeList.assign((n*n-n)/2+15,pair<int,ii>());
       costn=0;
       fora(i,1,n)
       {
          s(a);
          s(b);
          s(c);
          costn+=c;
       }
       s(k);
       fora(i,0,k)
       {
          s(a);
          s(b);
          s(c);
          edgeList.pb(mp(c,mp(a,b)));
       }
       s(m);
       fora(i,0,m)
       {
          s(a);
          s(b);
          s(c);
          edgeList.pb(mp(c,mp(a,b)));
       }
       sort(all(edgeList));
       Set uf((n*n-n)/2+15);
       costk=0;
       pair<int,ii> v;
       fora(i,0,edgeList.size())
       {
          v=edgeList[i];
         if(!uf.isSameSet(v.se.fi,v.se.se))
         {
            costk+=v.fi;
            uf.unionSet(v.se.fi,v.se.se);
         }
       }
       printf("%d\n%d\n",costn,costk);
    }
    return 0;
}
