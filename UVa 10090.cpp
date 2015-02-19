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
ll extendedEuclid(ll a,ll b,ll &x,ll &y)
{
   if(b==0){x=1;y=0;return a;}
   ll nx,ny;
   ll d=extendedEuclid(b,a%b,nx,ny);
   x=ny;
   y=nx-(a/b)*ny;
   return d;
}
ll linearDiophantine(ll a,ll b,ll c,ll &x,ll &y)
{
   ll d=extendedEuclid(a,b,x,y);
   if(c%d)
      return -1;
   x*=c/d;
   y*=c/d;
   return d;
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   ll n,n1,n2,c1,c2,x,y,mi,d,ce,fl,ans,fun;
   bool flag=false;
   int pos;
   while(scanf("%lld",&n)&&n)
   {
      scanf("%lld %lld",&c1,&n1);
      scanf("%lld %lld",&c2,&n2);
      d=linearDiophantine(n1,n2,n,x,y);
      if(d==-1)
      {
         printf("failed\n");
         continue;
      }
      n1/=d;
      n2/=d;
      fun=(c1*n2-c2*n1);
      ce=ceil(-(double)x/n2);
      fl=floor((double)y/n1);
      if(ce>fl)
      {
         printf("failed\n");
         continue;
      }
      if(ce*fun<fl*fun)
      {
         x+=(n2*ce);
         y-=(n1*ce);
      }
      else
      {
         x+=(n2*fl);
         y-=(n1*fl);
      }
      printf("%lld %lld\n",x,y);
   }
   return 0;
}


