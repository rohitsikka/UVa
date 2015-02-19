#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef pair<int,int> ii;
char g[105][105];
const int dr[]={1,-1,0,0,1,-1,1,-1};
const int dc[]={0,0,1,-1,1,-1,-1,1};
bool color[105][105];
int r,c;
int count;
void dfs(int x,int y)
{
    if(x<0||y<0||x>=r||y>=c||g[x][y]!='W'||color[x][y])
        return;
    color[x][y]=true;
    count++;
    for(int i=0;i<8;i++)
        dfs(x+dr[i],y+dc[i]);
}
int main()
{
    freopen("temp.txt","r",stdin);
    int t,row,col;
    char inp[150];
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        r=0;
        c=0;
        while(gets(inp)&&strlen(inp)>0)
        {
            if(inp[0]=='L'||inp[0]=='W')
                strcpy(g[r++],inp);
            else
            {
                count=0;
                memset(color,0,sizeof(color));
                c=strlen(g[0]);
                sscanf(inp,"%d %d",&row,&col);
                dfs(row-1,col-1);
                printf("%d\n",count);
            }
        }
        if(t)
            printf("\n");
    }
    return 0;
}
