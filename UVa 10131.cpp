#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<climits>
#define DIAG 0
#define LEFT -1
#define UP 1
using namespace std;

struct elephant
{
    int pos;
    int weight;
    int iq;
}E[1010],sortW[1010],sortIQ[1010];
short int C[1010][1010],S[1010][1010];
int n=1;
int compW(const void *x,const void *y)
{
    elephant *a,*b;
    a=(elephant*)x;
    b=(elephant*)y;
    if(a->weight<b->weight) return -1;
    else if(a->weight==b->weight)   return 0;
    else    return 1;
}
int compIQ(const void *x,const void *y)
{
    elephant *a,*b;
    a=(elephant*)x;
    b=(elephant*)y;
    if(a->iq>b->iq) return -1;
    else if(a->iq==b->iq)   return 0;
    else    return 1;
}

void LCS(elephant s1[],elephant s2[])
{
    for(int i=0;i<=n;i++)
    {
        C[i][0]=0;
        C[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i].pos==s2[j].pos)
            {
                C[i][j]=C[i-1][j-1]+1;
                S[i][j]=DIAG;
            }
            else if(C[i-1][j]>C[i][j-1])
            {
                C[i][j]=C[i-1][j];
                S[i][j]=UP;
            }
            else
            {
                C[i][j]=C[i][j-1];
                S[i][j]=LEFT;
            }
        }
    }
    cout<<C[n][n]<<"\n";
    short int seq[1010];
    int i=n,j=n,k=0;
    while(i>0&&j>0)
    {

        switch(S[i][j])
        {
            case DIAG:
                    seq[k++]=s1[i].pos;
                    i--;j--;
                    break;
            case UP :
                    i--;
                    break;
            case LEFT :
                    j--;
        }
    }
   for(i=k-1;i>=0;i--)
       cout<<seq[i]<<"\n";
}


int main()
{
    freopen("temp.txt","r",stdin);
    E[0].pos=0;
    E[0].weight=-1;
    E[0].iq=INT_MAX;
    while(cin>>E[n].weight)
    {
        cin>>E[n].iq;
        E[n].pos=n;
        n++;
    }
    for(int i=0;i<n;i++)
    {
        sortIQ[i]=E[i];
        sortW[i]=E[i];
    }
    qsort(sortW,n,sizeof(elephant),compW);
    qsort(sortIQ,n,sizeof(elephant),compIQ);
    n--;
    LCS(sortW,sortIQ);
    return 0;
}
