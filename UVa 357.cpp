#include<iostream>
#include<cstdio>
using namespace std;
int coins[5]={1,5,10,25,50};
long long int C[30010];//initialises global arays to 0 automatically

void build()
{
    C[0]=1;
    for(int i=0;i<5;i++)
        for(int j=coins[i];j<30010;j++)
            C[j]+=C[j-coins[i]];
}

int main()
{
    freopen("temp.txt","r",stdin);
    int n;
    build();
    while(cin>>n)
    {
        if(C[n]!=1)
            cout<<"There are "<<C[n]<<" ways to produce "<<n<<" cents change.\n";
        else
            cout<<"There is only "<<C[n]<<" way to produce "<<n<<" cents change.\n";
    }
    return 0;
}
