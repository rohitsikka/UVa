#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define isOn(b,i) (b & (1<<i))
#define setBit(b,i) (b |= (1<<i))
#define clearBit(b,i) (b &= (~(1<<i)))
using namespace std;
string arr,output;
char inp[400];
bool g[26][26];
bool flag;
int mask;
bool check(char u)
{
    for(int i=0;i<output.size();i++)
        if(g[u-'A'][output[i]-'A'])
            return false;
    return true;
}
void topologicalSort()
{
    if(arr.size()==output.size())
    {
        for(int i=0;i<output.size()-1;i++)
            printf("%c ",output[i]);
        printf("%c\n",output.back());
        flag=false;
    }
    else
    {
        for(int i=0;i<arr.size();i++)
        {
            if(!isOn(mask,i)&&check(arr[i]))
            {
                setBit(mask,i);
                output.push_back(arr[i]);
                topologicalSort();
                output.pop_back();
                clearBit(mask,i);
            }
        }
    }
}
int main()
{
    freopen("temp.txt","r",stdin);
    char a,b;
    int t;
    bool blank=false;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        if(blank)
            printf("\n");
        blank=true;
        getchar();
        gets(inp);
        arr.clear();
        for(int i=0;inp[i]!='\0';i++)
            if(isalpha(inp[i]))
                arr.push_back(inp[i]);
        sort(arr.begin(),arr.end());
        gets(inp);
        memset(g,0,sizeof(g));
        for(int i=0;inp[i]!='\0';i++)
        {
            if(isalpha(inp[i]))
            {
                a=inp[i];
                i++;
                while(!isalpha(inp[i]))
                    i++;
                b=inp[i];
                g[a-'A'][b-'A']=true;
            }
        }
        output.clear();
        mask=0;
        flag=true;
        topologicalSort();
        if(flag)
            printf("NO\n");
    }
    return 0;
}
