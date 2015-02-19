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
typedef long long ll;

ll gcd(ll a,ll b)
{
   ll t;
   while(b)
   {
      t=a;
      a=b;
      b=t%b;
   }
   return a;
}
inline ll LCM(ll a,ll b)
{
   return a/gcd(a,b)*b;
}
int main()
{
   freopen("temp.txt","r",stdin);
   int n,m;
   ll arr[550];
   ll ansMin,lcm,lcm1,lcm2,q,tMin,tMax,ansMax;
   while(scanf("%d %d",&n,&m)&&(n||m))
   {
      fora(i,0,n)
      {
         scanf("%lld",&arr[i]);
      }
      fora(i,0,m)
      {
         ansMin=0;
         ansMax=INT_MAX;
         scanf("%lld",&q);
         fora(j,0,n)
         fora(k,j+1,n)
         {
            lcm1=LCM(arr[j],arr[k]);
            fora(l,k+1,n)
            {
                lcm2=LCM(arr[l],lcm1);
                fora(o,l+1,n)
               {
                  lcm=LCM(arr[o],lcm2);
                     tMax=tMin=lcm*(q/lcm);
                  if(tMin!=q)
                     tMax=lcm+tMin;
                  if(q-tMin<q-ansMin)
                     ansMin=tMin;
                  if(tMax-q<ansMax-q)
                     ansMax=tMax;
               }
            }

         }

         printf("%lld %lld\n",ansMin,ansMax);
      }
   }
   return 0;
}
