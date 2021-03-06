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

int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   int n,arr[1000],count[10],idx,carry,t;
   while(s(n)&&n)
   {
      idx=0;
      arr[0]=1;
      carry=0;
      fora(i,2,n+1)
      {
         fora(j,0,idx+1)
         {
            t=(i*arr[j])+carry;
            arr[j]=t%10;
            carry=t/10;
         }
         while(carry)
         {
            idx++;
            arr[idx]=carry%10;
            carry/=10;
         }
      }
      ms(count,0);
      fora(i,0,idx+1)
         count[arr[i]]++;
      printf("%d! --\n",n);
      fora(i,0,5)
         printf("     (%d)%5d",i,count[i]);
      printf("\n");
      fora(i,5,10)
         printf("     (%d)%5d",i,count[i]);
      printf("\n");
   }
   return 0;
}
