#include<iostream>
#include<cstdio>
#include<limits.h>
#include<cstdlib>
#include<string.h>
using namespace std;
int C[60][60],cuts[60];
/*int cuttingSticks(int i,int j)
{
    if(i+1==j)
            return 0;
    int temp;
    if(C[i][j]!=-1)
        return C[i][j];
    C[i][j]=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        temp=cuttingSticks(i,k)+cuttingSticks(k,j)+cuts[j]-cuts[i];
        if(temp<C[i][j])
            C[i][j]=temp;
    }
    return C[i][j];
}*/
int cuttingSticks(int n)
{

    for(int i=0;i<=n;i++)
    {
        C[i][i]=0;
        C[i][i+1]=0;
    }
    for(int nc=3;nc<=n+1;nc++)
    {
        for(int i=0;i<=n-nc+1;i++)
        {
            int j=i+nc-1;
            C[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                if(C[i][j]>C[i][k]+C[k][j]+ (cuts[j]-cuts[i]))
                    C[i][j]=C[i][k]+C[k][j]+ (cuts[j]-cuts[i]) ;
            }
        }
    }
    return C[0][n];
}

int main()
{
    freopen("temp.txt","r",stdin);
    int l=1,n;
    while(cin>>l)
    {
        if(l==0)    break;
        cin>>n;
        cuts[0]=0;
        for(int i=1;i<=n;i++)
            cin>>cuts[i];
        cuts[n+1]=l;
        memset(C,-1,sizeof(int)*60*60);

        cout<<"The minimum cutting is "<<cuttingSticks(n+1)<<"."<<"\n";
    }
    return 0;
}
