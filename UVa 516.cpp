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
typedef long long int ll;
#define NOPRIMES 32767
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
ll power(int a,int b)
{
   ll res=1;
   while(b)
   {
      if(b%2!=0)
         res*=a;
      a=a*a;
      b=b/2;
   }
   return res;
}
int main()
{
   freopen("temp.txt","r",stdin);
   sieveOfErastosthenes();
   static char str[10000];
   ll n;
   vii ans;
   char *pch;
   int a,b,cnt;
   while(gets(str))
   {
      if(str[0]=='0')   break;
      pch=strtok(str," ");
      n=1;
      while(pch!=NULL)
      {
         a=atoi(pch);
         pch=strtok(NULL," ");
         b=atoi(pch);
         pch=strtok(NULL," ");
         n*=power(a,b);

      }

      n--;
      ans.clear();
      cnt=0;
      fora(i,0,primes.size())
      {
         cnt=0;
         while(!(n%primes[i]))
         {
            n/=primes[i];
            cnt++;
         }
         if(cnt!=0)
            ans.pb(mp(primes[i],cnt));
         if(n<primes[i])
            break;
      }
      if(n!=1)
         ans.pb(mp(n,1));
      printf("%d %d",ans[ans.size()-1].fi,ans[ans.size()-1].se);
      for(int i=ans.size()-2;i>=0;i--)
         printf(" %d %d",ans[i].fi,ans[i].se);
      printf("\n");
      //getchar();
   }
   return 0;
}
