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
#define MOD 100000000000
vector<int> primes;
bitset <1000100> sieve;
void sieveOfErastosthenes()
{
    primes.clear();
    primes.push_back(2);
    sieve.set();
    sieve.set(0,false);
    sieve.set(1,false);
    int m=sqrt(1000100);
    for(int i=3;i<=m;i+=2)
    {
        if(sieve.test((size_t)i))
        {
            for(int j=i*i;j<1000100;j+=i+i)
                sieve.set(j,false);
            primes.push_back(i);
        }
    }
    for(int i=1001;i<1000100;i+=2)
        if(sieve.test((size_t)i))
            primes.push_back(i);
}
ll gcd(ll a,ll b)
{
   ll temp;
   while(b)
   {
      temp=a;
      a=b;
      b=temp%b;
   }
   return a;
}
ll lcm(ll a,ll b)
{
   return a/gcd(a,b)*b;
}
ll power(ll a,ll b)
{
   ll res=1;
   while(b)
   {
      if(b%2==1)  res=(res*a)%MOD;
      a=(a*a)%MOD;
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
   ll n,j,k;
   ll LCM;
   while(s(n)&&n)
   {
      LCM=1;
      fora(i,0,primes.size())
      {
         if(primes[i]>n)   break;
         j=primes[i];
         k=0;
         do
         {
            j*=primes[i];
            k++;
         }while(j<=n);
         LCM=(LCM*power(primes[i],k))%MOD;
         while(LCM%10==0)
         {
            LCM/=10;
         }
      }
      printf("%d\n",LCM%10);
   }
   return 0;
}
