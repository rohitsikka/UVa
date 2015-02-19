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
#define lsBit(n) ((n)&(-n))

#define s(n) scanf("%d",&n)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(__typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define ms(a,b) memset(a,b,sizeof(a))
#define all(a) (a).begin(),(a).end()

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long int ll;

int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   int n,t;
   vi pf;
   while(s(n)&&n)
   {
      pf.clear();
      t=n;
      if(n<0)
         pf.pb(-1);
      n=abs(n);
      while(n%2==0)
      {
         pf.pb(2);
         n/=2;
      }
      int m=sqrt(n);
      for(int i=3;i<=m;i+=2)
         while(n%i==0)
         {
            n/=i;
            pf.pb(i);
         }
      if(n>1)
         pf.pb(n);
      printf("%d = %d",t,pf[0]);
      fora(i,1,pf.size())
         printf(" x %d",pf[i]);
      printf("\n");
   }
   return 0;
}
