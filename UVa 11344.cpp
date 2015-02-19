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

int gcd(int a,int b)
{
   int temp;
   while(b)
   {
      temp=a;
      a=b;
      b=temp%b;
   }
   return a;
}
int lcm(int a,int b)
{
   return a/gcd(a,b)*b;
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   int t,d,a,ans,n;
   char str[10010];
   int LCM;
   s(t);
   while(t--)
   {
      scanf("%s",&str);
      n=strlen(str);
      s(d);
      LCM=1;
      fora(i,0,d)
      {
         s(a);
         LCM=lcm(LCM,a);
      }
      ans=0;
      fora(i,0,n)
      {
         ans=(10*ans+str[i]-'0')%LCM;
      }
      if(ans==0)
         printf("%s - Wonderful.\n",str);
      else
         printf("%s - Simple.\n",str);
   }
   return 0;
}
