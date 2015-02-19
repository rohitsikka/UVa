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
int getPower(int a,int f)
{
   int res=0;
   for(int i=f;i<=a;i*=f)
      res+=a/i;
   return res;
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   sieveOfErastosthenes();
   int a,b;
   int fCount,factor;
   bool flag;
   int t;
   while(scanf("%d %d",&a,&b)!=EOF)
   {
      t=b;
      flag=true;
      fora(i,0,primes.size())
      {
         if(primes[i]>b)   break;
         fCount=0;
         while(b%primes[i]==0)
         {
            b/=primes[i];
            fCount++;
         }
         if(fCount>0&&fCount>getPower(a,primes[i]))
         {
            flag=false;
            break;
         }
      }
      if(b!=1&&b>a)  flag=false;
      if(flag)
         printf("%d divides %d!\n",t,a);
      else
         printf("%d does not divide %d!\n",t,a);
   }
   return 0;
}
