#include<iostream>
#include<cstdio>
using namespace std;
int T,N,P[1010],W[1010],MW,G,ans;
int C[1010][35];
int Knapsack(int weight)
{
    for(int i=0;i<=N;i++)
        C[i][0]=0;

    for(int i=0;i<=weight;i++)
        C[0][i]=0;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=weight;j++)
        {
            if(j>=W[i])
                C[i][j]=max(C[i-1][j],C[i-1][j-W[i]]+P[i]);
            else
                C[i][j]=C[i-1][j];
        }
    }
    return C[N][weight];
}
int main()
{
    freopen("temp.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=1;i<=N;i++)
        {
            cin>>P[i];
            cin>>W[i];
        }
        cin>>G;
        ans=0;
        for(int i=0;i<G;i++)
        {
            cin>>MW;
            ans+=Knapsack(MW);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
