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

int main()
{
   freopen("temp.txt","r",stdin);
   int n;
   bitset<1000001> primes;
   const int MAX=1000002;
   primes.set();
   primes[0]=0;
   primes[1]=0;
   for(int i=3;i*i<MAX;i+=2)
   {
      if(primes[i])
      {
         for(int j=i*i;j<MAX;j+=i+i)
            primes[j]=0;
      }
   }
   while(s(n)&&n)
   {
      for(int i=3;i<MAX/2;i+=2)
         if(primes[i]&&primes[n-i])
         {
              printf("%d = %d + %d\n",n,i,n-i);
              break;
         }

   }
   return 0;
}
