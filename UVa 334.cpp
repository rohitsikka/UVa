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

int main()
{
   freopen("temp.txt","r",stdin);
   int n,m,counter;
   int top;
   int adjMat[200][200];
   map<string,int> mp;
   vector<string> mpName;
   char inp1[20],inp2[20];
   int q=1;
   while(s(n)&&n)
   {
      mp.clear();
      mpName.clear();
      fora(i,0,200)
         fora(j,0,200)
            adjMat[i][j]=0;
      counter=0;
      fora(i,0,n)
      {
         s(m);
         top=counter;
         fora(j,0,m)
         {
            scanf("%s",inp1);
            mpName.pb(inp1);
            mp[inp1]=counter++;
         }
         fora(j,top,counter-1)
            adjMat[j][1+j]=1;
      }
      n=counter;
      s(m);
      fora(j,0,m)
      {
         scanf("%s",inp1);
         scanf("%s",inp2);
         adjMat[mp[inp1]][mp[inp2]]=1;
      }
      fora(k,0,n)
         fora(i,0,n)
            fora(j,0,n)
               adjMat[i][j]=adjMat[i][j]||(adjMat[i][k]&&adjMat[k][j]);
      int ans=0;
      string out;
      fora(i,0,n)
         fora(j,i+1,n)
            if((adjMat[i][j]==0)&&(adjMat[j][i]==0))
            {
               ans++;
               if(ans<=2)
                  out=out+"("+mpName[i]+","+mpName[j]+") ";
            }

      if(ans==0)
         printf("Case %d, no concurrent events.\n",q);
      else
      {
         printf("Case %d, %d concurrent events:\n",q,ans);
         cout<<out<<"\n";
      }
      q++;
   }
   return 0;
}
