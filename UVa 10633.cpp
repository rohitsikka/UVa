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
typedef unsigned long long int ull;

int main()
{
   #ifndef ONLINE_JUDGE
  freopen("temp.txt","r",stdin);
   #endif
   ull n,a,b;
   ull arr[2];
   while(scanf("%llu",&n)&&n)
   {
      arr[0]=(10*n)/9;
      arr[1]=0;
      for(ull i=arr[0]-10;i<=arr[0]+10;i++)
      {
         if(i==arr[0]) continue;
         if(i-(i/10)==n)  arr[1]=i;
      }
      if(arr[1]!=0)
      {
         sort(arr,arr+2);
         printf("%llu %llu\n",arr[0],arr[1]);
      }
      else
         printf("%llu\n",arr[0]);
   }
   return 0;
}
