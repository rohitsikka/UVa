#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
using namespace std;
int dl[]={1,-1,0,0,0,0};
int dr[]={0,0,1,-1,0,0};
int dc[]={0,0,0,0,1,-1};
struct vertex
{
    int l,r,c,dist;
    bool color;
    char ch;
}g[33][33][33];
int main()
{
    freopen("temp.txt","r",stdin);
    int l,r,c;
    bool flag;
    while(scanf("%d %d %d",&l,&r,&c))
    {
        flag=false;
        if(l==0&&r==0&&c==0)
            break;
        for(int i=0;i<l;i++)
            for(int j=0;j<r;j++)
                for(int k=0;k<c;k++)
                {
                    g[i][j][k].l=i;
                    g[i][j][k].r=j;
                    g[i][j][k].c=k;
                    g[i][j][k].color=false;
                }
        queue<vertex> q;

        for(int i=0;i<l;i++)
        {  getchar();
            for(int j=0;j<r;j++)
            {
                for(int k=0;k<c;k++)
                {   g[i][j][k].ch=getchar();
                    if(g[i][j][k].ch=='S')
                    {
                        g[i][j][k].dist=0;
                        q.push(g[i][j][k]);
                    }
                }
                getchar();
            }
        }


         while(!q.empty())
         {
            vertex temp;
            temp=q.front();
            q.pop();
            for(int i=0;i<6;i++)
            {
                int tl=temp.l+dl[i];
                int tr=temp.r+dr[i];
                int tc=temp.c+dc[i];
                if(tl>=0&&tr>=0&&tc>=0&&tl<l&&tr<r&&tc<c)
                    if(!g[tl][tr][tc].color&&g[tl][tr][tc].ch!='#')
                    {
                        g[tl][tr][tc].color=true;
                        g[tl][tr][tc].dist=g[temp.l][temp.r][temp.c].dist+1;
                        if(g[tl][tr][tc].ch=='E')
                        {
                            printf("Escaped in %d minute(s).\n",g[tl][tr][tc].dist);
                            flag=true;
                            break;
                        }
                        q.push(g[tl][tr][tc]);
                    }
            }
            if(flag)
                break;
         }
         if(!flag)
            printf("Trapped!\n");

    }
    return 0;
}
