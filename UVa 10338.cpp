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
unsigned long long int factorial[21];
unsigned long long int init()
{
   factorial[0]=1;
   fora(i,1,21)
      factorial[i]=i*factorial[i-1];
}
int main()
{
   freopen("temp.txt","r",stdin);
   int t,j;
   char str[25];
   int count[26];
   unsigned long long int ans;
   init();
   scanf("%d\n",&t);
   fora(i,0,t)
   {
      gets(str);
      memset(count,0,sizeof(count));
      for(j=0;str[j]!='\0';j++)
         count[str[j]-'A']++;
      ans=factorial[j];
      fora(k,0,26)
         ans/=factorial[count[k]];
      printf("Data set %d: %llu\n",i+1,ans);
   }
   return 0;
}
