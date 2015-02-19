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

int main()
{
   freopen("temp.txt","r",stdin);
   int n;
   int carry,mul;
   int s;
   vi ans;
   while(s(n)!=EOF)
   {
      ans.clear();
      ans.pb(1);
      fora(i,2,n+1)
      {
         s=ans.size();
         carry=0;
         fora(j,0,s)
         {
            mul=ans[j]*i+carry;
            ans[j]=mul%10;
            carry=mul/10;
         }
         while(carry)
         {
            ans.pb(carry%10);
            carry/=10;
         }
      }
      printf("%d!\n",n);
      for(int j=ans.size()-1;j>=0;j--)
         printf("%d",ans[j]);
      puts("");
   }
   return 0;
}
