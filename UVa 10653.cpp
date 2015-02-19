#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct vertex
{
    int r,c,dist;
    bool b,color;
};
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int main()
{
    freopen("temp.txt","r",stdin);
    static vertex g[1010][1010],t;
    int R,C,r,c,tr,tc,rNo,cNo,bombs,sr,sc,er,ec;
    for(int i=0;i<1010;i++)
            for(int j=0;j<1010;j++)
            {
                g[i][j].r=i;
                g[i][j].c=j;
            }
    while(scanf("%d %d",&R,&C))
    {

        if(R==0&&C==0)
            break;

        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
            {
                g[i][j].b=false;
                g[i][j].color=false;
            }

        scanf("%d",&r);
        for(int i=0;i<r;i++)
        {
            scanf("%d %d",&rNo,&bombs);
            for(int j=0;j<bombs;j++)
            {
                scanf("%d ",&cNo);
                g[rNo][cNo].b=true;
            }
        }
        scanf("%d %d",&sr,&sc);
        scanf("%d %d",&er,&ec);
        queue<vertex> q;
        g[sr][sc].dist=0;
        g[sr][sc].color=true;
        q.push(g[sr][sc]);
        bool flag=true;
        while(!q.empty()&&flag)
        {
            t=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                tr=t.r+dr[i];
                tc=t.c+dc[i];
                if(tr>=0&&tc>=0&&tr<R&&tc<C&&!g[tr][tc].b&&!g[tr][tc].color)
                {
                    g[tr][tc].color=true;
                    g[tr][tc].dist=g[t.r][t.c].dist+1;
                    q.push(g[tr][tc]);
                    if(tr==er&&tc==ec)
                    {
                        printf("%d\n",g[er][ec].dist);
                        break;
                        flag=false;
                    }
                }
            }
        }
    }
    return 0;
}
