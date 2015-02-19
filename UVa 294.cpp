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
#define NOPRIMES 1000000
vector<int> primes;
bitset <NOPRIMES> sieve;
void sieveOfErastosthenes()
{
    primes.clear();
    primes.push_back(2);
    sieve.set();
    sieve.set(0,false);
    sieve.set(1,false);
    int m=sqrt(NOPRIMES);
    for(int i=3;i<=m;i+=2)
    {
        if(sieve.test((size_t)i))
        {
            for(int j=i*i;j<NOPRIMES;j+=i+i)
                sieve.set(j,false);
            primes.push_back(i);
        }
    }
    if(m%2==0) m++;
    for(int i=m;i<NOPRIMES;i+=2)
        if(sieve.test((size_t)i))
            primes.push_back(i);
}
int noDivisor(int n)
{
   int i=0;
   int temp=n;
   int res=1;
   int counter;
   while(primes[i]*primes[i]<=temp&&i<primes.size()&&n>1)
   {
      counter=1;
      while(n%primes[i]==0)
      {
         counter++;
         n/=primes[i];
      }
      res*=counter;
      i++;
   }
   if(n!=1) res*=2;
   return res;
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   sieveOfErastosthenes();
   int t,l,u,ans,num,cal;
   s(t);
   while(t--)
   {
      s(l);
      s(u);
      ans=0;
      num=0;
      fora(i,l,u+1)
      {
         cal=noDivisor(i);
         if(cal>ans)
         {
            ans=cal;
            num=i;
         }
      }
      printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,u,num,ans);
   }
   return 0;
}
