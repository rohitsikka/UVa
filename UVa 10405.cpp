#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int LCS(char s1[],char s2[])
{
    short int C[1010][1010];
    int n1=strlen(s1),n2=strlen(s2);
    if(n1==0||n2==0)
        return 0;
    for(int i=0;i<n1;i++)
    {
         C[0][i]=0;
         C[i][0]=0;
    }
    for(int i=1;i<=n2;i++)
    {
        for(int j=1;j<=n1;j++)
        {
            if(s2[i-1]==s1[j-1])
                C[i][j]=C[(i-1)][j-1]+1;
            else
                C[i][j]=max(C[(i-1)][j],C[i][j-1]);
        }
    }
    return C[n2][n1];
}
int main()
{
    freopen("temp.txt","r",stdin);
    char s1[1010],s2[1010];
    while(gets(s1))
    {
        gets(s2);
        cout<<LCS(s1,s2)<<"\n";
    }
    return 0;
}
