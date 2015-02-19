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

void extendedEuclid(int a,int b)
{
   int x,y,nx,ny,temp,q;
   x=ny=1;
   y=nx=0;
   while(b)
   {
      q=a/b;
      temp=a;a=b;b=temp%b;
      temp=nx;nx=x-q*nx;x=temp;
      temp=ny;ny=y-q*ny;y=temp;
   }
   printf("%d %d %d\n",x,y,a);
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   int a,b;
   while(scanf("%d %d",&a,&b)!=EOF)
   {
      extendedEuclid(a,b);
   }
   return 0;
}
