#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
const int dr[]={1,-1,0,0};
const int dc[]={0,0,1,-1};
char maze[1010][1010];
int dist[1010][1010];
int main()
{
    freopen("temp.txt","r",stdin);
    int t,r,c;
    scanf("%d",&t);
    while(t--)
    {
        bool flag=true;
        queue<ii> q;
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++)
        {
            getchar();
            for(int j=0;j<c;j++)
            {
                maze[i][j]=getchar();
                if(maze[i][j]=='J')
                {
                    dist[i][j]=0;
                    q.push(make_pair(i,j));
                }
            }
        }
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(maze[i][j]=='F')
                    q.push(make_pair(i,j));

        flag=true;
        int ans=-1;
        int count=0;
        while(!q.empty()&&flag)
        {
            ii t;
            t=q.front();
            q.pop();
            for(int i=0;i<4&&flag;i++)
            {
                int tr=t.first+dr[i];
                int tc=t.second+dc[i];
                if((tc<0||tr<0||tc>=c||tr>=r))
                {
                    if(maze[t.first][t.second]=='J')
                    {
                        ans=dist[t.first][t.second]+1;
                        flag=false;
                    }

                }

                else if(maze[t.first][t.second]=='J')
                {
                    if(maze[tr][tc]=='.')
                    {
                        maze[tr][tc]='J';
                        q.push(make_pair(tr,tc));
                        dist[tr][tc]=dist[t.first][t.second]+1;
                    }
                }
                else
                {
                    if(maze[tr][tc]=='.'||maze[tr][tc]=='J')
                    {
                        maze[tr][tc]='F';
                        q.push(make_pair(tr,tc));
                    }

                }
            }
        }
        if(ans!=-1)
            printf("%d\n",ans);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
