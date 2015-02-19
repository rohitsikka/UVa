#include<iostream>
#include<cstdio>
#include<bitset>
#include<vector>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
typedef vector<int> vi;
vector<vi> adjList;
vector<vi> output;
vi temp;
char arr[10],ch;
int n,dfsLow[26],dfsTime[26],dfsCount;
bitset<26> color;
bitset<26> visited;
stack<int> s;
set<int> se;
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
        if (!visited[v])
            dfsLow[u]=min(dfsLow[u],dfsLow[v]);
    }
    if(dfsLow[u]==dfsTime[u])
    {
        temp.clear();
        while(s.top()!=u)
        {
            temp.push_back(s.top());
            visited[s.top()]=1;
            s.pop();
        }
        temp.push_back(u);
        visited[s.top()]=1;
        s.pop();
        sort(temp.begin(),temp.end());
        output[temp[0]].clear();
        output[temp[0]]=temp;

    }
}
int main()
{
    freopen("temp.txt","r",stdin);
    bool flag=false;
    while(scanf("%d\n",&n)&&n)
    {
        if(flag)
            printf("\n");
        flag=true;
        adjList.assign(26,vi());
        se.clear();
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<5;j++)
            {
                scanf("%c ",&arr[j]);
                se.insert(arr[j]-'A');
            }
            scanf("%c ",&ch);
            for(int j=0;j<5;j++)
                if(arr[j]!=ch)
                    adjList[ch-'A'].push_back(arr[j]-'A');
        }
        color.reset();
        visited.reset();
        output.assign(26,vi());
        while(s.size())
            s.pop();
        dfsCount=0;
        for(int i=0;i<26;i++)
            if(!color[i]&&se.find(i)!=se.end())
                tarjanScc(i);
        for(int i=0;i<26;i++)
        {
            if(output[i].size()>0)
            {
                printf("%c",output[i][0]+'A');
                for(int j=1;j<output[i].size();j++)
                    printf(" %c",output[i][j]+'A');
                printf("\n");
            }

        }
    }
    return 0;
}
