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
   int n,m,q,counter,source,dest,a,b,d;
   int adjMat[110][110];
   bool blank=false;
   counter=1;
   while(scanf("%d %d %d",&n,&m,&q))
   {
      if(!(n||m||q))
         break;
      if(blank)
         printf("\n");
      blank=true;
      fora(i,0,n+1)
         fora(j,0,n+1)
            adjMat[i][j]=INF;
      fora(i,0,m)
      {
         scanf("%d %d %d",&a,&b,&d);
         adjMat[a][b]=d;
         adjMat[b][a]=d;
      }
      fora(k,1,n+1)
         fora(i,1,n+1)
            fora(j,1,n+1)
               adjMat[j][i]=adjMat[i][j]=min(adjMat[i][j],max(adjMat[i][k],adjMat[k][j]));
      printf("Case #%d\n",counter);
      counter++;
      fora(i,0,q)
      {
         scanf("%d %d",&source,&dest);
         if(adjMat[source][dest]==INF)
            puts("no path");
         else
            printf("%d\n",adjMat[source][dest]);
      }
   }
   return 0;
}
