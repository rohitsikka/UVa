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

int gcd(int a,int b)
{
   int t;
   while(b)
   {
      t=a;
      a=b;
      b=t%b;
   }
   return a;
}
int main()
{
   freopen("temp.txt","r",stdin);
   vi arr;
   int ans,a,t;
   scanf("%d",&a);
   while(a)
   {
      arr.clear();
      while(a)
      {
         arr.pb(a);
         scanf("%d",&a);
      }
      ans=0;
      sort(arr.begin(),arr.end());
      fora(i,1,arr.size())
      {
         arr[i]=arr[i]-arr[0];
         ans=gcd(ans,arr[i]);
      }
      printf("%d\n",ans);
      scanf("%d",&a);
   }
   return 0;
}
