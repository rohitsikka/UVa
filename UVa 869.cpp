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
   int t,n,m;
   char a,b;
   int adjMatA[128][128];
   int adjMatB[128][128];
   s(t);
   while(t--)
   {
      getchar();
      scanf("%d\n",&n);
      fora(i,0,128)
         fora(j,0,128)
            adjMatB[i][j]=adjMatA[i][j]=0;
      fora(i,0,n)
      {
         scanf("%c %c\n",&a,&b);
         adjMatA[a][b]=1;
      }
      scanf("%d\n",&m);
      fora(i,0,m)
      {
         scanf("%c %c\n",&a,&b);
         adjMatB[a][b]=1;
      }
       fora(k,0,128)
         fora(i,0,128)
            fora(j,0,128)
            {
               adjMatA[i][j]= adjMatA[i][j]||(adjMatA[i][k]&&adjMatA[k][j]);
               adjMatB[i][j]= adjMatB[i][j]||(adjMatB[i][k]&&adjMatB[k][j]);
            }


      bool flag=true;
      fora(i,0,128&&flag)
         fora(j,0,128)
            if(adjMatA[i][j]!=adjMatB[i][j])
               flag=false;
      if(flag)
         printf("YES\n");
      else
         printf("NO\n");
      if(t)
         printf("\n");
   }
   return 0;
}
