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

int noPrimes;
vector<int> primes;
bitset <10001000> sieve;
void sieveOfErastosthenes()
{
    noPrimes=0;
    primes.clear();
    primes.push_back(2);
    sieve.set();
    sieve.set(0,false);
    sieve.set(1,false);
    int m=sqrt(10001000);
    for(int i=3;i<=m;i+=2)
    {
        if(sieve.test((size_t)i))
        {
            for(int j=i*i;j<10001000;j+=i+i)
                sieve.set(j,false);
            primes.push_back(i);
        }
    }
    for(int i=3163;i<10001000;i+=2)
        if(sieve.test((size_t)i))
            primes.push_back(i);
}

int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   ll n;
   ll ans,counter;
   sieveOfErastosthenes();
   while(scanf("%lld",&n)&&n)
   {
      n=abs(n);
      ans=0;
      counter=0;
      fora(i,0,primes.size())
      {
         if(n==1) break;
         if(n%primes[i]==0)
         {
            counter++;
            if(counter>1)
               ans=primes[i];
            while(n%primes[i]==0)
            {
               n/=primes[i];
            }
         }
      }
      if(n!=1)
         if(counter>=1) ans=n;
      if(ans==0)
         puts("-1");
      else
         printf("%lld\n",ans);
   }
   return 0;
}
