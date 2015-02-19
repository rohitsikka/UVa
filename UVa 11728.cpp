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
int sum(int n)
{
   int counter=0;
   fora(i,1,n+1)
      if(n%i==0)
         counter+=i;
   return counter;
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   int DP[1010];
   ms(DP,0);
   int m;
   fora(i,1,1001)
   {
      m=sum(i);
      if(m<=1000)
         DP[m]=i;
   }
   int k=1;
   int n;
   while(s(n)&&n)
   {
      if(DP[n]==0)
      printf("Case %d: -1\n",k);
      else
      printf("Case %d: %d\n",k,DP[n]);
      k++;
   }
   return 0;
}
