#include<iostream>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
typedef vector<int> vi;
vector<vi> adjList;
vi output;
int v,n,m,a,b;
bitset<110> color;
void topologicalSort(int u)
{
    color[u]=1;
    for(int i=0;i<adjList[u].size();i++)
    {
        v=adjList[u][i];
        if(!color[v])
        {
            topologicalSort(v);
        }
    }
    output.push_back(u);
}
int main()
{
    freopen("temp.txt","r",stdin);
    while(true)
    {
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)
            break;
        adjList.assign(n+1,vi());
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            adjList[b].push_back(a);
        }
        color.reset();
        output.clear();
        for(int i=1;i<=n;i++)
            if(!color[i])
                topologicalSort(i);
        for(int i=0;i<output.size()-1;i++)
            printf("%d ",output[i]);
        printf("%d\n",output.back());
    }
    return 0;
}
