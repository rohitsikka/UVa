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

#define s(n) scanf("%lld",&n)
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
   ll nx,ny,q,temp;
   x=ny=1;
   y=nx=0;
   while(b)
   {
      q=a/b;
      temp=a;a=b;b=temp%b;
      temp=nx;nx=x-q*nx;x=temp;
      temp=ny;ny=y-q*ny;y=temp;
   }
   return a;
}
bool linearDiophantine(ll a,ll b,ll c,ll &x,ll &y)
{
   ll d=extendedEuclid(a,b,x,y);
   if(c%d)  return false;
   x*=c/d;
   y*=c/d;
   return true;
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   ll t,p,q,x,k;
   s(t);
   while(t--)
   {
      s(x);
      s(k);
      linearDiophantine(x/k,ceil((double)x/k),x,p,q);
      printf("%lld %lld\n",p,q);
   }
   return 0;
}
