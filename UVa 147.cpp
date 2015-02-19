#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dollars[]={2000,1000,400,200,100,40,20,10,4,2,1};
unsigned long long int ways[6100];
void solve()
{
    memset(ways,0,sizeof(unsigned long long int)*6100);
    ways[0]=1;
    for(int i=0;i<11;i++)
        for(int j=dollars[i];j<6100;j++)
            ways[j]+=ways[j-dollars[i]];
}
int main()
{
    freopen("temp.txt","r",stdin);
    int n1,n2;
    solve();
    while(scanf("%d.%d",&n1,&n2)&&n1||n2)
    {
        unsigned long long q=0;
        int t=n1*100+n2;
        if(t%5!=0)
           printf("%3d.%.2d%17llu\n",n1,n2,q);
        else
        {
            t=t/5;
            printf("%3d.%0d%17llu\n",n1,n2,ways[t]);
        }
    }
    return 0;
}
