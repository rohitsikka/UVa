#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string name;
short int N,C,R,M[110][110];
int DP[110][110];
int recur(int i,int j)
{
    if(i<0||j<0||i>=R||j>=C)
        return 0;
    if(DP[i][j]!=-1)
        return DP[i][j];
    int temp=0;
    if(M[i-1][j]<M[i][j])
        temp=max(temp,recur(i-1,j));
    if(M[i][j-1]<M[i][j])
        temp=max(temp,recur(i,j-1));
    if(M[i+1][j]<M[i][j])
        temp=max(temp,recur(i+1,j));
    if(M[i][j+1]<M[i][j])
        temp=max(temp,recur(i,j+1));
    DP[i][j]=temp+1;
    return temp+1;
}
int solve()
{
    int maximum=0;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(recur(i,j)>maximum)
                maximum=recur(i,j);
    return maximum;
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>N;
    while(N--)
    {
        cin>>name;
        cin>>R;
        cin>>C;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                cin>>M[i][j];
        memset(DP,-1,110*110*sizeof(int));
        cout<<name<<": "<<solve()<<"\n";
    }
    return 0;
}
