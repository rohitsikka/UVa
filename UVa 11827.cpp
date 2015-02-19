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
   int t;
   vi arr;
   int m;
   char *pch;
   char str[100];
   scanf("%d\n",&t);
   while(t--)
   {
      gets(str);
      arr.clear();
      pch=strtok(str," ");
      while(pch!=NULL)
      {
         arr.pb(atoi(pch));
         pch=strtok(NULL," ");
      }
      m=0;
      fora(i,0,arr.size())
         fora(j,i+1,arr.size())
            m=max(m,gcd(arr[i],arr[j]));
      printf("%d\n",m);
   }
   return 0;
}
