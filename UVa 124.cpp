#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<sstream>
#include<cstring>
#define isOn(b,i) (b & (1<<i))
#define setBit(b,i) (b |= (1<<i))
#define clearBit(b,i) (b &= (~(1<<i)))

using namespace std;
typedef vector<int> vi;
bool g[27][27];
string arr;
string output;
int mask;
bool check(char u)
{
    for(int i=0;i<output.size();i++)
       if(g[u-'a'][output[i]-'a'])
            return false;
    return true;
}
void topologicalSort()
{
    if(output.size()==arr.size())
    {
        for(int i=0;i<output.size();i++)
            printf("%c",output[i]);
        printf("\n");
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
    char inp[400];
    bool flag=false;
    while(gets(inp))
    {
        if(flag)
            printf("\n");
        flag=true;
        arr.clear();
        for(int i=0;inp[i]!='\0';i++)
            if(isalpha(inp[i]))
                arr.push_back(inp[i]);
        sort(arr.begin(),arr.end());
        gets(inp);
        char a,b;
        memset(g,0,sizeof(g));
        for(int i=0;inp[i]!='\0';i++)
        {
            if(isalpha(inp[i]))
            {
                a=inp[i];
                i++;
                while(!isalpha(inp[i])) i++;
                b=inp[i];
                g[a-'a'][b-'a']=true;
            }
        }

        output.clear();
        mask=0;
        topologicalSort();
    }
    return 0;
}
