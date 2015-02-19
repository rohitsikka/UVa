#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s1[110],s2[110];
short int C[110][110],S[110][110],n1,n2;
bool flag=false;
void print(int i,int j)
{
    if(i<=0||j<=0)
        return ;
    if(S[i][j]==0)
    {
        print(i-1,j-1);
        if(flag)
            cout<<" "<<s1[i-1];
        else
        {
            flag=true;
            cout<<s1[i-1];
        }
    }
    else if(S[i][j]==1)
        print(i-1,j);
    else
        print(i,j-1);
}
void LCS()
{
    for(int i=0;i<=n1;i++)
        C[i][0]=0;
    for(int i=0;i<=n2;i++)
        C[0][i]=0;
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                C[i][j]=C[i-1][j-1]+1;
                S[i][j]=0;
            }
            else if(C[i-1][j]>C[i][j-1])
            {
                C[i][j]=C[i-1][j];
                S[i][j]=1;
            }
            else
            {
                C[i][j]=C[i][j-1];
                S[i][j]=-1;
            }
        }
    }
    print(n1,n2);
}
int main()
{
    freopen("temp.txt","r",stdin);
    string str;
    while(cin>>str)
    {
        n1=1;
        n2=0;
        s1[0]=str;
        while(cin>>str&&str[0]!='#')
        {
            s1[n1]=str;
            n1++;
        }
        while(cin>>str&&str[0]!='#')
        {
            s2[n2]=str;
            n2++;
        }
        flag=false;
        LCS();
        cout<<endl;
    }
    return 0;
}
