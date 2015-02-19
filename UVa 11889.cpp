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
vector<int> primes;
bitset <1000001> sieve;
void sieveOfErastosthenes()
{
    primes.clear();
    primes.push_back(2);
    sieve.set();
    sieve.set(0,false);
    sieve.set(1,false);
    int m=sqrt(1000001);
    for(int i=3;i<=m;i+=2)
    {
        if(sieve.test((size_t)i))
        {
            for(int j=i*i;j<1000001;j+=i+i)
                sieve.set(j,false);
            primes.push_back(i);
        }
    }
    if(m%2==0) m++;
    for(int i=m;i<1000001;i+=2)
        if(sieve.test((size_t)i))
            primes.push_back(i);
}
ll power(ll a,ll b)
{
   ll res=1;
   while(b)
   {
      if(b%2==1)  res*=a;
      a*=a;
      b/=2;
   }
   return res;
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   sieveOfErastosthenes();
   ll t,a,b,c,counterA,counterC,temp;
   s(t);
   while(t--)
   {
      s(a);
      s(c);
      if(c%a!=0)
      {
         puts("NO SOLUTION");
         continue;
      }
      b=1;
      temp=c;
      fora(i,0,primes.size())
      {
         if(primes[i]*primes[i]>temp) break;
         counterA=0;
         while(a%primes[i]==0)
         {
            a/=primes[i];
            counterA++;
         }
         counterC=0;
         while(c%primes[i]==0)
         {
            c/=primes[i];
            counterC++;
         }
         if(counterC>counterA)   b*=power(primes[i],counterC);
      }
      if (c>1&&a==1) b*=c;
      printf("%lld\n",b);
   }
   return 0;
}
