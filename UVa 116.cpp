#include<iostream>
#include<climits>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

long long int M[13][110];
int parent[13][110];
bool Co[13][110];
int R,C;
long long int TSP(int i,int j)
{
    if(j==C-1)
        return M[i][j];
    if(Co[i][j])
        return M[i][j];
    Co[i][j]=true;
    int costa,costb,costc;
    int a,b,c;
    a=(i-1+R)%R;
    b=i;
    c=(i+1)%R;

    costa=TSP(a,j+1);
    costb=TSP(b,j+1);
    costc=TSP(c,j+1);

    int min=a;
    int minCost=costa;
    if(costb<minCost || minCost==costb&&min>b)
    {
        minCost=costb;
        min=b;
    }
    if(costc<minCost|| minCost==costc&&min>c)
    {
        minCost=costc;
        min=c;
    }
    parent[i][j]=min;
    M[i][j]=minCost+M[i][j];
    return M[i][j];
}
void print(int i,int j)
{
    if(j==C)
        return;
    if(j==0)
        cout<<i+1;
    else
        cout<<" "<<i+1;
    print(parent[i][j],j+1);
}
void solve()
{
    long long int mini=0,minc,cost;
    for(int i=0;i<R;i++)
    {
        cost=TSP(i,0);
        if(i==0)
            minc=cost;
        if(cost<minc)
        {
            mini=i;
            minc=cost;
        }
    }
    print(mini,0);
    cout<<"\n";
    cout<<minc;

}
int main()
{
    freopen("temp.txt","r",stdin);

    while(cin>>R)
    {
        cin>>C;
        memset(Co,false,13*110*sizeof(bool));
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                cin>>M[i][j];
        solve();
        cout<<"\n";
    }
    return 0;
}
