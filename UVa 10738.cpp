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
#define NOPRIMES 1100
#define MAX 1000010
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
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   sieveOfErastosthenes();
   static int mu[MAX],M[MAX];
   int counter;
   bool flag;
   mu[1]=M[1]=1;
   fora(j,2,MAX)
   {
      int n=j;
      counter=0;
      flag=true;
      fora(i,0,primes.size())
      {
         if(n==1) break;
         if(n%primes[i]==0)
         {
            n/=primes[i];
            if(n%primes[i]==0)
            {
               mu[j]=0;
               flag=false;
               break;
            }
            counter++;
         }
      }
      if(n!=1) counter++;
      if(flag)
         mu[j]=counter%2==0?1:-1;
   }
   fora(i,2,MAX)
      M[i]=M[i-1]+mu[i];
   int n1;
   while(s(n1)&&n1)
   {
      printf("%8d%8d%8d\n",n1,mu[n1],M[n1]);
   }
   return 0;
}
