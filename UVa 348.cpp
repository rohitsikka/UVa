#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>

#define INF 100000000

using namespace std;

int N;
int D[15];
int C[12][12];
int Construct[12][12];

void print(int i,int j)
{

    if(i==j&&i<=N)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        print(i,Construct[i][j]);
        cout<<" x ";
        print(Construct[i][j]+1,j);
        cout<<")";
    }
}
void Matrix()
{
    int j;
    for(int i=0;i<=N;i++)
    {
        C[i][i]=0;
        Construct[i][i]=i;
    }
    for(int l=2;l<=N;l++)
    {
        for(int i=1;i<=N-l+1;i++)
        {
            j=i+l-1;
            C[i][j]=INF;
            for(int k=i;k<j;k++)
                if(C[i][j] > C[i][k] + C[k+1][j] + D[i-1]*D[k]*D[j])
                {
                    C[i][j]=C[i][k] + C[k+1][j] + D[i-1]*D[k]*D[j];
                    Construct[i][j]=k;
                }
        }
    }
    print(1,N);
}
int main()
{
    freopen("temp.txt","r",stdin);
    int n=1;
    while(cin>>N&&N!=0)
    {
        for(int i=0;i<N;i++)
        {
            cin>>D[i];
            cin>>D[i+1];
        }
        cout<<"Case "<<n<<": ";
        Matrix();
        cout<<"\n";
        n++;

    }
    return 0;
}
