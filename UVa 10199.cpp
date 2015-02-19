#include<iostream>
#include<cstdio>
#include<map>
#include<bitset>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef vector<int> vi;
bitset<105> color;
bitset<105> p;
vector<vi> adjList;
int cityCounter,n,r,a,b,t;
string strA,strB;
vector<string> aP;
map<string,int> m;
string city[105];
int dfsTime[105],dfsLow[105],dfsCount,parent[105];
void articulatedPoints(int u)
{
    dfsTime[u]=dfsLow[u]=dfsCount++;
    color[u]=1;
    int children=0;
    for(int i=0;i<adjList[u].size();i++)
    {
        int v=adjList[u][i];
        if(!color[v])
        {
            children++;
            parent[v]=u;
            articulatedPoints(v);
            if(parent[u]==-1&&children>1)
                p[u]=1;
            if(parent[u]!=-1&&dfsLow[v]>=dfsTime[u])
                p[u]=1;
            dfsLow[u]=min(dfsLow[u],dfsLow[v]);
        }
        else if(parent[u]!=v)
            dfsLow[u]=min(dfsLow[u],dfsTime[v]);
    }
}
int main()
{
    freopen("temp.txt","r",stdin);
    t=1;
    bool flag=false;
    while(scanf("%d",&n)&&n)
    {
        if(flag)
            printf("\n");
        flag=true;
        m.clear();
        for(int i=0;i<n;i++)
        {
            cin>>city[i];
            m.insert(std::map<string, int>::value_type(city[i],i));
        }
        scanf("%d",&r);
        adjList.assign(n,vi());
        for(int i=0;i<r;i++)
        {
            cin>>strA>>strB;
            a=m[strA];
            b=m[strB];
            adjList[b].push_back(a);
            adjList[a].push_back(b);
        }
        aP.clear();
        p.reset();
        color.reset();
        for(int i=0;i<=n;i++)
            parent[i]=-1;
        dfsCount=0;
        for(int i=0;i<n;i++)
            if(!color[i])
                articulatedPoints(i);
        for(int i=0;i<105;i++)
            if(p[i])
                aP.push_back(city[i]);
        printf("City map #%d: %u camera(s) found\n",t++,aP.size());
        sort(aP.begin(),aP.end());
        for(int i=0;i<aP.size();i++)
            cout<<aP[i]<<"\n";
    }
    return 0;
}

