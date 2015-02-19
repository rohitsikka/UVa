#include<iostream>
#include<cstdio>
using namespace std;
int coins[5]={1,5,10,25,50};
long int C[8000];//initialises global arays to 0 automatically

void build()
{
    C[0]=1;
    for(int i=0;i<5;i++)
        for(int j=coins[i];j<8000;j++)
            C[j]+=C[j-coins[i]];
}

int main()
{
    freopen("temp.txt","r",stdin);
    int n;
    build();
    while(cin>>n)
    {
        cout<<C[n]<<"\n";
    }
    return 0;
}
