#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<bitset>
#include<stack>
using namespace std;
typedef vector<int> vi;
map<string,int> m;
int n,p,counter;
bitset<1010> color,visited;
stack<int> s;
int dfsLow[1010],dfsTime[1010],dfsCount;
vector<vi> adjList;
void tarjanScc(int u)
{
    color[u]=1;
    dfsTime[u]=dfsLow[u]=dfsCount++;
    s.push(u);
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
            visited[s.top()]=1;
            s.pop();
        }
        visited[u]=1;
        s.pop();
    }
}
int main()
{
    freopen("temp.txt","r",stdin);
    char inp1[100],inp2[100];
    int a,b;
    while(true)
    {
        scanf("%d %d\n",&p,&n);
        if(p==0&&n==0)
            break;
        m.clear();
        for(int i=0;i<p;i++)
        {
            gets(inp1);
            m[inp1]=i;
        }
        adjList.assign(p,vi());
        for(int i=0;i<n;i++)
        {
            gets(inp1);
            gets(inp2);
            a=m[inp1];
            b=m[inp2];
            adjList[a].push_back(b);
        }
        while(s.size()>0)
            s.pop();
        color.reset();
        visited.reset();
        counter=0;
        dfsCount=0;
        for(int i=0;i<p;i++)
            if(!color[i])
                tarjanScc(i);
        printf("%d\n",counter);
    }
    return 0;
}
