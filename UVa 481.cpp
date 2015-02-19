#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
vector<int> arr;
vector< vector<int> > DP;
int bSearch(int ele,int len)
{
    int left=1,right=len;
    int mid;
    while(right-left>1)
    {
        mid=(left+right)/2;
        if(DP[mid].back()<ele)
            left=mid;
        else
            right=mid;
    }
    return left;
}
void nlognLis()
{
    int len=1;
    DP[1].push_back(arr[0]);
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]<DP[1].back())
        {
            DP[1].clear();
            DP[1].push_back(arr[i]);
        }
        else if(arr[i]>(DP[len].back()))
        {
            DP[len+1]=DP[len];
            DP[len+1].push_back(arr[i]);
            len++;
        }
        else
        {
            int index=bSearch(arr[i],len);
            DP[index+1]=DP[index];
            DP[index+1].push_back(arr[i]);
        }
    }
    cout<<len<<"\n-\n";
    for(int i=0;i<DP[len].size();i++)
        cout<<DP[len][i]<<"\n";
}
int main()
{
    freopen("temp.txt","r",stdin);
    int temp;
    arr.reserve(100000);
    DP.reserve(100000);
    for(int i=0;i<100000;i++)
        DP[i].clear();
    while(scanf("%d",&temp)!=EOF)
        arr.push_back(temp);
    nlognLis();
    return 0;
}
