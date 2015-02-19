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
#define all(a) (a).begin(),(a).end()

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
   freopen("temp.txt","r",stdin);
   int t,n,m,a,b,source,destination;
   int adjMat[110][110];
   s(t);
   fora(q,1,t+1)
   {
      s(n);
      fora(i,0,n)
         fora(j,0,n)
            adjMat[i][j]=INF;
      fora(i,0,n)
         adjMat[i][i]=0;
      s(m);
      fora(i,0,m)
      {
         s(a);
         s(b);
         adjMat[a][b]=1;
         adjMat[b][a]=1;
      }
      s(source);
      s(destination);

      fora(k,0,n)
         fora(i,0,n)
            fora(j,0,n)
               adjMat[i][j]=min(adjMat[i][j],adjMat[i][k]+adjMat[k][j]);

      int maximum=0;
      fora(i,0,n)
         maximum=max(maximum,adjMat[source][i]+adjMat[i][destination]);
      printf("Case %d: %d\n",q,maximum);
   }
   return 0;
}
