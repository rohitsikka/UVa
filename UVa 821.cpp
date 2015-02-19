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
#include<set>
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
#define fore(i,a,b) for(a i=(b).begin();i!=(b).end();i++)
#define all(a) (a).begin(),(a).end()

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
   freopen("temp.txt","r",stdin);
   int t=1,a,b,adjMat[110][110],n;
   set<int> m;
   while(s(a)&&s(b))
   {
      m.clear();
      fora(i,0,110)
         fora(j,0,110)
            adjMat[i][j]=INF;
      if(a==0&&b==0)
         break;
      m.insert(a);
      m.insert(b);
      adjMat[a][b]=1;
      while(s(a)&&s(b))
      {
         if(a==0&&b==0)
            break;
         adjMat[a][b]=1;
         m.insert(a);
         m.insert(b);
      }
      n=m.size();
      for(set<int>::iterator i=m.begin();i!=m.end();i++)
         adjMat[*i][*i]=0;
      for(set<int>::iterator k=m.begin();k!=m.end();k++)
        for(set<int>::iterator i=m.begin();i!=m.end();i++)
            for(set<int>::iterator j=m.begin();j!=m.end();j++)
               adjMat[*i][*j]=min(adjMat[*i][*j],adjMat[*i][*k]+adjMat[*k][*j]);
      int total=0;
      for(set<int>::iterator i=m.begin();i!=m.end();i++)
         for(set<int>::iterator j=m.begin();j!=m.end();j++)
            if(adjMat[*i][*j]<INF)
               total+=adjMat[*i][*j];
      double ans;
      ans=total/((double)n*(n-1));
      printf("Case %d: average length between pages = %.3f clicks\n",t,ans);
      t++;
   }
   return 0;
}
