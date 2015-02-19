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
#define MAX 20000001
int main()
{
   freopen("temp.txt","r",stdin);
   static bitset<MAX> isPrime;
   isPrime[0]=1;
   isPrime[1]=1;
   for(int i=3;i*i<MAX;i+=2)
   {
      if(!isPrime[i])
         for(int j=i*i;j<MAX;j+=i+i)
            isPrime[j]=1;
   }
   vi ans;
   for(int i=3;i<MAX;i+=2)
   {
         if(!isPrime[i]&&!isPrime[i+2])
         {
            ans.pb(i);
         }
   }
   int n;
   while(s(n)!=EOF)
   {
      printf("(%d, %d)\n",ans[n-1],ans[n-1]+2);
   }
   return 0;
}
