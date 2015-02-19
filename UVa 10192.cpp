#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char T1[110],T2[110];
int N1,N2;
int C[110][110];
int LCS()
{
    for(int i=0;i<=N1;i++)
        C[i][0]=0;
    for(int i=0;i<=N2;i++)
        C[0][i]=0;
    for(int i=1;i<=N1;i++)
    {
        for(int j=1;j<=N2;j++)
        {
            if(T1[i-1]==T2[j-1])
                C[i][j]=C[i-1][j-1]+1;
            else
                C[i][j]=max(C[i-1][j],C[i][j-1]);
        }
    }
    return C[N1][N2];
}
int main()
{
    int n=1;
    freopen("temp.txt","r",stdin);
    while(gets(T1)!=NULL)
    {
        if(T1[0]=='#')
                continue;
        gets(T2);
        N1=strlen(T1);
        N2=strlen(T2);
        cout<<"Case #"<<n<<":";
        cout<<" you can visit at most "<<LCS()<<" cities.\n";
        n++;
    }
    return 0;
}
