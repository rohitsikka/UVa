#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<sstream>
#include<cstdlib>
using namespace std;
typedef pair<int,int> ii;
#define make_pair MP
int g[110][110];
int n;
bool color[110][110];
bool h[110];
const int dr[]={1,-1,0,0};
const int dc[]={0,0,1,-1};
void floodFill(int r,int c,int num)
{
    if(r<1||c<1||r>n||c>n||color[r][c]||g[r][c]!=num)
        return;
    color[r][c]=true;
    for(int i=0;i<4;i++)
        floodFill(r+dr[i],c+dc[i],num);
}
bool solve()
{
    memset(h,0,sizeof(h));
    memset(color,0,sizeof(color));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!color[i][j])
            {
                if(!h[g[i][j]])
                {
                    floodFill(i,j,g[i][j]);
                    h[g[i][j]]=true;
                }
                else
                    return false;
            }
        }
    }
    return true;
}
void format(char *s,int num)
{
    char *pch;
    pch=strtok(s," ");
    while(pch!=NULL)
    {
        int a=atoi(pch);
        pch=strtok(NULL," ");
        int b=atoi(pch);
        pch=strtok(NULL," ");
        g[a][b]=num;
    }
}
int main()
{
    freopen("temp.txt","r",stdin);
    char inp[1000];
    int a,b;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        getchar();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                g[i][j]=n;
        for(int i=1;i<n;i++)
        {
            gets(inp);
            /*stringstream ss(inp);
            while(ss>>a>>b)
                g[a][b]=i;
            */
            format(inp,i);
        }
        if(solve())
            printf("good\n");
        else
            printf("wrong\n");
    }
    return 0;
}
