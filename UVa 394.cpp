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
typedef long long ll;

struct data
{
   string name;
   int base,size,dim;
   vii bounds;
   data(string s,int b,int si,int d,vii &bound)
   {
      name=s;
      base=b;
      size=si;
      dim=d;
      bounds=bound;
   }
};
int main()
{
   freopen("temp.txt","r",stdin);
   int n,r,a,b;
   vii bound;
   char str[20];
   int base,size,dim,count;
   map<string,int> m;
   count=0;
   vector<data> arr;

   scanf("%d %d",&n,&r);
   while(n--)
   {
      scanf("%s %d %d %d",&str,&base,&size,&dim);
      m[str]=count++;
      bound.clear();
      fora(i,0,dim)
      {
         scanf("%d %d",&a,&b);
         bound.pb(mp(a,b));
      }
      arr.pb(data(str,base,size,dim,bound));
   }

   ll ans;
   ll c;
   int index;
   int q;
   while(r--)
   {
      scanf("%s",&str);
      index=m[str];
      dim=arr[index].dim;
      ans=arr[index].base;
      vii &bo=arr[index].bounds;
      size=arr[index].size;
      printf("%s[",str);
      fora(i,0,dim)
      {
         scanf("%d",&q);
         printf("%d%s",q,i==dim-1?"":", ");
         c=1;
         fora(j,i+1,dim)
            c*=(bo[j].se-bo[j].fi+1);
         //c*=size;
         ans+=(q-bo[i].fi)*c*size;
      }
      printf("] = %d\n",ans);
   }
   return 0;
}
