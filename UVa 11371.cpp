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

ll parse(string str)
{
   ll ans=0;
   fora(i,0,str.size())
      ans=ans*10+str[i]-'0';
   return ans;
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   string str;
   ll a,b;
   int pos;
   while(cin>>str)
   {
      sort(all(str));
      pos=0;
      while(pos<str.size()&&str[pos]=='0')
         pos++;
      swap(str[pos],str[0]);
      b=parse(str);
      sort(str.rbegin(),str.rend());
      a=parse(str);
      printf("%lld - %lld = %lld = %lld * %lld\n",a,b,a-b,9ll,(ll)(a-b)/9);
   }
   return 0;
}
