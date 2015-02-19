#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
const int dr[]={1,-1,0,0};
const int dc[]={0,0,1,-1};
typedef pair<int,int> ii;
int main()
{
    freopen("temp.txt","r",stdin);
    static bool color[2001][2001],m[2001][2001];
    static int dist[2001][2001];
    int p,a,b;
    while(scanf("%d",&p)&&p)
    {
        queue<ii> q;
        memset(color,0,sizeof(color));
        for(int i=0;i<p;i++)
        {
            scanf("%d %d",&a,&b);
            color[a][b]=true;
            q.push(make_pair(a,b));
        }
        memset(m,0,sizeof(m));
        scanf("%d",&p);
        for(int i=0;i<p;i++)
        {
            scanf("%d %d",&a,&b);
            m[a][b]=true;
        }
        memset(dist,0,sizeof(dist));
        while(!q.empty())
        {
           ii t;
           t=q.front();
           q.pop();
           if(m[t.first][t.second])
            {
                printf("%d\n",dist[t.first][t.second]);
                break;
            }
            for(int i=0;i<4;i++)
           {
               int tr=t.first+dr[i];
               int tc=t.second+dc[i];
               if(tr>=0&&tc>=0&&tr<=2000&&tc<=2000&&!color[tr][tc])
               {
                    color[tr][tc]=true;
                    dist[tr][tc]=dist[t.first][t.second]+1;
                    q.push(make_pair(tr,tc));
               }
           }
        }

    }
    return 0;
}
