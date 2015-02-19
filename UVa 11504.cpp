#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<bitset>
#include<cstring>
using namespace std;
typedef vector<int> vi;
vector<vi> adjList;
stack<int> s;
bitset<100010> color,visited;
int in[100010],flag[100010];
int counter,c,dfsCount,dfsTime[100010],dfsLow[100010];
void tarjanScc(int u)
{
    color[u]=1;
    s.push(u);
    dfsLow[u]=dfsTime[u]=dfsCount++;
    for(int i=0;i<adjList[u].size();i++)
    {
        int v=adjList[u][i];
        if(!color[v])
            tarjanScc(v);
        if(!visited[v])
            dfsLow[u]=min(dfsLow[u],dfsLow[v]);
    }
    if(dfsLow[u]==dfsTime[u])
    {
        counter++;
        while(s.top()!=u)
        {
            flag[s.top()]=counter;
            visited[s.top()]=1;
            s.pop();

        }
        flag[s.top()]=counter;
        visited[s.top()]=1;
        s.pop();
    }
}
int main()
{
    freopen("temp.txt","r",stdin);
    int t,n,m,a,b;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);
        adjList.assign(n+1,vi());
        while(m--)
        {
            scanf("%d %d",&a,&b);
            adjList[a].push_back(b);
        }
        color.reset();
        visited.reset();
        counter=0;
        dfsCount=0;
        memset(in,0,sizeof(int)*(n+1));
        for(int i=1;i<=n;i++)
            if(!color[i])
                tarjanScc(i);
        for(int i=0;i<adjList.size();i++)
            for(int j=0;j<adjList[i].size();j++)
                if(flag[i]!=flag[adjList[i][j]])
                    in[flag[adjList[i][j]]]++;
        c=0;
        for(int i=1;i<=counter;i++)
            if(!in[i])
                c++;
        printf("%d\n",c);
    }
    return 0;
}
